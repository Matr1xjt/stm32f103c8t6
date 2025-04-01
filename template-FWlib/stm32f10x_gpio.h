#include"stm32f10x.h"

#define GPIO_Pin_0 ((uint16_t)(1<<0))
#define GPIO_Pin_1 ((uint16_t)(1<<1))
#define GPIO_Pin_2 ((uint16_t)(1<<2))
#define GPIO_Pin_3 ((uint16_t)(1<<3))
#define GPIO_Pin_4 ((uint16_t)(1<<4))
#define GPIO_Pin_5 ((uint16_t)(1<<5))
#define GPIO_Pin_6 ((uint16_t)(1<<6))

typedef enum{
	GPIO_Speed_10MHZ=1,
	GPIO_Speed_2MHZ,
	GPIO_Speed_50MHZ
}GPIOSpeed_TypeDef;

typedef struct{
	uint16_t GPIO_Pin;
	GPIOSpeed_TypeDef GPIO_Speed;
	uint16_t GPIO_Mode;
}GPIO_InitTypeDef;





void GPIO_SetBits(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);


void GPIO_ReSetBits(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);