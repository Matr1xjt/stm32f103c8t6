#include"stm32f10x.h"
#include"bsp_led.h"

void delay(uint32_t count)
{
	for(;count!=0;count--);
}


int main(void){
	HSE_SetSysCLK(RCC_PLLMul_8);
	LED_GPIO_Config();
	
	while(1)
	{
		
		
		
		
		GPIO_SetBits(GPIOC,GPIO_Pin_2);
		delay(0xfffff);
		GPIO_ResetBits(GPIOC,GPIO_Pin_2);
		delay(0xfffff);
		
		GPIO_SetBits(GPIOC,GPIO_Pin_3);
		delay(0xfffff);
		GPIO_ResetBits(GPIOC,GPIO_Pin_3);
		delay(0xfffff);
		
	}
}