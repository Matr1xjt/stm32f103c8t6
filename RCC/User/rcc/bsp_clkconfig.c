#include"bsp_clkconfig.h"
 
void HSE_SetSysCLK(uint32_t RCC_PLLMul)
{
	__IO uint32_t StartUpCounter = 0,HSEStatus = 0;
	 
	
	RCC_DeInit();
	
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus == SUCCESS)
	{
		FLASH->ACR |= FLASH_ACR_PRFTBE;
		
		FLASH->ACR &=(uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
		FLASH->ACR |= (uint32_t)((uint32_t)FLASH_ACR_LATENCY_2);
		
		
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul);
		
		RCC_PLLCmd(ENABLE);
		
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		while(RCC_GetSYSCLKSource() !=0x08);
	}
	else
	{
		
	}
	
}