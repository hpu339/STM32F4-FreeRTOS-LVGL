/**
 * @Description: 
 * @Author: Ylx
 * @Date: 2023-06-02 21:39:11
 * @LastEditors: hpu339 15513924345@163.com
 * @LastEditTime: Do not edit
 * @FilePath: Do not edit
 */
//#include<stdbool.h>
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "lcd.h"
#include "key.h"
#include "string.h"
#include "malloc.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "wifi.h"
#include "sram.h"
#include "pwm.h"
#include "dht11.h"
#include "sgp30.h"
#include "SHT30.h"
#include "my_gui.h"


/****************** ****************************************
 * 
 * 					FreeRTOS�����������
 * 
 ***************** *****************************************/

/****************** ��ʼ���� ******************/
#define START_TASK_PRIO				1			//�������ȼ�
#define START_STK_SIZE 				256  		//�����ջ��С	
TaskHandle_t StartTask_Handler;					//������
void start_task(void *pvParameters);			//������

/****************** ������ȼ������� ******************/
#define HIGH_TASK_PRIO 				4
#define HIGH_STK_SIZE  				512 
TaskHandle_t HighTask_Handler;
void high_Task(void *pvParameters);

/****************** ��ʱ����Ĺ������� ******************/
#define TIMERCONTROL_TASK_PRIO     2
#define TIMERCONTROL_STK_SIZE      512 
TaskHandle_t TimerControlTask_Handler;
void timercontrol_task(void *pvParameters);


/****************** ��ʱ����� ******************/
TimerHandle_t 	SensorReloadTimer_Handle;	//���������ڶ�ʱ�����
TimerHandle_t 	WifiReloadTimer_Handle;	 	//wifiģ���������ڶ�ʱ�����

void SensorReloadCallback(TimerHandle_t xTimer); 	//�������ص�����
void WifiReloadCallback(TimerHandle_t xTimer);		//wifi��ʱ���ص�����



//�����ź������
SemaphoreHandle_t MutexSemaphore;	//�����ź���


/**********************************************************
 * 
 * 					ȫ�ֱ�������
 * 
 **********************************************************/

uint16_t SHT30_temp;				//�¶���λ��
uint16_t SHT30_humi;				//ʪ��
uint32_t sgp30_dat,CO2Data,TVOCData;//�������ݡ�CO2��TVOC

uint8_t LED1_Light_Value;			//LED1�Ƶ�����
bool Switch1_State_bool = 0;			//����1״̬
bool Switch2_State_bool = 0;			//����2״̬
bool time_receive_success_flag = 0;		//ʱ���ȡ�ɹ���־λ
uint8_t local_time[4];					//�������ʱ�䣬Сʱ�ͷ���


int main(void)
{ 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4
	delay_init(168);					//��ʼ����ʱ����
	uart_init(9600);
	uart3_init(9600);     				//��ʼ������
	LED_Init();		        			//��ʼ��LED�˿�
	KEY_Init();							//��ʼ������
	LCD_Init();							//��ʼ��LCD
	SHT30_Init();
	SGP30_Init();

	FSMC_SRAM_Init();
	TIM9_PWM_Init(500-1,168-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.  
	
    wifi_protocol_init();
	my_lvgl_init();
	wifi_uart_service();

	My_Gui();

	//������ʼ����
    xTaskCreate((TaskFunction_t )start_task,            //������
                (const char*    )"start_task",          //��������
                (uint16_t       )START_STK_SIZE,        //�����ջ��С
                (void*          )NULL,                  //���ݸ��������Ĳ���
                (UBaseType_t    )START_TASK_PRIO,       //�������ȼ�
                (TaskHandle_t*  )&StartTask_Handler);   //������              
    vTaskStartScheduler();          //�����������
}

//��ʼ����������
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //�����ٽ���
	SensorReloadTimer_Handle = xTimerCreate((const char*		)"SensorReloadTimer",
									    	(TickType_t			)500,	//500ms
							            	(UBaseType_t		)pdTRUE,
							            	(void*				)1,
							            	(TimerCallbackFunction_t)SensorReloadCallback);

	WifiReloadTimer_Handle = xTimerCreate((const char*		)"WifiReloadTimer",
									      (TickType_t		)1000,		//1s
							              (UBaseType_t		)pdTRUE,
							              (void*			)2,
							              (TimerCallbackFunction_t)WifiReloadCallback);

    xTaskCreate((TaskFunction_t )high_Task,             
                (const char*    )"high_Task",           
                (uint16_t       )HIGH_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )HIGH_TASK_PRIO,        
                (TaskHandle_t*  )&HighTask_Handler);   

	xTaskCreate((TaskFunction_t )timercontrol_task,             
				(const char*    )"timercontrol_task",           
				(uint16_t       )TIMERCONTROL_STK_SIZE,        
				(void*          )NULL,                  
				(UBaseType_t    )TIMERCONTROL_TASK_PRIO,        
				(TaskHandle_t*  )&TimerControlTask_Handler);  
    vTaskDelete(StartTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL();            //�˳��ٽ���
}


//�����ȼ������������
void high_Task(void *pvParameters)
{
	//My_Gui();
	while(1)
	{
		/* ������������ */
		/* ���ݹٷ�˵����ʹ�ò���ϵͳʱ���õ�LVGL���κεط���Ҫ���ϻ����� */
		//xSemaphoreTake(MutexSemaphore,portMAX_DELAY);	//��ȡ�����ź���
		lv_task_handler();
		//xSemaphoreGive(MutexSemaphore);					//�ͷ��ź���
		wifi_uart_service();
		vTaskDelay(10);	//��ʱ10ms��Ҳ����500��ʱ�ӽ���  
	}
}

void timercontrol_task(void *pvParameters)
{
	static uint8_t task_start_flag = 1;		//����ɾ����־λ
	while(1)
	{
		if((SensorReloadTimer_Handle!=NULL)&&(WifiReloadTimer_Handle!=NULL)&&task_start_flag)
		{
			xTimerStart(SensorReloadTimer_Handle,0);
			xTimerStart(WifiReloadTimer_Handle,0);
			task_start_flag = 0;			//��������
		}
		printf("timecontrol_task running\n");
		mcu_get_system_time();
		mcu_write_rtctime(local_time);
		if(time_receive_success_flag) vTaskDelete(TimerControlTask_Handler);	//ɾ������
		vTaskDelay(10);
	}
}

void SensorReloadCallback(TimerHandle_t xTimer)
{
	/**************** ��ʪ�� ***************/
	SHT30_read_result(0x44,&SHT30_temp,&SHT30_humi);

	/*************** CO2/TVOC **************/
	SGP30_Write(0x20,0x08);
	sgp30_dat = SGP30_Read();//��ȡSGP30��ֵ
	CO2Data = (sgp30_dat & 0xffff0000) >> 16;
	TVOCData = sgp30_dat & 0x0000ffff;

	/*************** dp���ϱ� **************/
	mcu_dp_value_update(DPID_TEMP_CURRENT,SHT30_temp);
	mcu_dp_value_update(DPID_HUMIDITY_VALUE,SHT30_humi);
	mcu_dp_value_update(DPID_TVOC,TVOCData);
	mcu_dp_value_update(DPID_CO2_VALUE,CO2Data);
	//LED_0 = ~LED_0;
}	

void WifiReloadCallback(TimerHandle_t xTimer)
{
	//mcu_get_wifi_connect_status();
	mcu_get_system_time();
	//request_weather_serve();
	mcu_write_rtctime(local_time);	
	// mcu_open_weather();
	// request_weather_serve();
	//printf("���ڲ���%d:%d\n",local_time[0],local_time[1]);
	//LED_1 = ~LED_1;
	printf("wifi_task\n");
}		