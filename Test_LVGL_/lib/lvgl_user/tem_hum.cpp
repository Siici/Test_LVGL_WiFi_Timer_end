#include "tem_hum.h"

#define NTP "ntp.aliyun.com"

// 创建对象
DHT20 DHT;          // 温湿度
Adafruit_SGP30 sgp; // 二氧化碳 TVOC
unsigned long lastMs = 0;
float tep;
float hum;

float TVOC;
float CO2;

/* 连接WIFI SSID和密码 */
#define WIFI_SSID "Come on Baby"
#define WIFI_PASSWD "12345678"

/* 设备的三元组信息*/
#define PRODUCT_KEY "a1ja2NU3asy"
#define DEVICE_NAME "testV1"
#define DEVICE_SECRET "ccb4e9d2795aea6d197343c48a222b78"
#define REGION_ID "cn-shanghai"

/* 线上环境域名和端口号，不需要改 */
#define MQTT_SERVER PRODUCT_KEY ".iot-as-mqtt." REGION_ID ".aliyuncs.com"
#define MQTT_PORT 1883
#define MQTT_USRNAME DEVICE_NAME "&" PRODUCT_KEY

// 修改用户id 和 MQTT密码
#define CLIENT_ID "a1ja2NU3asy.testV1|securemode=2,signmethod=hmacsha256,timestamp=1706622122594|"
#define MQTT_PASSWD "f34a483dc2845856494551f912cf1afd89f69efe1de13af582603c56dec76e01"

// 宏定义订阅主题                   // 修改产品名
#define ALINK_BODY_FORMAT "{\"id\":\"testV1\",\"version\":\"1.0\",\"method\":\"thing.event.property.post\",\"params\":%s}"
#define ALINK_TOPIC_PROP_POST "/sys/" PRODUCT_KEY "/" DEVICE_NAME "/thing/event/property/post"

WiFiClient espClient;
PubSubClient client(espClient);

// 连接wifi
void wifiInit()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("WiFi not Connect");
    }
}

// 检查 mqtt连接 若没连接则连接
void mqttCheckConnect()
{
    while (!client.connected())
    {
        Serial.println("Connecting to MQTT Server ...");
        if (client.connect(CLIENT_ID, MQTT_USRNAME, MQTT_PASSWD))
        {
            Serial.println("MQTT Connected!");
        }
        else
        {
            Serial.print("MQTT Connect err:");
            Serial.println(client.state());
            delay(5000);
        }
    }
}

// 上传温湿度、二氧化碳浓度
void mqttIntervalPost()
{
    char param[32];
    char jsonBuf[128];

    // upload humidity
    hum = DHT.getHumidity(); // 获取湿度
    sprintf(param, "{\"humidity\":%2f}", hum);
    sprintf(jsonBuf, ALINK_BODY_FORMAT, param);
    Serial.println(jsonBuf);
    boolean b = client.publish(ALINK_TOPIC_PROP_POST, jsonBuf);     // 使用client发布一个消息到ALINK_TOPIC_PROP_POST主题，消息内容为jsonBuf，并将返回值存储在变量b中
    if (b)
    {
        Serial.println("publish Humidity success");
    }
    else
    {
        Serial.println("publish Humidity fail");
    }

    // Upload temperature
    tep = DHT.getTemperature(); // 获取温度
    sprintf(param, "{\"temperature\":%2f}", tep);
    sprintf(jsonBuf, ALINK_BODY_FORMAT, param);
    Serial.println(jsonBuf);
    boolean c = client.publish(ALINK_TOPIC_PROP_POST, jsonBuf);
    if (c)
    {
        Serial.println("publish Temperature success");
    }
    else
    {
        Serial.println("publish Temperature fail");
    }

    // Upload TVOC
    TVOC = sgp.TVOC; //    TVOC
    sprintf(param, "{\"TVOC\":%2f}", TVOC);
    sprintf(jsonBuf, ALINK_BODY_FORMAT, param);
    Serial.println(jsonBuf);
    boolean d = client.publish(ALINK_TOPIC_PROP_POST, jsonBuf);
    if (b)
    {
        Serial.println("publish Humidity success");
    }
    else
    {
        Serial.println("publish Humidity fail");
    }

    // Upload CO2
    CO2 = sgp.eCO2; // 获取CO2
    sprintf(param, "{\"CO2\":%2f}", CO2);
    sprintf(jsonBuf, ALINK_BODY_FORMAT, param);
    Serial.println(jsonBuf);
    boolean e = client.publish(ALINK_TOPIC_PROP_POST, jsonBuf);
    if (c)
    {
        Serial.println("publish Temperature success");
    }
    else
    {
        Serial.println("publish Temperature fail");
    }
}

// 初始温湿度传感器
void dht20_init()
{
    Wire.begin(39, 40); // SDA 39 SCL 40
    DHT.begin();
    delay(1000);
}

void SGP30_init()
{
    Wire1.begin(13, 14); // SDA SCL
    if (!sgp.begin(&Wire1))
    {
        Serial.println("Sensor not found ");
        while (1)
            ;
    }
}

void time_init()
{
    struct tm timeinfo; // 定义时间信息
    // 如果获取失败，就开启联网模式，获取时间
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("获取时间失败");
        // 开启网络
        //  wifi_init();
        //  从网络时间服务器上获取并设置时间
        configTime(8 * 3600, 0, NTP); // 时区，夏令时，NTP地址
        return;
    }
    // 格式化输出:2021-10-24 23:00:44 Sunday
    // Serial.println(&timeinfo, "%F %T %A");
    Serial.println(timeinfo.tm_sec);
    // WiFi.disconnect(true); //在不需要开启网络的情况下，可以主动断开网络连接。

    char Hour[10];
    char Min[10];
    char Sec[10];

    sprintf(Hour, "%d", timeinfo.tm_hour);
    sprintf(Min, "%d", timeinfo.tm_min);
    sprintf(Sec, "%d", timeinfo.tm_sec);

    lv_label_set_text(ui_hour, Hour); // 十
    lv_label_set_text(ui_min, Min);   // 分
    lv_label_set_text(ui_sec, Sec);   // 秒
}

// 创建温湿度进程
void temAndhum_PinnedToCore(void)
{
    xTaskCreatePinnedToCore(
        Tem_Hum_task, /* 任务回调函数的指针 */
        "tem_hum",    /* 任务名 最多16字节 */
        2 * 4096,     /* 任务栈大小，根据需要自行设置*/
        NULL,         /* 创建任务的参数，会传给任务函数的形参 传递入参时,需传递该变量的地址并强转为void *型，否则无法传递，编译报错 */
        3,            /* 任务优先级 (0~24) 数字越大优先级越高*/
        NULL,         /* 任务句柄 */
        1);           /* CPU1 */
}

// 任务回调函数 ---> 温湿度进程
void Tem_Hum_task(void *param)
{
    Serial.begin(115200);
    wifiInit();
    dht20_init();                 // 初始温湿度传感器
    SGP30_init();                 // 初始SGP30
    configTime(8 * 3600, 0, NTP); // 时区，夏令时，NTP地址

    vTaskDelay(500);
    client.setServer(MQTT_SERVER, MQTT_PORT); /* 连接MQTT服务器 */
    client.connect(CLIENT_ID, MQTT_USRNAME, MQTT_PASSWD);

    while (1)
    {
        time_init();

        // 从传感器读取温湿度数据 并返回状态
        int status = DHT.read(); // 不能注释掉
        // 刷新SGP30
        if (!sgp.IAQmeasure())
        {
            Serial.println("Measurement failed");
            return;
        }

        // 每2s 读取一次数据
        if (millis() - lastMs >= 2000)
        {
            lastMs = millis();

            tep = DHT.getTemperature(); // 获取温度
            hum = DHT.getHumidity();    // 获取湿度

            char Temp[10];
            char Hum[10];
            sprintf(Temp, "%0.1f C", tep);
            sprintf(Hum, "%0.1f C", hum);

            lv_label_set_text(ui_Label1, "");   // 清空文本输入框
            lv_label_set_text(ui_Label1, Hum);  // 输入湿度数据
            lv_label_set_text(ui_Label2, "");   // 清空文本输入框
            lv_label_set_text(ui_Label2, Temp); // 输入温度数据

            TVOC = sgp.TVOC; //    TVOC
            CO2 = sgp.eCO2;  // 获取CO2
            char Tvoc[10];
            char Co2[10];
            sprintf(Tvoc, "%0.1f C", TVOC);
            sprintf(Co2, "%0.1f C", CO2);

            lv_label_set_text(ui_Label3, "");   // 清空文本输入框
            lv_label_set_text(ui_Label3, Tvoc); // 输入湿度数据
            lv_label_set_text(ui_Label4, "");   // 清空文本输入框
            lv_label_set_text(ui_Label4, Co2);  // 输入温度数据

            mqttCheckConnect(); // 检查MQTT 是否连接成功

            mqttIntervalPost(); // 上报阿里云
        }
        client.loop();
        // vTaskDelay(2000);
    }
}
