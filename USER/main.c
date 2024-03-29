#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "lcd.h"
#include "key.h"
#include "beep.h"
#include "string.h"
//#include "malloc.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


#include "lvgl_app.h"



//任务优先级
#define START_TASK_PRIO			1
//任务堆栈大小	
#define START_STK_SIZE 			256  
//任务句柄
TaskHandle_t StartTask_Handler;
//任务函数
void start_task(void *pvParameters);

//任务优先级
#define LOW_TASK_PRIO			2
//任务堆栈大小	
#define LOW_STK_SIZE 			256  
//任务句柄
TaskHandle_t LowTask_Handler;
//任务函数
void low_task(void *pvParameters);

//任务优先级
#define MIDDLE_TASK_PRIO 		3
//任务堆栈大小	
#define MIDDLE_STK_SIZE  		256 
//任务句柄
TaskHandle_t MiddleTask_Handler;
//任务函数
void middle_task(void *pvParameters);

//任务优先级
#define HIGH_TASK_PRIO 			4
//任务堆栈大小	
#define HIGH_STK_SIZE  			512 
//任务句柄
TaskHandle_t HighTask_Handler;
//任务函数
void high_task(void *pvParameters);

//互斥信号量句柄
SemaphoreHandle_t MutexSemaphore;	//互斥信号量

//LCD刷屏时使用的颜色
int lcd_discolor[14]={	WHITE, BLACK, BLUE,  BRED,      
						GRED,  GBLUE, RED,   MAGENTA,       	 
						GREEN, CYAN,  YELLOW,BROWN, 			
						BRRED, GRAY };


int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4
	delay_init(168);					//初始化延时函数
	uart_init(115200);     				//初始化串口
	LED_Init();		        			//初始化LED端口
	KEY_Init();							//初始化按键
	BEEP_Init();						//初始化蜂鸣器
	LCD_Init();							//初始化LCD
   
	
	my_lvgl_init();
	
//	my_lvgl_test();		//测试案例
	my_lvgl_test_2(); 

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
	
	//创建互斥信号量
	MutexSemaphore=xSemaphoreCreateMutex();
	
    //创建高优先级任务
    xTaskCreate((TaskFunction_t )high_task,             
                (const char*    )"high_task",           
                (uint16_t       )HIGH_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )HIGH_TASK_PRIO,        
                (TaskHandle_t*  )&HighTask_Handler);   
    //创建中等优先级任务
    xTaskCreate((TaskFunction_t )middle_task,     
                (const char*    )"middle_task",   
                (uint16_t       )MIDDLE_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )MIDDLE_TASK_PRIO,
                (TaskHandle_t*  )&MiddleTask_Handler); 
	//创建低优先级任务
    xTaskCreate((TaskFunction_t )low_task,     
                (const char*    )"low_task",   
                (uint16_t       )LOW_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )LOW_TASK_PRIO,
                (TaskHandle_t*  )&LowTask_Handler);
    vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}







//高优先级任务的任务函数
void high_task(void *pvParameters)
{

	while(1)
	{
		/* 互斥量的引入 */
		/* 根据官方说明：使用操作系统时调用到LVGL的任何地方都要加上互斥量 */
		xSemaphoreTake(MutexSemaphore,portMAX_DELAY);	//获取互斥信号量
		lv_task_handler();
		xSemaphoreGive(MutexSemaphore);					//释放信号量
		
		
		vTaskDelay(10);	//延时10ms，也就是500个时钟节拍  
	}
}

//中等优先级任务的任务函数
void middle_task(void *pvParameters)
{


	while(1)
	{

		vTaskDelay(500);	//延时1s，也就是1000个时钟节拍	
	}
}

//低优先级任务的任务函数
void low_task(void *pvParameters)
{

	while(1)
	{

		vTaskDelay(500);	//延时1s，也就是1000个时钟节拍	
	}
}

