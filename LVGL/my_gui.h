
#ifndef _MY_GUI_H
#define _MY_GUI_H

/*LVGL相关头文件*/
#include "lv_conf.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"

/*外部相关头文件*/
#include "led.h"

void My_Gui(void);
void my_lvgl_init(void);
void LED1_mcu(bool state);
void LED2_mcu(bool state);

#endif // _MY_GUI_H
