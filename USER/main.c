
/*
 * @Author: Yang Lixin
 * @Date: 2023-04-10 20:04:02
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-05-16 11:19:41
 * @Description: 
 */
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
#define START_TASK_PRIO			1			//任务优先级
#define START_STK_SIZE 			256  		//任务堆栈大小	
TaskHandle_t StartTask_Handler;				//任务句柄
void start_task(void *pvParameters);		//任务函数

/****************** 开始任务 ******************/
#define HIGH_TASK_PRIO 			4
#define HIGH_STK_SIZE  			512 
TaskHandle_t HighTask_Handler;
void high_task(void *pvParameters);

/****************** 温湿度获取任务 ******************/
#define DHT11_TASK_PRIO 			4
#define DHT11_STK_SIZE  			512 
TaskHandle_t DHT11Task_Handler;
void dht11_task(void *pvParameters);

//互斥信号量句柄
SemaphoreHandle_t MutexSemaphore;	//互斥信号量


/****************** ****************************************
 * 
 * 					全局变量声明
 * 
 ***************** *****************************************/
uint8_t DHT11_temp_int;				//温度变量整数部分
uint8_t DHT11_temp_flot;			//温度变量小数部分
uint8_t DHT11_humi_int;				//湿度变量整数部分

uint16_t SHT30_temp;
uint16_t SHT30_humi;

uint32_t sgp30_dat,CO2Data,TVOCData;
int main(void)
{ 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4
	delay_init(168);					//初始化延时函数
	uart_init(9600);
	uart3_init(9600);     				//初始化串口
	LED_Init();		        			//初始化LED端口
	KEY_Init();							//初始化按键
	LCD_Init();							//初始化LCD
	DHT11_Init();						//初始化温湿度传感器
	SHT30_Init();
	SGP30_Init();
	delay_ms(100);
	// SGP30_Write(0x20,0x08);
	// sgp30_dat = SGP30_Read();//读取SGP30的值
	// CO2Data = (sgp30_dat & 0xffff0000) >> 16;
	// TVOCData = sgp30_dat & 0x0000ffff;
	
	FSMC_SRAM_Init();
	TIM9_PWM_Init(500-1,168-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.  
	
	//TIM_SetCompare1(TIM14,led0pwmval);	//修改比较值，修改占空比
    wifi_protocol_init();
	my_lvgl_init();
	
	//my_lvgl_test();		//测试案例
	//my_lvgl_test_2(); 
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
    xTaskCreate((TaskFunction_t )high_task,             
                (const char*    )"high_task",           
                (uint16_t       )HIGH_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )HIGH_TASK_PRIO,        
                (TaskHandle_t*  )&HighTask_Handler);   

	xTaskCreate((TaskFunction_t )dht11_task,             
				(const char*    )"dht11_task",           
				(uint16_t       )DHT11_STK_SIZE,        
				(void*          )NULL,                  
				(UBaseType_t    )DHT11_TASK_PRIO,        
				(TaskHandle_t*  )&DHT11Task_Handler);  
    vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}


//高优先级任务的任务函数
void high_task(void *pvParameters)
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

void dht11_task(void *pvParameters)
{
	while(1)
	{
		//DHT11_Read_Data(&DHT11_temp_int,&DHT11_temp_flot,&DHT11_humi_int);
		SHT30_read_result(0x44,&SHT30_temp,&SHT30_humi);

		// mcu_dp_value_update(DPID_TEMP_CURRENT,DHT11_temp_int*10+DHT11_temp_flot);
		// mcu_dp_value_update(DPID_HUMIDITY_VALUE,DHT11_humi_int);
		mcu_dp_value_update(DPID_TEMP_CURRENT,26*10+3);
		mcu_dp_value_update(DPID_HUMIDITY_VALUE,47);
		SGP30_Write(0x20,0x08);
		sgp30_dat = SGP30_Read();//读取SGP30的值
		CO2Data = (sgp30_dat & 0xffff0000) >> 16;
		TVOCData = sgp30_dat & 0x0000ffff;

		// mcu_dp_value_update(DPID_TVOC,TVOCData);
		// mcu_dp_value_update(DPID_CO2_VALUE,CO2Data);
		mcu_dp_value_update(DPID_TVOC,24);
		mcu_dp_value_update(DPID_CO2_VALUE,445);
		
		vTaskDelay(1000);
	}
}
