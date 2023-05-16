#ifndef _dht11_H
#define _dht11_H

#include "sys.h"
#include "stdint.h"
#include "delay.h"
//#include "SysTick.h"

#define DHT11 			(GPIO_Pin_9) //PG9
#define GPIO_DHT11 		GPIOG

#define DHT11_DQ_IN 	PGin(9)	  // ‰»Î
#define DHT11_DQ_OUT 	PGout(9)  // ‰≥ˆ

void DHT11_IO_OUT(void);
void DHT11_IO_IN(void);
uint8_t DHT11_Init(void);
void DHT11_Rst(void);
uint8_t DHT11_Check(void);
uint8_t DHT11_Read_Bit(void);
uint8_t DHT11_Read_Byte(void);
uint8_t DHT11_Read_Data(u8 *temp_int,u8 *temp_flot,u8 *humi_int);    


#endif
