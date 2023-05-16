#include "my_gui.h"
#include "lvgl.h"
#include <stdio.h>


#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t* font = &lv_font_montserrat_20;       /* 定义字体 */

/*************** 图片声明 ********************/
LV_IMG_DECLARE(bg_color);       //page2背景图片
LV_IMG_DECLARE(switch_img);         //

LV_FONT_DECLARE(Font30);                        /* 声明字体 */
LV_FONT_DECLARE(Font24_Normal);         /* 声明字体 */
LV_FONT_DECLARE(Font18_Normal);         /* 声明字体 */
LV_FONT_DECLARE(Font20);                        /* 声明字体 */


/*************** 外部变量声明 ********************/
extern uint8_t DHT11_temp_int;
extern uint8_t DHT11_temp_flot;
extern uint8_t DHT11_humi_int;
extern uint16_t SHT30_temp;
extern uint16_t SHT30_humi;
extern uint32_t CO2Data;
extern uint32_t TVOCData;

/*************** 变量声明 ********************/

static lv_obj_t *PageView;          /* 全局平铺视图 */
static lv_obj_t *Page1;             /* 页面1 左 */
static lv_obj_t *Page2;             /* 页面2 中 */
static lv_obj_t *Page3;             /* 页面3 右 */

static lv_obj_t* lv_LED1;
static lv_obj_t* title1;
static lv_obj_t* slider1;
static lv_obj_t* switch1;

static lv_obj_t* lv_LED2;
static lv_obj_t* title2;
static lv_obj_t* slider2;
static lv_obj_t* switch2;

static lv_obj_t* lv_LED3;
static lv_obj_t* slider3;
static lv_obj_t* switch3;

static _Bool Switch1State = 0;
static _Bool Switch2State = 0;
static _Bool Switch3State = 0;

static lv_obj_t * Temp_Lable;
static lv_obj_t * Humi_Lable;
static lv_obj_t * TVOC_Lable;
static lv_obj_t * CO2_Lable;

static int32_t value1;

/*************** 函数声明 ********************/
static void StateBar_Set(void);             /* 状态栏函数 */
static void Page2_Card1Set( lv_obj_t *card );
static void Page2_Card2Set( lv_obj_t *card );
static void Page2_Card3Set( lv_obj_t *card );
void my_timer(lv_timer_t * timer);

static void CardTable_Set(lv_obj_t* CardTable,lv_obj_t* LED, lv_obj_t* slider,lv_obj_t* switch_t);


/**
 * @brief  灯开关回调函数
 * @param  *e ：事件相关参数的集合，它包含了该事件的所有数据
 * @return 无
 */
static void CardTable1_switch_event_cb(lv_event_t * e)
{
    Switch1State = !Switch1State;
    lv_obj_t *target = lv_event_get_current_target(e);      /* 获取触发源 */
    lv_obj_t *TargetOBJ;
    printf("run callback1  fun\r\n");
    if(Switch1State == 1)
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        lv_led_on(lv_LED1);
        TIM_SetCompare1(TIM9,255);
        lv_slider_set_value(slider1,255,LV_ANIM_ON);
    }
    else
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x000000),LV_STATE_DEFAULT);
        lv_led_off(lv_LED1);
        TIM_SetCompare1(TIM9,0);
        lv_slider_set_value(slider1,0,LV_ANIM_ON);
    }

    //lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(target,200,LV_STATE_DEFAULT);
    //LED1_TOGGLE();
}
static void CardTable2_switch_event_cb(lv_event_t * e)
{
    Switch2State = !Switch2State;
    lv_obj_t *target = lv_event_get_current_target(e);      /* 获取触发源 */
    lv_obj_t *TargetOBJ;
    printf("run callback2  fun\r\n");
    if(Switch2State == 1)
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        lv_led_on(lv_LED2);
        LED1 = 0;                   //低电平亮
    }
    else
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x000000),LV_STATE_DEFAULT);
        lv_led_off(lv_LED2);
        LED1 = 1;
    }

    //lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(target,200,LV_STATE_DEFAULT);
    //lv_obj_set_style_img_recolor(switch1,lv_color_hex(0x000000),LV_STATE_DEFAULT);
    //LED1_TOGGLE();
}
static void CardTable3_switch_event_cb(lv_event_t * e)
{
    Switch3State = !Switch3State;
    lv_obj_t *target = lv_event_get_current_target(e);      /* 获取触发源 */
    lv_obj_t *TargetOBJ;
    printf("run callback3  fun\r\n");
    if(Switch3State == 1)   //打开
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        lv_led_on(lv_LED3);

    }
    else
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x000000),LV_STATE_DEFAULT);
        lv_led_off(lv_LED3);
    }

    //lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(target,200,LV_STATE_DEFAULT);
    //lv_obj_set_style_img_recolor(switch1,lv_color_hex(0x000000),LV_STATE_DEFAULT);
    //LED1_TOGGLE();
}


/**
 * @brief  灯滑动条回调函数
 * @param  *e ：事件相关参数的集合，它包含了该事件的所有数据
 * @return 无
 */
static void CardTable1_slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* 获取触发源 */
    lv_event_code_t code = lv_event_get_code(e); /* 获取事件类型 */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        value1 = lv_slider_get_value(target);
        //printf("%d\r\n",value1);
        lv_led_set_brightness(lv_LED1, value1);
        TIM_SetCompare1(TIM9,value1);
        if(value1) lv_obj_set_style_img_recolor(switch1,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        else lv_obj_set_style_img_recolor(switch1,lv_color_hex(0x000000),LV_STATE_DEFAULT);

    }

}
static void CardTable2_slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* 获取触发源 */
    lv_event_code_t code = lv_event_get_code(e); /* 获取事件类型 */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        //printf("%d\r\n",lv_slider_get_value(target));
    }

}
static void CardTable3_slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* 获取触发源 */
    lv_event_code_t code = lv_event_get_code(e); /* 获取事件类型 */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        //printf("%d\r\n",lv_slider_get_value(target));
    }

}



/**
 * @brief  页面创建函数
 * @param
 * @return
 */
static void Page_Creat(void)
{

    PageView = lv_tileview_create(lv_scr_act());  //创建平铺视图
    Page1 = lv_tileview_add_tile( PageView, 0, 0,LV_DIR_RIGHT );//最左面的
    Page2 = lv_tileview_add_tile( PageView, 1, 0,LV_DIR_HOR );//中间的
    //Page3 = lv_tileview_add_tile( PageView, 2, 0,LV_DIR_LEFT );//最右面的


    StateBar_Set();
    lv_obj_update_layout( PageView ); /* 更新参数 */
    lv_obj_set_tile( PageView, Page2, LV_ANIM_ON ); //设置页面2为当前页面

    lv_obj_t *img = lv_img_create(Page2);
    lv_img_set_src(img, &bg_color);

    //lv_obj_set_style_bg_color(PageView, lv_color_hex(0x354e6b),LV_STATE_DEFAULT); /* 设置部件的*/
    lv_obj_remove_style(PageView, NULL, LV_PART_SCROLLBAR);  /* 移除滚动条 */
}

/**
 * @brief  页面1内容设置
 * @param
 * @return
 */
static void Page1_Set(void)
{
    lv_obj_t *label_1 = lv_label_create(Page1);                    /* 创建标签 */
    lv_label_set_text(label_1, "Page_1");                           /* 设置文本内容 */
    lv_obj_set_style_text_font(label_1, font, LV_STATE_DEFAULT);    /* 设置字体 */
    lv_obj_center(label_1);                                         /* 设置位置 */
}

/**
 * @brief  页面2内容设置
 * @param
 * @return
 */
static void Page2_Set(void)
{
//    lv_obj_t *label_1 = lv_label_create(Page2);                    /* 创建标签 */
//    lv_label_set_text(label_1, "Page_2");                           /* 设置文本内容 */
//    lv_obj_set_style_text_font(label_1, font, LV_STATE_DEFAULT);    /* 设置字体 */
//    lv_obj_center(label_1);                                         /* 设置位置 */

    /************** 创建三个card ****************/
    lv_obj_t *card1 = lv_obj_create(Page2);
    lv_obj_t *card2 = lv_obj_create(Page2);
    lv_obj_t *card3 = lv_obj_create(Page2);

    /************** 设置三个card ****************/
    Page2_Card1Set(card1);
    Page2_Card2Set(card2);
    Page2_Card3Set(card3);

}

/**
 * @brief  页面3内容设置
 * @param
 * @return
 */
static void Page3_Set(void)
{
    // lv_obj_t *label_1 = lv_label_create(Page3);                    /* 创建标签 */
    // lv_label_set_text(label_1, "Page_3");                           /* 设置文本内容 */
    // lv_obj_set_style_text_font(label_1, font, LV_STATE_DEFAULT);    /* 设置字体 */
    // lv_obj_center(label_1);                                         /* 设置位置 */
}

/**
 * @brief  状态栏设置函数
 * @param
 * @return
 */
static void StateBar_Set(void)
{

    /* 左侧状态栏 */
    lv_obj_t *label_left = lv_label_create(lv_scr_act());                                   /* 创建标签 */
    lv_label_set_text(label_left, "AM 8:30" );                                              /* 设置文本内容 */
    lv_obj_set_style_text_font(label_left, font, LV_STATE_DEFAULT);                         /* 设置字体 */
    lv_obj_align(label_left, LV_ALIGN_TOP_LEFT, 10, 10);                                    /* 设置位置 */

    /* 右侧状态栏 */
    lv_obj_t *label_right = lv_label_create(lv_scr_act());                                  /* 创建标签 */
    lv_label_set_text(label_right, LV_SYMBOL_WIFI "   80% " LV_SYMBOL_BATTERY_3);           /* 设置文本内容 */
    lv_obj_set_style_text_font(label_right, font, LV_STATE_DEFAULT);                        /* 设置字体 */
    lv_obj_align(label_right, LV_ALIGN_TOP_RIGHT, -10, 10);                                 /* 设置位置 */
}

/**
 * @brief
 * @param  card对象
 * @return
 */
static void Page2_Card1Set(lv_obj_t *card)
{
    /*************** card属性 ****************/
    lv_obj_align(card,LV_ALIGN_LEFT_MID,40,0);  //位置
    lv_obj_set_size(card,340,350);  //大小
    //lv_obj_set_style_bg_color(card,);
    lv_obj_set_style_bg_opa(card,140,LV_STATE_DEFAULT); //透明度
    lv_obj_remove_style(card, NULL, LV_PART_SCROLLBAR);  /* 移除滚动条 */

    /*************** 创建三个obj ****************/
    lv_obj_t* CardTable1 = lv_obj_create(card);
    lv_obj_t* CardTable2 = lv_obj_create(card);
    lv_obj_t* CardTable3 = lv_obj_create(card);

    /************* 调整三个obj的属性 *************/
    lv_obj_align(CardTable1,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(CardTable1,300,100);

    lv_obj_align_to(CardTable2,CardTable1,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
    lv_obj_set_size(CardTable2,300,100);

    lv_obj_align_to(CardTable3,CardTable2,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
    lv_obj_set_size(CardTable3,300,100);

    /************* 设置对应的开关 *************/
    lv_LED1 = lv_led_create(CardTable1);
    title1 = lv_label_create(CardTable1);
    slider1 = lv_slider_create(CardTable1);
    switch1 = lv_imgbtn_create(CardTable1);

    lv_LED2 = lv_led_create(CardTable2);
    title2 = lv_label_create(CardTable2);
    slider2 = lv_slider_create(CardTable2);
    switch2 = lv_imgbtn_create(CardTable2);

    lv_LED3 = lv_led_create(CardTable3);
    slider3 = lv_slider_create(CardTable3);
    switch3 = lv_imgbtn_create(CardTable3);

    lv_obj_set_style_text_font(title1,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(title1,"bedroom");
    lv_obj_align_to(title1,CardTable1,LV_ALIGN_TOP_MID,0,-2);

    lv_obj_set_style_text_font(title2,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(title2,"living room");
    lv_obj_align_to(title2,CardTable2,LV_ALIGN_TOP_MID,0,-2);

    CardTable_Set(CardTable1,lv_LED1,slider1,switch1);
    CardTable_Set(CardTable2,lv_LED2,slider2,switch2);
    CardTable_Set(CardTable3,lv_LED3,slider3,switch3);

    /************* 设置开关回调函数 *************/
    lv_obj_add_event_cb(switch1,CardTable1_switch_event_cb,LV_EVENT_RELEASED,NULL);
    lv_obj_add_event_cb(switch2,CardTable2_switch_event_cb,LV_EVENT_RELEASED,NULL);
    lv_obj_add_event_cb(switch3,CardTable3_switch_event_cb,LV_EVENT_RELEASED,NULL);

    /************* 设置滑动条回调函数 *************/
    lv_obj_add_event_cb(slider1,CardTable1_slider_event_cb,LV_EVENT_VALUE_CHANGED,NULL);
    lv_obj_add_event_cb(slider2,CardTable2_slider_event_cb,LV_EVENT_VALUE_CHANGED,NULL);
    lv_obj_add_event_cb(slider3,CardTable3_slider_event_cb,LV_EVENT_VALUE_CHANGED,NULL);




}
static void Page2_Card3Set( lv_obj_t *card )
{
    //lv_obj_align_to(FatherCard,card,LV_ALIGN_RIGHT_MID,40,0);
    lv_obj_align(card,LV_ALIGN_RIGHT_MID,-40,0);  //左边中间偏移40
    lv_obj_set_size(card,150,350);
    lv_obj_set_style_bg_opa(card,140,LV_STATE_DEFAULT);


    /*******************  标题  ***********************/
    lv_obj_t *TVOC_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(TVOC_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(TVOC_Title_Label,"TVOC:");
    lv_obj_align(TVOC_Title_Label,LV_ALIGN_TOP_LEFT,0,20);

    lv_obj_t *CO2_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(CO2_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(CO2_Title_Label,"CO2:");
    lv_obj_align(CO2_Title_Label,LV_ALIGN_LEFT_MID,0,25);

    /*******************  值  ***********************/
    TVOC_Lable = lv_label_create(card);
    lv_obj_set_style_text_font(TVOC_Lable,&Font30,LV_STATE_DEFAULT);
    lv_label_set_text_fmt(TVOC_Lable,"%d",TVOCData);
    //lv_label_set_text(Temp_Lable,DHT11_temp);
    lv_obj_align(TVOC_Lable,LV_ALIGN_CENTER,-10,-40);

    CO2_Lable = lv_label_create(card);
    lv_obj_set_style_text_font(CO2_Lable,&Font30,LV_STATE_DEFAULT);
    lv_label_set_text_fmt(CO2_Lable,"%d",CO2Data);
    //lv_label_set_text(Humi_Lable,DHT11_humi);
    lv_obj_align(CO2_Lable,LV_ALIGN_BOTTOM_MID,-10,-40);

    /*******************  单位符号  ***********************/
    lv_obj_t * TVOC_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(TVOC_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(TVOC_Signal,"ppm");
    lv_obj_align_to(TVOC_Signal,TVOC_Lable,LV_ALIGN_OUT_RIGHT_MID,7,0);

    lv_obj_t * CO2_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(CO2_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(CO2_Signal,"ppm");
    lv_obj_align_to(CO2_Signal,CO2_Lable,LV_ALIGN_OUT_RIGHT_MID,7,0);

    lv_obj_remove_style(card, NULL, LV_PART_SCROLLBAR);  /* 移除滚动条 */
}
static void Page2_Card2Set( lv_obj_t *card )
{
    lv_obj_align(card,LV_ALIGN_RIGHT_MID,-230,0);
    lv_obj_set_size(card,150,350);
    lv_obj_set_style_bg_opa(card,140,LV_STATE_DEFAULT);

    /*******************  温湿度标题  ***********************/
    lv_obj_t *Temp_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(Temp_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Temp_Title_Label,"娓╁害:");
    lv_obj_align(Temp_Title_Label,LV_ALIGN_TOP_LEFT,0,20);

    lv_obj_t *Humi_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(Humi_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Humi_Title_Label,"婀垮害:");
    lv_obj_align(Humi_Title_Label,LV_ALIGN_LEFT_MID,0,25);

    /*******************  温湿度值  ***********************/
    Temp_Lable = lv_label_create(card);
    lv_obj_set_style_text_font(Temp_Lable,&Font30,LV_STATE_DEFAULT);
    lv_label_set_text_fmt(Temp_Lable,"%d.%d",DHT11_temp_int,DHT11_temp_flot);
    //lv_label_set_text(Temp_Lable,DHT11_temp);
    lv_obj_align(Temp_Lable,LV_ALIGN_CENTER,-10,-40);

    Humi_Lable = lv_label_create(card);
    lv_obj_set_style_text_font(Humi_Lable,&Font30,LV_STATE_DEFAULT);
    lv_label_set_text_fmt(Humi_Lable,"%d",DHT11_humi_int);
    //lv_label_set_text(Humi_Lable,DHT11_humi);
    lv_obj_align(Humi_Lable,LV_ALIGN_BOTTOM_MID,-10,-40);

    /*******************  温湿度单位符号  ***********************/
    lv_obj_t * Temp_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(Temp_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Temp_Signal,"C");
    lv_obj_align_to(Temp_Signal,Temp_Lable,LV_ALIGN_OUT_RIGHT_MID,9,9);

    lv_obj_t * Humi_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(Humi_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Humi_Signal,"%");
    lv_obj_align_to(Humi_Signal,Humi_Lable,LV_ALIGN_OUT_RIGHT_MID,7,4);
}

/**
 * @brief
 * @param  @CardTable;@LED;@slider;@switch_t;
 * @return
 */
static void CardTable_Set(lv_obj_t* CardTable,lv_obj_t* LED, lv_obj_t* slider,lv_obj_t* switch_t)
{
    lv_led_set_color(LED,lv_color_hex(0xfedc5e));  //设置颜色
    lv_obj_align(LED,LV_ALIGN_LEFT_MID,0,0);       //设置位置
    lv_led_off(LED);


    lv_obj_set_size(slider,150, 10);
    lv_obj_align_to(slider,LED,LV_ALIGN_LEFT_MID,50,0);
    lv_slider_set_range(slider,0,255);              //设置滑杆范围

    lv_imgbtn_set_src(switch_t,LV_IMGBTN_STATE_RELEASED,NULL,&switch_img,NULL);
    lv_obj_set_size(switch_t,32,32);

    lv_obj_align(switch_t,LV_ALIGN_RIGHT_MID,0,0);
    lv_obj_set_style_img_recolor_opa(switch_t,200,LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(switch_t,lv_color_hex(0x000000),LV_STATE_DEFAULT);
    //lv_obj_add_event_cb(switch_t,CardTable_event_cb,LV_EVENT_RELEASED,NULL);
}

void My_Gui(void)
{
    Page_Creat();
    Page1_Set();
    Page2_Set();
    Page3_Set();

    lv_timer_t * timer = lv_timer_create(my_timer,500,NULL);
}

void my_lvgl_init(void)
{
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	
}

void my_timer(lv_timer_t * timer)
{
    // lv_label_set_text_fmt(Temp_Lable,"%d.%d",DHT11_temp_int,DHT11_temp_flot);
    // lv_label_set_text_fmt(Humi_Lable,"%d",DHT11_humi_int);

    lv_label_set_text_fmt(Temp_Lable,"%d.%d",SHT30_temp/10,SHT30_temp%10);
    lv_label_set_text_fmt(Humi_Lable,"%d",SHT30_humi);

    lv_label_set_text_fmt(TVOC_Lable,"%d",TVOCData);
    lv_label_set_text_fmt(CO2_Lable,"%d",CO2Data);
}