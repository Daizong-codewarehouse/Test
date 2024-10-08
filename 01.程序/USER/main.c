#include "delay.h"
#include "sys.h"
#include "led.h"
#include "oled.h"
#include "hcsr04.h"
#include "adc.h"
#include "key.h"

float  dis;

int adcx3;  			//AD转换的结果
float adc3;

int GM_YZ=40;
int CH_YZ=40;

int key_value;		//键值的定义


	
int main(void)
{	
	delay_init();	   		 //延时函数初始化	  
	LED_Init();		  		 //初始化与外设连接的硬件接口
	OLED_Init();         //OLED初始化
	OLED_Clear();        //OLED清屏
	Hcsr04Init();		//超声波初始化
	Adc_Init();							//ADC转换初始化
	KEY_Init();
	
	
	while(1)
	{	
		
		/*光敏电阻*/
		adcx3=Get_Adc_Average(ADC_Channel_8,10);			//PB0通道8检测电压
		adc3 = 100-(adcx3/40);       
		OLED_ShowCHinese(0,0,0);              //显示光照强度
		OLED_ShowCHinese(16,0,1);
		OLED_ShowCHinese(32,0,2);              
		OLED_ShowCHinese(48,0,3);
		OLED_ShowNum(70,0,adc3,2,16);	
		OLED_ShowNum(90,0,GM_YZ,2,16);
		
		
		/*超声波*/
		dis=Hcsr04GetLength();	     //输出超声波距离
		OLED_ShowCHinese(0,2,4);     //显示距离
		OLED_ShowCHinese(16,2,5); 
		OLED_ShowNum(70,2,dis,2,16);
		OLED_ShowNum(90,2,CH_YZ,2,16);	
		
		if((int)adc3<=GM_YZ||(int)dis<CH_YZ)
		{
			LED1=0;	//蜂鸣器
		}
			else
			{
			LED1=1;	//蜂鸣器
			}

		if((int)adc3<=GM_YZ)	
		{
			LED2=1;		//LED
		}
		else
		{
			LED2=0;
		}
		
		
		
		if(KEY1==0)
		{
			while(KEY1==0);
			GM_YZ++;
			if(GM_YZ>99)
			{
				GM_YZ=99;
			}
		}
		if(KEY2==0)
		{
			while(KEY2==0);
			GM_YZ--;
			if(GM_YZ<1)
			{
				GM_YZ=1;
			}
		}
		if(KEY3==0)
		{
			while(KEY3==0);
			CH_YZ++;
			if(GM_YZ>99)
			{
				GM_YZ=99;
			}
		}
		if(KEY4==0)
		{
			while(KEY4==0);
			CH_YZ--;
			if(GM_YZ<1)
			{
				GM_YZ=1;
			}
		}

		




	}
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
