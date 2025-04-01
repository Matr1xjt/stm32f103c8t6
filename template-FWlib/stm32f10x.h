#ifndef __STM32F10X_H
#define __STM32F10X_H


#define PERIPH_BASE ((unsigned int )0x40000000)

#define APB1PERIPH_BASE  PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE+0x00010000)
#define AHBPERIPH_BASE  (PERIPH_BASE+0x00018000)

#define GPIOA_BASE (APB2PERIPH_BASE+0x0800)
#define GPIOB_BASE (APB2PERIPH_BASE+0x0C00)
#define GPIOC_BASE (APB2PERIPH_BASE+0x1000)
#define GPIOD_BASE (APB2PERIPH_BASE+0x1400)

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

typedef struct{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;	
	uint32_t LCKR;
}GPIO_TypeDef;


#define GPIOA ((GPIO_TypeDef * )GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef * )GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef * )GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef * )GPIOD_BASE)

#endif