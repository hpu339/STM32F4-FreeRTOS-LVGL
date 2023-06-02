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
 * 					FreeRTOS相关任务声明
 * 
 ***************** *****************************************/

/****************** 开始任务 ******************/
#define START_TASK_PRIO				1			//任务优先级
#define START_STK_SIZE 				256  		//任务堆栈大小	
TaskHandle_t StartTask_Handler;					//任务句柄
void start_task(void *pvParameters);			//任务函数

/****************** 最高优先级的任务 ******************/
#define HIGH_TASK_PRIO 				4
#define HIGH_STK_SIZE  				512 
TaskHandle_t HighTask_Handler;
void high_Task(void *pvParameters);

/****************** 定时任务的管理任务 ******************/
#define TIMERCONTROL_TASK_PRIO     2
#define TIMERCONTROL_STK_SIZE      512 
TaskHandle_t TimerControlTask_Handler;
void timercontrol_task(void *pvParameters);


/****************** 定时器相关 ******************/
TimerHandle_t 	SensorReloadTimer_Handle;	//传感器周期定时器句柄
TimerHandle_t 	WifiReloadTimer_Handle;	 	//wifi模组任务周期定时器句柄

void SensorReloadCallback(TimerHandle_t xTimer); 	//传感器回调函数
void WifiReloadCallback(TimerHandle_t xTimer);		//wifi定时器回调函数



//互斥信号量句柄
SemaphoreHandle_t MutexSemaphore;	//互斥信号量


/**********************************************************
 * 
 * 					全局变量声明
 * 
 **********************************************************/

uint16_t SHT30_temp;				//温度三位数
uint16_t SHT30_humi;				//湿度
uint32_t sgp30_dat,CO2Data,TVOCData;//气体数据、CO2、TVOC

uint8_t LED1_Light_Value;			//LED1灯的亮度
bool Switch1_State_bool = 0;			//开关1状态
bool Switch2_State_bool = 0;			//开关2状态
bool time_receive_success_flag = 0;		//时间获取成功标志位
uint8_t local_time[4];					//用来存放时间，小时和分钟


int main(void)
{ 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4
	delay_init(168);					//初始化延时函数
	uart_init(9600);
	uart3_init(9600);     				//初始化串口
	LED_Init();		        			//初始化LED端口
	KEY_Init();							//初始化按键
	LCD_Init();							//初始化LCD
	SHT30_Init();
	SGP30_Init();

	FSMC_SRAM_Init();
	TIM9_PWM_Init(500-1,168-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.  
	
    wifi_protocol_init();
	my_lvgl_init();
	wifi_uart_service();

	My_Gui();

	//创建开始任务
    xTaskCreate((TaskFunction_t )start_task,            //任务函数
                (const char*    )"start_task",          //任务名称
                (uint16_t       )START_STK_SIZE,        //任务堆栈大小
                (void*          )NULL,                  //传递给任务函数的参数
                (UBaseType_t    )START_TASK_PRIO,       //任务优先级
                (TaskHandle_t*  )&StartTask_Handler);   //任务句柄              
    vTaskStartScheduler();          //开启任务调度
}

//开始任务任务函数
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //进入临界区
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
    vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}


//高优先级任务的任务函数
void high_Task(void *pvParameters)
{
	//My_Gui();
	while(1)
	{
		/* 互斥量的引入 */
		/* 根据官方说明：使用操作系统时调用到LVGL的任何地方都要加上互斥量 */
		//xSemaphoreTake(MutexSemaphore,portMAX_DELAY);	//获取互斥信号量
		lv_task_handler();
		//xSemaphoreGive(MutexSemaphore);					//释放信号量
		wifi_uart_service();
		vTaskDelay(10);	//延时10ms，也就是500个时钟节拍  
	}
}

void timercontrol_task(void *pvParameters)
{
	static uint8_t task_start_flag = 1;		//任务删除标志位
	while(1)
	{
		if((SensorReloadTimer_Handle!=NULL)&&(WifiReloadTimer_Handle!=NULL)&&task_start_flag)
		{
			xTimerStart(SensorReloadTimer_Handle,0);
			xTimerStart(WifiReloadTimer_Handle,0);
			task_start_flag = 0;			//任务打开完毕
		}
		printf("timecontrol_task running\n");
		mcu_get_system_time();
		mcu_write_rtctime(local_time);
		if(time_receive_success_flag) vTaskDelete(TimerControlTask_Handler);	//删除任务
		vTaskDelay(10);
	}
}

void SensorReloadCallback(TimerHandle_t xTimer)
{
	/**************** 温湿度 ***************/
	SHT30_read_result(0x44,&SHT30_temp,&SHT30_humi);

	/*************** CO2/TVOC **************/
	SGP30_Write(0x20,0x08);
	sgp30_dat = SGP30_Read();//读取SGP30的值
	CO2Data = (sgp30_dat & 0xffff0000) >> 16;
	TVOCData = sgp30_dat & 0x0000ffff;

	/*************** dp点上报 **************/
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
	//printf("串口测试%d:%d\n",local_time[0],local_time[1]);
	//LED_1 = ~LED_1;
	printf("wifi_task\n");
}		