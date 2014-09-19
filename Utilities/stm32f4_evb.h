/**
  ******************************************************************************
  * @file    STM32F4_evb.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-March-2013
  * @brief   This file contains definitions for STM32F4_EVB's Leds, push-buttons
  *          and COM ports hardware resources.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4_EVB_H
#define __STM32F4_EVB_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32_eval_legacy.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */

/** @addtogroup STM32F4_EVB
  * @{
  */

/** @addtogroup STM32F4_EVB_LOW_LEVEL
  * @{
  */

/** @defgroup STM324F4_EVB_LOW_LEVEL_Exported_Types
  * @{
  */
typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3
} Led_TypeDef;

typedef enum
{
	BUTTON_WAKEUP	= 0,
	BUTTON_TAMPER	= 1,
	BUTTON_KEY		= 2
/*	BUTTON_RIGHT	= 3,
	BUTTON_LEFT		= 4,
	BUTTON_UP		= 5,
	BUTTON_DOWN		= 6,
	BUTTON_SEL		= 7*/
} Button_TypeDef;

typedef enum
{
	BUTTON_MODE_GPIO = 0,
	BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

typedef enum
{
	JOY_NONE	= 0,
	JOY_SEL	= 1,
	JOY_DOWN	= 2,
	JOY_LEFT	= 3,
	JOY_RIGHT	= 4,
	JOY_UP	= 5
} JOYState_TypeDef
;

typedef enum
{
	COM1 = 0
} COM_TypeDef;
/**
  * @}
  */

/** @defgroup STM32F4_EVB_LOW_LEVEL_Exported_Constants
  * @{
  */

/**
  * @brief  Define for STM32F4_EVB board
  */
#if !defined (USE_STM32F4_EVB)
	#define USE_STM32F4_EVB
#endif

/** @addtogroup STM32F4_EVB_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             4

#define LED1_PIN                         GPIO_Pin_7
#define LED1_GPIO_PORT                   GPIOF
#define LED1_GPIO_CLK                    RCC_AHB1Periph_GPIOF

#define LED2_PIN                         GPIO_Pin_8
#define LED2_GPIO_PORT                   GPIOF
#define LED2_GPIO_CLK                    RCC_AHB1Periph_GPIOF

#define LED3_PIN                         GPIO_Pin_9
#define LED3_GPIO_PORT                   GPIOF
#define LED3_GPIO_CLK                    RCC_AHB1Periph_GPIOF

#define LED4_PIN                         GPIO_Pin_10
#define LED4_GPIO_PORT                   GPIOF
#define LED4_GPIO_CLK                    RCC_AHB1Periph_GPIOF

/**
  * @}
  */

/** @addtogroup STM32F4_EVB_LOW_LEVEL_BUTTON
  * @{
  */
#define BUTTONn                          3 /*!< Joystick pins are connected to
                                                an IO Expander (accessible through
                                                I2C1 interface) */

/**
 * @brief Wakeup push-button
 */
#define WAKEUP_BUTTON_PIN                GPIO_Pin_0
#define WAKEUP_BUTTON_GPIO_PORT          GPIOA
#define WAKEUP_BUTTON_GPIO_CLK           RCC_AHB1Periph_GPIOA
#define WAKEUP_BUTTON_EXTI_LINE          EXTI_Line0
#define WAKEUP_BUTTON_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOA
#define WAKEUP_BUTTON_EXTI_PIN_SOURCE    EXTI_PinSource0
#define WAKEUP_BUTTON_EXTI_IRQn          EXTI0_IRQn

/**
 * @brief Tamper push-button
 */
#define TAMPER_BUTTON_PIN                GPIO_Pin_13
#define TAMPER_BUTTON_GPIO_PORT          GPIOC
#define TAMPER_BUTTON_GPIO_CLK           RCC_AHB1Periph_GPIOC
#define TAMPER_BUTTON_EXTI_LINE          EXTI_Line13
#define TAMPER_BUTTON_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOC
#define TAMPER_BUTTON_EXTI_PIN_SOURCE    EXTI_PinSource13
#define TAMPER_BUTTON_EXTI_IRQn          EXTI15_10_IRQn

/**
 * @brief Key push-button
 */
#define KEY_BUTTON_PIN                   GPIO_Pin_8
#define KEY_BUTTON_GPIO_PORT             GPIOI
#define KEY_BUTTON_GPIO_CLK              RCC_AHB1Periph_GPIOI
#define KEY_BUTTON_EXTI_LINE             EXTI_Line8
#define KEY_BUTTON_EXTI_PORT_SOURCE      EXTI_PortSourceGPIOI
#define KEY_BUTTON_EXTI_PIN_SOURCE       EXTI_PinSource8
#define KEY_BUTTON_EXTI_IRQn             EXTI9_5_IRQn
/**
  * @}
  */

/** @addtogroup STM32F4_EVB_LOW_LEVEL_COM
  * @{
  */
#define COMn                             1

/**
 * @brief Definition for COM port1, connected to USART1
 */
#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCC_APB2Periph_USART1
#define EVAL_COM1_TX_PIN                 GPIO_Pin_9
#define EVAL_COM1_TX_GPIO_PORT           GPIOA
#define EVAL_COM1_TX_GPIO_CLK            RCC_AHB1Periph_GPIOA
#define EVAL_COM1_TX_SOURCE              GPIO_PinSource9
#define EVAL_COM1_TX_AF                  GPIO_AF_USART1
#define EVAL_COM1_RX_PIN                 GPIO_Pin_10
#define EVAL_COM1_RX_GPIO_PORT           GPIOA
#define EVAL_COM1_RX_GPIO_CLK            RCC_AHB1Periph_GPIOA
#define EVAL_COM1_RX_SOURCE              GPIO_PinSource10
#define EVAL_COM1_RX_AF                  GPIO_AF_USART1
#define EVAL_COM1_IRQn                   USART1_IRQn

/**
  * @}
  */

/** @addtogroup STM32F4_EVB_LOW_LEVEL_SD_FLASH
  * @{
  */
/**
  * @brief  SD FLASH SDIO Interface
  */
#define SD_DETECT_PIN					GPIO_Pin_11                 /* PF.11 */
#define SD_DETECT_GPIO_PORT				GPIOF                       /* GPIOF */
#define SD_DETECT_GPIO_CLK				RCC_AHB1Periph_GPIOF

#define SDIO_FIFO_ADDRESS				(uint32_t)(SDIO_BASE + 0x80)
/**
  * @brief  SDIO Intialization Frequency (400KHz max)
  */
#define SDIO_INIT_CLK_DIV				((uint8_t)0x76)
/**
  * @brief  SDIO Data Transfer Frequency (25MHz max)
  */
#define SDIO_TRANSFER_CLK_DIV			((uint8_t)0x0)

#define SD_SDIO_DMA						DMA2
#define SD_SDIO_DMA_CLK					RCC_AHB1Periph_DMA2

#define SD_SDIO_DMA_STREAM3				3
//#define SD_SDIO_DMA_STREAM6           6

#ifdef SD_SDIO_DMA_STREAM3
	#define SD_SDIO_DMA_STREAM 			DMA2_Stream3
	#define SD_SDIO_DMA_CHANNEL			DMA_Channel_4
	#define SD_SDIO_DMA_FLAG_FEIF		DMA_FLAG_FEIF3
	#define SD_SDIO_DMA_FLAG_DMEIF		DMA_FLAG_DMEIF3
	#define SD_SDIO_DMA_FLAG_TEIF		DMA_FLAG_TEIF3
	#define SD_SDIO_DMA_FLAG_HTIF		DMA_FLAG_HTIF3
	#define SD_SDIO_DMA_FLAG_TCIF		DMA_FLAG_TCIF3
	#define SD_SDIO_DMA_IRQn			DMA2_Stream3_IRQn
	#define SD_SDIO_DMA_IRQHANDLER		DMA2_Stream3_IRQHandler
#elif defined SD_SDIO_DMA_STREAM6
	#define SD_SDIO_DMA_STREAM			DMA2_Stream6
	#define SD_SDIO_DMA_CHANNEL			DMA_Channel_4
	#define SD_SDIO_DMA_FLAG_FEIF		DMA_FLAG_FEIF6
	#define SD_SDIO_DMA_FLAG_DMEIF		DMA_FLAG_DMEIF6
	#define SD_SDIO_DMA_FLAG_TEIF		DMA_FLAG_TEIF6
	#define SD_SDIO_DMA_FLAG_HTIF		DMA_FLAG_HTIF6
	#define SD_SDIO_DMA_FLAG_TCIF		DMA_FLAG_TCIF6
	#define SD_SDIO_DMA_IRQn			DMA2_Stream6_IRQn
	#define SD_SDIO_DMA_IRQHANDLER		DMA2_Stream6_IRQHandler
#endif /* SD_SDIO_DMA_STREAM3 */

/**
  * @}
  */

/** @addtogroup STM32F4_EVB_LOW_LEVEL_I2C_EE
  * @{
  */
/**
  * @brief  I2C EEPROM Interface pins
  */
#define sEE_I2C							I2C1
#define sEE_I2C_CLK						RCC_APB1Periph_I2C1
#define sEE_I2C_SCL_PIN					GPIO_Pin_6                  /* PB.06 */
#define sEE_I2C_SCL_GPIO_PORT			GPIOB                       /* GPIOB */
#define sEE_I2C_SCL_GPIO_CLK			RCC_AHB1Periph_GPIOB
#define sEE_I2C_SCL_SOURCE				GPIO_PinSource6
#define sEE_I2C_SCL_AF					GPIO_AF_I2C1
#define sEE_I2C_SDA_PIN					GPIO_Pin_9                  /* PB.09 */
#define sEE_I2C_SDA_GPIO_PORT			GPIOB                       /* GPIOB */
#define sEE_I2C_SDA_GPIO_CLK			RCC_AHB1Periph_GPIOB
#define sEE_I2C_SDA_SOURCE				GPIO_PinSource9
#define sEE_I2C_SDA_AF					GPIO_AF_I2C1
#define sEE_M24C64_32

/* Time constant for the delay caclulation allowing to have a millisecond
   incrementing counter. This value should be equal to (System Clock / 1000).
   ie. if system clock = 168MHz then sEE_TIME_CONST should be 168. */
#define sEE_TIME_CONST					168
/**
  * @}
  */
/**
  * @}
  */

/** @defgroup STM32F4_EVB_LOW_LEVEL_Exported_Macros
  * @{
  */
/**
  * @}
  */


/** @defgroup STM32F4_EVB_LOW_LEVEL_Exported_Functions
  * @{
  */
void STM_EVAL_LEDInit(Led_TypeDef Led);
void STM_EVAL_LEDOn(Led_TypeDef Led);
void STM_EVAL_LEDOff(Led_TypeDef Led);
void STM_EVAL_LEDToggle(Led_TypeDef Led);
void STM_EVAL_PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t STM_EVAL_PBGetState(Button_TypeDef Button);
void STM_EVAL_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);
void SD_LowLevel_DeInit(void);
void SD_LowLevel_Init(void);
void SD_LowLevel_DMA_TxConfig(uint32_t *BufferSRC, uint32_t BufferSize);
void SD_LowLevel_DMA_RxConfig(uint32_t *BufferDST, uint32_t BufferSize);
void sEE_LowLevel_DeInit(void);
void sEE_LowLevel_Init(void);
void sEE_LowLevel_DMAConfig(uint32_t pBuffer, uint32_t BufferSize, uint32_t Direction);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4_EVB_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
