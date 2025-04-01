#include"stm32f10x.h"

void soft_delay( unsigned int count )
{
	for(; count !=0;count--);
}

int main(void)
{
	*(unsigned int *)0x40021018 |=( (1) << 4 );
	
	GPIOC_CRL |=( (1) << (4*2) );
	
	GPIOC_ODR &=~(1<<2);

		
	while(1){
		GPIOC_ODR |=(1<<2);
		soft_delay(0xfffff);
		
		GPIOC_ODR &=~(1<<2);
		soft_delay(0xfffff);
		
		
	}
}

void SystemInit(void)
{
	
}