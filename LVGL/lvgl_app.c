#include "lvgl_app.h"
#include "led.h"

void my_lvgl_init(void)
{
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	
}


void my_lvgl_test(void)
{
	char* github_addr = "https://gitee.com/W23";
	lv_obj_t * label = lv_label_create(lv_scr_act());
	lv_label_set_recolor(label, true);
	lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
	lv_obj_set_width(label, 120);
	lv_label_set_text_fmt(label, "#ff0000 Gitee: %s#", github_addr);
	lv_obj_align(label, LV_ALIGN_CENTER, 0, 10);

	lv_obj_t * label2 = lv_label_create(lv_scr_act());
	lv_label_set_recolor(label2, true);
	lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
	lv_obj_set_width(label2, 120);
	lv_label_set_text_fmt(label2, "#ff0000 Hello# #0000ff world !123456789#");
	lv_obj_align(label2, LV_ALIGN_CENTER, 0, -10);
}


void my_lvgl_test_2(void)
{
	lv_obj_t * obj		= lv_obj_create(lv_scr_act());
	lv_obj_t * label	= lv_label_create(obj);
	lv_obj_t * btn		= lv_btn_create(obj);

	lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
	lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 0);
	lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
	LED1 = 1;
	lv_label_set_text(label,"Hellow");

}


















