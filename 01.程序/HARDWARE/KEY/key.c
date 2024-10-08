#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

//按键初始化函数
void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(KEY1_PORT_CLK|KEY2_PORT_CLK|KEY3_PORT_CLK|KEY4_PORT_CLK,ENABLE);		//使时钟

	GPIO_InitStructure.GPIO_Pin  = KEY1_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(KEY1_PORT, &GPIO_InitStructure);	//初始化GPIO	
	
	GPIO_InitStructure.GPIO_Pin  = KEY2_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(KEY2_PORT, &GPIO_InitStructure);	//初始化GPIO
	
	GPIO_InitStructure.GPIO_Pin  = KEY3_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(KEY3_PORT, &GPIO_InitStructure);	//初始化GPIO
	
	GPIO_InitStructure.GPIO_Pin  = KEY4_PORT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(KEY4_PORT, &GPIO_InitStructure);	//初始化GPIO	
	
}




