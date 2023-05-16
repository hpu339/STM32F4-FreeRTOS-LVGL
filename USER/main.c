
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
 * 					FreeRTOS�����������
 * 
 ***************** *****************************************/

/****************** ��ʼ���� ******************/
#define START_TASK_PRIO			1			//�������ȼ�
#define START_STK_SIZE 			256  		//�����ջ��С	
TaskHandle_t StartTask_Handler;				//������
void start_task(void *pvParameters);		//������

/****************** ��ʼ���� ******************/
#define HIGH_TASK_PRIO 			4
#define HIGH_STK_SIZE  			512 
TaskHandle_t HighTask_Handler;
void high_task(void *pvParameters);

/****************** ��ʪ�Ȼ�ȡ���� ******************/
#define DHT11_TASK_PRIO 			4
#define DHT11_STK_SIZE  			512 
TaskHandle_t DHT11Task_Handler;
void dht11_task(void *pvParameters);

//�����ź������
SemaphoreHandle_t MutexSemaphore;	//�����ź���


/****************** ****************************************
 * 
 * 					ȫ�ֱ�������
 * 
 ***************** *****************************************/
uint8_t DHT11_temp_int;				//�¶ȱ�����������
uint8_t DHT11_temp_flot;			//�¶ȱ���С������
uint8_t DHT11_humi_int;				//ʪ�ȱ�����������

uint16_t SHT30_temp;
uint16_t SHT30_humi;

uint32_t sgp30_dat,CO2Data,TVOCData;
int main(void)
{ 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4
	delay_init(168);					//��ʼ����ʱ����
	uart_init(9600);
	uart3_init(9600);     				//��ʼ������
	LED_Init();		        			//��ʼ��LED�˿�
	KEY_Init();							//��ʼ������
	LCD_Init();							//��ʼ��LCD
	DHT11_Init();						//��ʼ����ʪ�ȴ�����
	SHT30_Init();
	SGP30_Init();
	delay_ms(100);
	// SGP30_Write(0x20,0x08);
	// sgp30_dat = SGP30_Read();//��ȡSGP30��ֵ
	// CO2Data = (sgp30_dat & 0xffff0000) >> 16;
	// TVOCData = sgp30_dat & 0x0000ffff;
	
	FSMC_SRAM_Init();
	TIM9_PWM_Init(500-1,168-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.  
	
	//TIM_SetCompare1(TIM14,led0pwmval);	//�޸ıȽ�ֵ���޸�ռ�ձ�
    wifi_protocol_init();
	my_lvgl_init();
	
	//my_lvgl_test();		//���԰���
	//my_lvgl_test_2(); 
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
    vTaskDelete(StartTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL();            //�˳��ٽ���
}


//�����ȼ������������
void high_task(void *pvParameters)
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
		sgp30_dat = SGP30_Read();//��ȡSGP30��ֵ
		CO2Data = (sgp30_dat & 0xffff0000) >> 16;
		TVOCData = sgp30_dat & 0x0000ffff;

		// mcu_dp_value_update(DPID_TVOC,TVOCData);
		// mcu_dp_value_update(DPID_CO2_VALUE,CO2Data);
		mcu_dp_value_update(DPID_TVOC,24);
		mcu_dp_value_update(DPID_CO2_VALUE,445);
		
		vTaskDelay(1000);
	}
}
