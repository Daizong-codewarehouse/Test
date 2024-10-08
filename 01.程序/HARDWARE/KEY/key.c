#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

//������ʼ������
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(KEY1_PORT_CLK|KEY2_PORT_CLK|KEY3_PORT_CLK|KEY4_PORT_CLK,ENABLE);		//ʹʱ��

	GPIO_InitStructure.GPIO_Pin  = KEY1_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(KEY1_PORT, &GPIO_InitStructure);	//��ʼ��GPIO	
	
	GPIO_InitStructure.GPIO_Pin  = KEY2_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(KEY2_PORT, &GPIO_InitStructure);	//��ʼ��GPIO
	
	GPIO_InitStructure.GPIO_Pin  = KEY3_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(KEY3_PORT, &GPIO_InitStructure);	//��ʼ��GPIO
	
	GPIO_InitStructure.GPIO_Pin  = KEY4_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(KEY4_PORT, &GPIO_InitStructure);	//��ʼ��GPIO	
	
}




