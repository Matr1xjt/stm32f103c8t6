#include"stm32f10x.h"
#include"bsp_led.h"
#include"bsp_exti_key.h"
void delay(uint32_t count)
{
	for(;count!=0;count--);
}


int main(void){
	LED_GPIO_Config();
	
	EXTI_KEY_Config();
	while(1)
	{

	}
}