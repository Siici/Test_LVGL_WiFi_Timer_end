#ifndef _ui_task_h_
#define _ui_task_h_

#include "allhead.h"


// 创建UI进程
void lvgl_PinnedToCore(void);
// 任务回调函数 ---> ui进程 
void Guitask(void *param);  // 显示ui界面

/***********************************************************************/

/***********************************************************************/



#endif