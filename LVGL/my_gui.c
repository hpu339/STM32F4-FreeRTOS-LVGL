/*
 * @description: 
 * @event: 
 * @param: 
 * @return: 
 */
#include "my_gui.h"
#include "lvgl.h"
#include "wifi.h"
#include <stdio.h>


// #if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
//     #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
// #endif

static const lv_font_t* font = &lv_font_montserrat_20;       /* �������� */

/*************** ͼƬ���� ********************/
LV_IMG_DECLARE(bg_color);       //page2����ͼƬ
LV_IMG_DECLARE(switch_img);         //
LV_IMG_DECLARE(hpu_log);

LV_FONT_DECLARE(Font30);                        /* �������� */
LV_FONT_DECLARE(Font24_Normal);         /* �������� */
LV_FONT_DECLARE(Font18_Normal);         /* �������� */


/*************** �ⲿ�������� ********************/

extern uint16_t SHT30_temp;
extern uint16_t SHT30_humi;
extern uint32_t CO2Data;
extern uint32_t TVOCData;
extern bool Switch1_State_bool;
extern bool Switch2_State_bool;

/*************** �������� ********************/

static lv_obj_t *PageView;          /* ȫ��ƽ����ͼ */
static lv_obj_t *Page1;             /* ҳ��1 �� */
static lv_obj_t *Page2;             /* ҳ��2 �� */
//static lv_obj_t *Page3;             /* ҳ��3 �� */

static lv_obj_t* lv_LED1;
static lv_obj_t* title1;
lv_obj_t* slider1;
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

static lv_obj_t *label_left;        //��������ߣ�������ʾʱ��

static int32_t value1;              //LED1�����Ȼص�����
static lv_obj_t *Init_bar;          //������
static lv_obj_t * percent_label;    //��������ǩ
static lv_obj_t *InitUI;            //��ʼ����������

/*************** �������� ********************/
static void StateBar_Set(void);             /* ״̬������ */
static void Page_Creat(void);               /* ҳ�洴������ */
static void Page1_Set(void);                /* ҳ��1���ú��� */
static void Page2_Set(void);                /* ҳ��2���ú��� */
static void Page2_Card1Set( lv_obj_t *card );
static void Page2_Card2Set( lv_obj_t *card );
static void Page2_Card3Set( lv_obj_t *card );
void my_timer(lv_timer_t * timer);

static void CardTable_Set(lv_obj_t* CardTable,lv_obj_t* LED, lv_obj_t* slider,lv_obj_t* switch_t);

/************************************* Page2�ڲ������� ******************************************






*************************************************************************************************/

            /*************************�ƹ���غ���**********************************/


                                /****���ػص�����****/
/**
 * @brief  �ƿ��ػص�����
 * @param  *e ���¼���ز����ļ��ϣ��������˸��¼�����������
 * @return ��
 */
static void CardTable1_switch_event_cb(lv_event_t * e)
{
    Switch1State = !Switch1State;
    lv_obj_t *target = lv_event_get_current_target(e);      /* ��ȡ����Դ */

    printf("run callback1  fun\r\n");
    if(Switch1State == 1)
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        lv_led_on(lv_LED1);
        Switch1_State_bool = TRUE;
        mcu_dp_value_update(DPID_LED_1,255);
        TIM_SetCompare1(TIM9,255);
        lv_slider_set_value(slider1,255,LV_ANIM_ON);
    }
    else
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x000000),LV_STATE_DEFAULT);
        lv_led_off(lv_LED1);
        Switch1_State_bool = FALSE;
        mcu_dp_value_update(DPID_LED_1,0);
        TIM_SetCompare1(TIM9,0);
        lv_slider_set_value(slider1,0,LV_ANIM_ON);
    }

    //lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(target,200,LV_STATE_DEFAULT);
    mcu_dp_bool_update(DPID_SWITCH1,Switch1_State_bool);        //�ϴ�����1��״̬
    //LED1_TOGGLE();
}
static void CardTable2_switch_event_cb(lv_event_t * e)
{
    Switch2State = !Switch2State;
    lv_obj_t *target = lv_event_get_current_target(e);      /* ��ȡ����Դ */

    printf("run callback2  fun\r\n");
    if(Switch2State == 1)
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        lv_led_on(lv_LED2);
        Switch2_State_bool = TRUE;
        LED1 = 0;                   //�͵�ƽ��
    }
    else
    {
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x000000),LV_STATE_DEFAULT);
        lv_led_off(lv_LED2);
        Switch2_State_bool = FALSE;
        LED1 = 1;
    }

    //lv_obj_set_style_img_recolor(target,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(target,200,LV_STATE_DEFAULT);
    mcu_dp_bool_update(DPID_SWITCH2,Switch2_State_bool);
    //lv_obj_set_style_img_recolor(switch1,lv_color_hex(0x000000),LV_STATE_DEFAULT);
    //LED1_TOGGLE();
}
static void CardTable3_switch_event_cb(lv_event_t * e)
{
    Switch3State = !Switch3State;
    lv_obj_t *target = lv_event_get_current_target(e);      /* ��ȡ����Դ */

    printf("run callback3  fun\r\n");
    if(Switch3State == 1)   //��
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

                                /***�������ص�����***/
/**
 * @brief  �ƻ������ص�����
 * @param  *e ���¼���ز����ļ��ϣ��������˸��¼�����������
 * @return ��
 */
static void CardTable1_slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* ��ȡ����Դ */
    lv_event_code_t code = lv_event_get_code(e); /* ��ȡ�¼����� */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        value1 = lv_slider_get_value(target);
        //printf("%d\r\n",value1);
        lv_led_set_brightness(lv_LED1, value1);
        mcu_dp_value_update(DPID_LED_1,value1);
        TIM_SetCompare1(TIM9,value1);
        if(value1) lv_obj_set_style_img_recolor(switch1,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        else lv_obj_set_style_img_recolor(switch1,lv_color_hex(0x000000),LV_STATE_DEFAULT);

    }

}
static void CardTable2_slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* ��ȡ����Դ */
    lv_event_code_t code = lv_event_get_code(e); /* ��ȡ�¼����� */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        //printf("%d\r\n",lv_slider_get_value(target));
    }

}
static void CardTable3_slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e); /* ��ȡ����Դ */
    lv_event_code_t code = lv_event_get_code(e); /* ��ȡ�¼����� */
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        //printf("%d\r\n",lv_slider_get_value(target));
    }

}

            /*************************page2 ����Ƭ����*******************************/
/**
 * @brief
 * @param  card����
 * @return
 */
static void Page2_Card1Set(lv_obj_t *card)
{
    /*************** card���� ****************/
    lv_obj_align(card,LV_ALIGN_LEFT_MID,40,0);  //λ��
    lv_obj_set_size(card,340,350);  //��С
    //lv_obj_set_style_bg_color(card,);
    lv_obj_set_style_bg_opa(card,140,LV_STATE_DEFAULT); //͸����
    lv_obj_remove_style(card, NULL, LV_PART_SCROLLBAR);  /* �Ƴ������� */

    /*************** ��������obj ****************/
    lv_obj_t* CardTable1 = lv_obj_create(card);
    lv_obj_t* CardTable2 = lv_obj_create(card);
    lv_obj_t* CardTable3 = lv_obj_create(card);

    /************* ��������obj������ *************/
    lv_obj_align(CardTable1,LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_size(CardTable1,300,100);

    lv_obj_align_to(CardTable2,CardTable1,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
    lv_obj_set_size(CardTable2,300,100);

    lv_obj_align_to(CardTable3,CardTable2,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
    lv_obj_set_size(CardTable3,300,100);

    /************* ���ö�Ӧ�Ŀ��� *************/
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

    /************* ���ÿ��ػص����� *************/
    lv_obj_add_event_cb(switch1,CardTable1_switch_event_cb,LV_EVENT_RELEASED,NULL);
    lv_obj_add_event_cb(switch2,CardTable2_switch_event_cb,LV_EVENT_RELEASED,NULL);
    lv_obj_add_event_cb(switch3,CardTable3_switch_event_cb,LV_EVENT_RELEASED,NULL);

    /************* ���û������ص����� *************/
    lv_obj_add_event_cb(slider1,CardTable1_slider_event_cb,LV_EVENT_VALUE_CHANGED,NULL);
    lv_obj_add_event_cb(slider2,CardTable2_slider_event_cb,LV_EVENT_VALUE_CHANGED,NULL);
    lv_obj_add_event_cb(slider3,CardTable3_slider_event_cb,LV_EVENT_VALUE_CHANGED,NULL);




}
static void Page2_Card3Set( lv_obj_t *card )
{
    //lv_obj_align_to(FatherCard,card,LV_ALIGN_RIGHT_MID,40,0);
    lv_obj_align(card,LV_ALIGN_RIGHT_MID,-40,0);  //����м�ƫ��40
    lv_obj_set_size(card,150,350);
    lv_obj_set_style_bg_opa(card,140,LV_STATE_DEFAULT);


    /*******************  ����  ***********************/
    lv_obj_t *TVOC_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(TVOC_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(TVOC_Title_Label,"TVOC:");
    lv_obj_align(TVOC_Title_Label,LV_ALIGN_TOP_LEFT,0,20);

    lv_obj_t *CO2_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(CO2_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(CO2_Title_Label,"CO2:");
    lv_obj_align(CO2_Title_Label,LV_ALIGN_LEFT_MID,0,25);

    /*******************  ֵ  ***********************/
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

    /*******************  ��λ����  ***********************/
    lv_obj_t * TVOC_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(TVOC_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(TVOC_Signal,"ppb");
    lv_obj_align_to(TVOC_Signal,TVOC_Lable,LV_ALIGN_OUT_RIGHT_MID,20,0);

    lv_obj_t * CO2_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(CO2_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(CO2_Signal,"ppm");
    lv_obj_align_to(CO2_Signal,CO2_Lable,LV_ALIGN_OUT_RIGHT_MID,7,0);

    lv_obj_remove_style(card, NULL, LV_PART_SCROLLBAR);  /* �Ƴ������� */
}
static void Page2_Card2Set( lv_obj_t *card )
{
    lv_obj_align(card,LV_ALIGN_RIGHT_MID,-230,0);
    lv_obj_set_size(card,150,350);
    lv_obj_set_style_bg_opa(card,140,LV_STATE_DEFAULT);

    /*******************  ��ʪ�ȱ���  ***********************/
    lv_obj_t *Temp_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(Temp_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Temp_Title_Label,"温度:");
    lv_obj_align(Temp_Title_Label,LV_ALIGN_TOP_LEFT,0,20);

    lv_obj_t *Humi_Title_Label = lv_label_create(card);
    lv_obj_set_style_text_font(Humi_Title_Label,&Font24_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Humi_Title_Label,"湿度:");
    lv_obj_align(Humi_Title_Label,LV_ALIGN_LEFT_MID,0,25);

    /*******************  ��ʪ��ֵ  ***********************/
    Temp_Lable = lv_label_create(card);
    lv_obj_set_style_text_font(Temp_Lable,&Font30,LV_STATE_DEFAULT);
    lv_label_set_text_fmt(Temp_Lable,"%d.%d",SHT30_temp/10,SHT30_temp%10);
    //lv_label_set_text(Temp_Lable,DHT11_temp);
    lv_obj_align(Temp_Lable,LV_ALIGN_CENTER,-10,-40);

    Humi_Lable = lv_label_create(card);
    lv_obj_set_style_text_font(Humi_Lable,&Font30,LV_STATE_DEFAULT);
    lv_label_set_text_fmt(Humi_Lable,"%d",SHT30_humi);
    //lv_label_set_text(Humi_Lable,DHT11_humi);
    lv_obj_align(Humi_Lable,LV_ALIGN_BOTTOM_MID,-10,-40);

    /*******************  ��ʪ�ȵ�λ����  ***********************/
    lv_obj_t * Temp_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(Temp_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Temp_Signal,"C");
    lv_obj_align_to(Temp_Signal,Temp_Lable,LV_ALIGN_OUT_RIGHT_MID,9,9);

    lv_obj_t * Humi_Signal = lv_label_create(card);
    lv_obj_set_style_text_font(Humi_Signal,&Font18_Normal,LV_STATE_DEFAULT);
    lv_label_set_text(Humi_Signal,"%");
    lv_obj_align_to(Humi_Signal,Humi_Lable,LV_ALIGN_OUT_RIGHT_MID,7,4);
}

            /*************************��Ƭ Table ����ģ�庯�� ************************/
/**
 * @brief   ��Ƭ1 Table ����ģ�庯��
 * @param  @CardTable;@LED;@slider;@switch_t;
 * @return
 */
static void CardTable_Set(lv_obj_t* CardTable,lv_obj_t* LED, lv_obj_t* slider,lv_obj_t* switch_t)
{
    lv_led_set_color(LED,lv_color_hex(0xfedc5e));  //������ɫ
    lv_obj_align(LED,LV_ALIGN_LEFT_MID,0,0);       //����λ��
    lv_led_off(LED);


    lv_obj_set_size(slider,150, 10);
    lv_obj_align_to(slider,LED,LV_ALIGN_LEFT_MID,50,0);
    lv_slider_set_range(slider,0,255);              //���û��˷�Χ

    lv_imgbtn_set_src(switch_t,LV_IMGBTN_STATE_RELEASED,NULL,&switch_img,NULL);
    lv_obj_set_size(switch_t,32,32);

    lv_obj_align(switch_t,LV_ALIGN_RIGHT_MID,0,0);
    lv_obj_set_style_img_recolor_opa(switch_t,200,LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(switch_t,lv_color_hex(0x000000),LV_STATE_DEFAULT);
    //lv_obj_add_event_cb(switch_t,CardTable_event_cb,LV_EVENT_RELEASED,NULL);
}

            /************************* MCU ���ú��� **********************************/
/**
 * @brief   LED1����״̬
 * @param  @SwitcState
 * @return
 */
void LED1_mcu(bool state)
{
    if(state)
    {
        lv_led_on(lv_LED1);
        lv_obj_set_style_img_recolor(switch1,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        TIM_SetCompare1(TIM9,255);
        lv_slider_set_value(slider1,255,LV_ANIM_ON);
    }
    else
    {
        lv_led_off(lv_LED1);
        lv_obj_set_style_img_recolor(switch1,lv_color_hex(0x000000),LV_STATE_DEFAULT);
        TIM_SetCompare1(TIM9,0);
        lv_slider_set_value(slider1,0,LV_ANIM_ON);
    }
}
/**
 * @brief   LED2����״̬
 * @param  @SwitcState
 * @return
 */
void LED2_mcu(bool state)
{
    if(state)
    {
        lv_led_on(lv_LED2);
        lv_obj_set_style_img_recolor(switch2,lv_color_hex(0xff0000),LV_STATE_DEFAULT);
        LED1 = 0;
    }
    else
    {
        lv_led_off(lv_LED2);
        lv_obj_set_style_img_recolor(switch2,lv_color_hex(0x000000),LV_STATE_DEFAULT);
        LED1 = 1;
    }
}


/************************************* ������������ ******************************************






*************************************************************************************************/


            /************************ �����洴������ *************************/
/**
 * @brief  ҳ�洴������
 * @param
 * @return
 */
static void Page_Creat(void)
{

    PageView = lv_tileview_create(lv_scr_act());  //����ƽ����ͼ
    Page1 = lv_tileview_add_tile( PageView, 0, 0,LV_DIR_RIGHT );//�������
    Page2 = lv_tileview_add_tile( PageView, 1, 0,LV_DIR_HOR );//�м��
    //Page3 = lv_tileview_add_tile( PageView, 2, 0,LV_DIR_LEFT );//�������


    StateBar_Set();
    lv_obj_update_layout( PageView ); /* ���²��� */
    lv_obj_set_tile( PageView, Page2, LV_ANIM_ON ); //����ҳ��2Ϊ��ǰҳ��

    lv_obj_t *img = lv_img_create(Page2);
    lv_img_set_src(img, &bg_color);

    //lv_obj_set_style_bg_color(PageView, lv_color_hex(0x354e6b),LV_STATE_DEFAULT); /* ���ò�����*/
    lv_obj_remove_style(PageView, NULL, LV_PART_SCROLLBAR);  /* �Ƴ������� */

    Page1_Set();
    Page2_Set();

    lv_timer_create(my_timer,500,NULL);
}

            /************************ ������������API *************************/
/**
 * @brief  ҳ��1��������
 * @param
 * @return
 */
static void Page1_Set(void)
{
     lv_obj_set_style_bg_color(Page1,lv_color_hex(0xffffff),LV_STATE_DEFAULT);
}

/**
 * @brief  ҳ��2��������
 * @param
 * @return
 */
static void Page2_Set(void)
{
//    lv_obj_t *label_1 = lv_label_create(Page2);                    /* ������ǩ */
//    lv_label_set_text(label_1, "Page_2");                           /* �����ı����� */
//    lv_obj_set_style_text_font(label_1, font, LV_STATE_DEFAULT);    /* �������� */
//    lv_obj_center(label_1);                                         /* ����λ�� */

    /************** ��������card ****************/
    lv_obj_t *card1 = lv_obj_create(Page2);
    lv_obj_t *card2 = lv_obj_create(Page2);
    lv_obj_t *card3 = lv_obj_create(Page2);

    /************** ��������card ****************/
    Page2_Card1Set(card1);
    Page2_Card2Set(card2);
    Page2_Card3Set(card3);

}



            /************************ ״̬������API *************************/
/**
 * @brief  ״̬�����ú���
 * @param
 * @return
 */
static void StateBar_Set(void)
{

    /* ���״̬�� */
    label_left = lv_label_create(lv_scr_act());                                   /* ������ǩ */
    lv_label_set_text(label_left, "AM 8:30" );                                              /* �����ı����� */
    //lv_label_set_text_fmt(label_left,"2023-%d-%d  %d:%02d",time[0],time[1],time[2],time[3])
    lv_obj_set_style_text_font(label_left, font, LV_STATE_DEFAULT);                         /* �������� */
    lv_obj_align(label_left, LV_ALIGN_TOP_LEFT, 10, 10);                                    /* ����λ�� */

    /* �Ҳ�״̬�� */
    lv_obj_t *label_right = lv_label_create(lv_scr_act());                                  /* ������ǩ */
    lv_label_set_text(label_right, LV_SYMBOL_WIFI);           /* �����ı����� */
    lv_obj_set_style_text_font(label_right, font, LV_STATE_DEFAULT);                        /* �������� */
    lv_obj_align(label_right, LV_ALIGN_TOP_RIGHT, -10, 10);                                 /* ����λ�� */
}


/************************************* ��ʼ��������ز��� ******************************************






*************************************************************************************************/
            /************************ �ٷֱȼ��ػص����� *************************/
/**
 * @brief  �ٷֱȼ��ػص�����
 * @param  *e ���¼���ز����ļ��ϣ��������˸��¼�����������
 * @return ��
 */
static void percent_cb(lv_timer_t* timer)
{
    static uint8_t temp_value = 0;

    if(temp_value< 100)
    {
       temp_value++;
       lv_bar_set_value(Init_bar,temp_value,LV_ANIM_ON);
        lv_label_set_text_fmt(percent_label,"%d %%", lv_bar_get_value(Init_bar));
    }
    else{

        lv_label_set_text_fmt(percent_label,"finsh", lv_bar_get_value(Init_bar));
        lv_timer_del(timer);
        lv_obj_del(InitUI);

        Page_Creat();
    }
}

            /************************ ��ʼ�����洴������ *************************/
static void InitPage_Creat()
{
    InitUI = lv_obj_create(lv_scr_act());

    lv_obj_set_size(InitUI,800,480);
    lv_obj_set_style_bg_color(InitUI,lv_color_black(),LV_STATE_DEFAULT);

    /***************************** ��������� ********************************/

    /*��ʼ��������*/
    Init_bar = lv_bar_create (InitUI);
    lv_bar_set_range(Init_bar, 0, 100);
    lv_obj_set_size(Init_bar,300,15);
    lv_obj_align(Init_bar, LV_ALIGN_CENTER,0,-60);
    lv_obj_set_style_anim_time(Init_bar,3000,LV_STATE_DEFAULT);
    lv_bar_set_value(Init_bar, 100, LV_ANIM_ON);
 //   lv_obj_set_style_opa(Init_bar,50,LV_STATE_DEFAULT);

    /* �ٷֱȱ�ǩ*/
    percent_label = lv_label_create(InitUI);
    lv_obj_align_to(percent_label,Init_bar,LV_ALIGN_OUT_RIGHT_TOP,20,-3);
    lv_label_set_text(percent_label,"0%");

    lv_obj_set_style_text_color(percent_label,lv_color_white(),LV_STATE_DEFAULT);
    lv_timer_create(percent_cb,30,NULL);          /* �ٷֱȼ��ض�ʱ�ص�����*/

    /******************************* ������� ********************************/
    /*���̿�*/
    lv_obj_t * box = lv_obj_create(InitUI);
    lv_obj_set_size(box,300,200);
    lv_obj_align(box,LV_ALIGN_CENTER,0,100);
    lv_obj_set_style_bg_color(box,lv_color_black(),LV_STATE_DEFAULT);

    /*���ؽ���*/
    lv_obj_t * SH_Label = lv_label_create(box);
    lv_obj_t * SG_Label = lv_label_create(box);
    lv_obj_t * WIFI_Label = lv_label_create(box);
    lv_obj_t * TIME_Label = lv_label_create(box);

    /*����λ��*/
    lv_obj_align(SH_Label,LV_ALIGN_TOP_LEFT,0,0);
    lv_obj_align_to(SG_Label,SH_Label,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
    lv_obj_align_to(WIFI_Label,SG_Label,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);
    lv_obj_align_to(TIME_Label,WIFI_Label,LV_ALIGN_OUT_BOTTOM_LEFT,0,10);

    /*�����ı�*/
    lv_label_set_text(SH_Label, "SHT30  OK");                           /* �����ı����� */
    lv_label_set_text(SG_Label, "SGP30  OK");                           /* �����ı����� */
    lv_label_set_text(WIFI_Label, "WIFI  Connecting ");                           /* �����ı����� */
    lv_label_set_text(TIME_Label, "Time   OK ");                           /* �����ı����� */
   // lv_obj_set_style_text_font(SH_Label, font, LV_STATE_DEFAULT);    /* �������� */
    lv_obj_set_style_text_color(SH_Label,lv_color_white(),LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(SG_Label,lv_color_white(),LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(WIFI_Label,lv_color_white(),LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(TIME_Label,lv_color_white(),LV_STATE_DEFAULT);

    /*���ö���*/

    lv_anim_t a1,a2,a3,a4;
    lv_anim_timeline_t* anim_TimeLine = lv_anim_timeline_create();      /*����ʱ����*/

    lv_anim_init(&a1);
    lv_anim_init(&a2);
    lv_anim_init(&a3);
    lv_anim_init(&a4);

    /*�󶨱�ǩ*/
    a1.var = SH_Label;
    a2.var = SG_Label;
    a3.var = WIFI_Label;
    a4.var = TIME_Label;

    /* ��������*/
    a1.exec_cb = a2.exec_cb = a3.exec_cb = a4.exec_cb = (lv_anim_exec_xcb_t)lv_obj_set_height;
    /*����ʱ��*/
    a1.time = a2.time = 500;
    a3.time = a4.time = 1000;
    /*��ʼ�ͽ�����ֵ*/
    a1.start_value =  a2.start_value =  a3.start_value =   a4.start_value = 0;
    a1.end_value =  a2.end_value =  a3.end_value =  a4.end_value = 20;

    lv_anim_timeline_add(anim_TimeLine,100,&a1);              /*a1 ����*/
    lv_anim_timeline_add(anim_TimeLine,600,&a2);              /*a1 ����*/
    lv_anim_timeline_add(anim_TimeLine,1200,&a3);              /*a1 ����*/
    lv_anim_timeline_add(anim_TimeLine,2300,&a4);              /*a1 ����*/

    lv_anim_timeline_start(anim_TimeLine);

}



/**
 * @brief   ���±���ʱ��
 * @param  @SwitcState
 * @return
 */
void Time_Update(uint8_t time[])
{
    //lv_label_set_text(label_left, "AM 8:30" );  
    lv_label_set_text_fmt(label_left,"2023-%d-%d  %d:%02d",time[0],time[1],time[2],time[3]);
}

void My_Gui(void)
{

    InitPage_Creat();
    // Page_Creat();
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

    // lv_label_set_text_fmt(Temp_Lable,"%d.%d",26,3);
    // lv_label_set_text_fmt(Humi_Lable,"%d",47);

    lv_label_set_text_fmt(TVOC_Lable,"%d",TVOCData);
    lv_label_set_text_fmt(CO2_Lable,"%d",CO2Data);
}
