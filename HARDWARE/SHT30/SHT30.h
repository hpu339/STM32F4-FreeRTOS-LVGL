#ifndef SHT30_H
#define SHT30_H
#include "delay.h"
#include "sys.h"
#include "stdio.h"
#include "usart.h"
#include "string.h"
 
extern u8 humiture_buff1[20];

void SHT30_Init(void);
void IIC_ACK(void);
void IIC_NACK(void);
u8 IIC_wait_ACK(void);
void SHT30_IIC_Start(void);
void SHT30_IIC_Stop(void);
void IIC_SendByte(u8 byte);
u8 IIC_RcvByte(void);
void SHT30_read_result(u8 addr,u16 *temp,u16 *humi);
 
 #endif

