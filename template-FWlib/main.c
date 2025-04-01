#include"stm32f10x.h"
#include"stm32f10x_gpio.h"

void soft_delay( unsigned int count )
{
	for(; count !=0;count--);
}

int main(void)
{
	*(unsigned int *)0x40021018 |=( (1) << 4 );
	
	GPIOC->CRL |=( (1) << (4*2) );
	
	GPIOC->ODR &=~(1<<2);

		
	while(1){
		GPIO_SetBits(GPIOC,GPIO_Pin_2);
		soft_delay(0xfffff);
		
		GPIO_ReSetBits(GPIOC,GPIO_Pin_2);
		soft_delay(0xfffff);
		
		
	}
}

void SystemInit(void)
{
	
}