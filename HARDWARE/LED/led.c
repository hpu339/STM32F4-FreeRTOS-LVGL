/*
 * @Author: Yang Lixin
 * @Date: 2023-04-30 20:03:58
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-05-22 12:37:45
 * @Description: 
 */
#include "led.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

//��ʼ��PF9��PF10Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{    	 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);	//ʹ��GPIOFʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);	//ʹ��GPIOFʱ��

	//GPIOF9,F10��ʼ������
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;	//LED0��LED1��ӦIO��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_9 | GPIO_Pin_10;	//LED0��LED1��ӦIO��
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	//LED0��LED1��ӦIO��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//����
	GPIO_Init(GPIOE, &GPIO_InitStructure);					//��ʼ��GPIO
	GPIO_Init(GPIOF, &GPIO_InitStructure);					//��ʼ��GPIO
	GPIO_SetBits(GPIOE,GPIO_Pin_5);			//GPIOF9,F10���øߣ�����
	GPIO_SetBits(GPIOE,GPIO_Pin_6);			//GPIOF9,F10���øߣ�����
	GPIO_SetBits(GPIOF,GPIO_Pin_9);			//GPIOF9,F10���øߣ�����
	GPIO_SetBits(GPIOF,GPIO_Pin_10);			//GPIOF9,F10���øߣ�����

}






