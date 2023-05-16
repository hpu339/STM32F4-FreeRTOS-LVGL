/*
 * @description: 
 * @event: 
 * @param: 
 * @return: 
 */
/**
 * @Description: 
 * @Author: Ylx
 * @Date: 2023-05-08 09:38:31
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-05-15 09:52:54
 * @FilePath: Do not edit
 */

#ifndef __HX711_H
#define __HX711_H
#include "sys.h"

//#if 0
    #define  SGP30_SCL   PBout(12)
    #define  SGP30_SDA   PBout(13)


    // USART GPIO ���ź궨��
    #define  SGP30_SCL_GPIO_CLK        RCC_AHB1Periph_GPIOB
    #define  SGP30_SCL_GPIO_PORT       GPIOB
    #define  SGP30_SCL_GPIO_PIN        GPIO_Pin_12

    #define  SGP30_SDA_GPIO_SDA        RCC_AHB1Periph_GPIOB
    #define  SGP30_SDA_GPIO_PORT       GPIOB
    #define  SGP30_SDA_GPIO_PIN        GPIO_Pin_13

//#else 

    // #define  SGP30_SCL   PFout(7)
    // #define  SGP30_SDA   PFout(6)


    // // USART GPIO ���ź궨��
    // #define  SGP30_SCL_GPIO_CLK        RCC_AHB1Periph_GPIOF
    // #define  SGP30_SCL_GPIO_PORT       GPIOF
    // #define  SGP30_SCL_GPIO_PIN        GPIO_Pin_7

    // #define  SGP30_SDA_GPIO_SDA        RCC_AHB1Periph_GPIOF
    // #define  SGP30_SDA_GPIO_PORT       GPIOF
    // #define  SGP30_SDA_GPIO_PIN        GPIO_Pin_6

//#endif

#define  SGP30_SDA_READ()           GPIO_ReadInputDataBit(SGP30_SDA_GPIO_PORT, SGP30_SDA_GPIO_PIN)

#define SGP30_read  0xb1  //SGP30�Ķ���ַ
#define SGP30_write 0xb0  //SGP30��д��ַ


void SGP30_IIC_Start(void);				//����IIC��ʼ�ź�
void SGP30_IIC_Stop(void);	  			//����IICֹͣ�ź�
void SGP30_IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u16 SGP30_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 SGP30_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void SGP30_IIC_Ack(void);					//IIC����ACK�ź�
void SGP30_IIC_NAck(void);				//IIC������ACK�ź�
void SGP30_IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 SGP30_IIC_Read_One_Byte(u8 daddr,u8 addr);	
void SGP30_Init(void);				  
void SGP30_Write(u8 a, u8 b);
u32 SGP30_Read(void);



#endif

