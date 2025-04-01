#ifndef __SPI_ILI9341LCD_H
#define __SPI_ILI9341LCD_H

#include "stm32f10x.h"
#include <stdio.h>

//#define  sFLASH_ID              0xEF3015   //W25X16
//#define  sFLASH_ID              0xEF4015	 //W25Q16
//#define  sFLASH_ID              0XEF4018   //W25Q128
#define  sFLASH_ID              0XEF4017    //W25Q64

#define SPI_FLASH_PageSize              256
#define SPI_FLASH_PerWritePageSize      256

/*命令定义-开头*******************************/
#define W25X_WriteEnable		      0x06 
#define W25X_WriteDisable		      0x04 
#define W25X_ReadStatusReg		    0x05 
#define W25X_WriteStatusReg		    0x01 
#define W25X_ReadData			        0x03 
#define W25X_FastReadData		      0x0B 
#define W25X_FastReadDual		      0x3B 
#define W25X_PageProgram		      0x02 
#define W25X_BlockErase			      0xD8 
#define W25X_SectorErase		      0x20 
#define W25X_ChipErase			      0xC7 
#define W25X_PowerDown			      0xB9 
#define W25X_ReleasePowerDown	    0xAB 
#define W25X_DeviceID			        0xAB 
#define W25X_ManufactDeviceID   	0x90 
#define W25X_JedecDeviceID		    0x9F

/* WIP(busy)标志，FLASH内部正在写入 */
#define WIP_Flag                  0x01
#define Dummy_Byte                0xFF
/*命令定义-结尾*******************************/


//CS(NSS)引脚 片选选普通GPIO即可
#define      ILI9341_CS_CLK                  RCC_APB2Periph_GPIOA   
#define      ILI9341_CS_PORT                 GPIOC
#define      ILI9341_CS_PIN                  GPIO_Pin_4

//RD引脚
#define      ILI9341_RD_CLK                  RCC_APB2Periph_GPIOC   
#define      ILI9341_RD_PORT                 GPIOC
#define      ILI9341_RD_PIN                  GPIO_Pin_5

//WE引脚
#define      ILI9341_WE_CLK                  RCC_APB2Periph_GPIOC
#define      ILI9341_WE_PORT                 GPIOC
#define      ILI9341_WE_PIN                  GPIO_Pin_6

//DC引脚
#define      ILI9341_DC_CLK                  RCC_APB2Periph_GPIOC
#define      ILI9341_DC_PORT                 GPIOC
#define      ILI9341_DC_PIN                  GPIO_Pin_7

//BK
#define      ILI9341_BK_CLK                  RCC_APB2Periph_GPIOD  
#define      ILI9341_BK_PORT                 GPIOD
#define      ILI9341_BK_PIN                  GPIO_Pin_2

//D0-D15
#define      ILI9341_DATA_CLK                  RCC_APB2Periph_GPIOB   
#define      ILI9341_DATA_PORT                 GPIOB
#define      ILI9341_DATA_PIN                  	GPIO_Pin_ALL

#define  		SPI_FLASH_CS_LOW()     						GPIO_ResetBits( ILI9341_CS_PORT, ILI9341_CS_PIN )
#define  		SPI_FLASH_CS_HIGH()    						GPIO_SetBits( ILI9341_CS_PORT, ILI9341_CS_PIN )

/*SPI接口定义-结尾****************************/

/*等待超时时间*/
#define SPIT_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define SPIT_LONG_TIMEOUT         ((uint32_t)(10 * SPIT_FLAG_TIMEOUT))

/*信息输出*/
#define FLASH_DEBUG_ON         1

#define FLASH_INFO(fmt,arg...)           printf("<<-FLASH-INFO->> "fmt"\n",##arg)
#define FLASH_ERROR(fmt,arg...)          printf("<<-FLASH-ERROR->> "fmt"\n",##arg)
#define FLASH_DEBUG(fmt,arg...)          do{\
                                          if(FLASH_DEBUG_ON)\
                                          printf("<<-FLASH-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)



#endif /* __SPI_ILI9341LCD_H */

