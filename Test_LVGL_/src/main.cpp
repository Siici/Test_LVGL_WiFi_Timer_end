#include "allhead.h"
#include "tem_hum.h"



void setup()
{
	lvgl_PinnedToCore();	  // UI 进程
	temAndhum_PinnedToCore(); // 创建温湿度进程
}

void loop()
{
}
