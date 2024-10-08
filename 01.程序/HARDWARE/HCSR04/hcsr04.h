#ifndef __HCSR_H
#define __HCSR_H 
#include "sys.h"   



//超声波硬件接口定义
#define HCSR04_PORT     GPIOB
#define HCSR04_CLK      RCC_APB2Periph_GPIOB
#define HCSR04_TRIG     GPIO_Pin_7
#define HCSR04_ECHO     GPIO_Pin_6
#define TRIG_Send  PBout(7)
#define ECHO_Reci  PBin(6)
       		   
void hcsr04_NVIC(void);
void Hcsr04Init(void);
void OpenTimerForHc(void);
void CloseTimerForHc(void);
u32 GetEchoTimer(void);
float Hcsr04GetLength(void );

#endif















