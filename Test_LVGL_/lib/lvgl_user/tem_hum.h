#pragma once
#include "allhead.h"
#include "DHT20.h"
#include <WiFi.h>
#include "PubSubClient.h"


// 初始温湿度传感器
void dht20_init();
// 任务回调函数 ---> 温湿度进程
void Tem_Hum_task(void *param);
// 创建温湿度进程
void temAndhum_PinnedToCore(void);


//连接wifi
void wifiInit();

// mqtt连接
void mqttCheckConnect();

//上传温湿度、二氧化碳浓度
void mqttIntervalPost();

