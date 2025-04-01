#include"stm32f10x.h"
#include"stm32f10x_gpio.h"
void GPIO_SetBits(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin){
	GPIOx->BSRR=GPIO_Pin;
}

void GPIO_ReSetBits(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin){
	GPIOx->BRR=GPIO_Pin;
}

