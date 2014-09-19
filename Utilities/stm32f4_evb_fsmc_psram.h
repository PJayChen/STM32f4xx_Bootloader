/**
  ******************************************************************************
  * @file    stm32f4_evb_fsmc_psram.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-March-2013
  * @brief   This file contains all the functions prototypes for the 
  *          stm32f4_evb_fsmc_psram.c driver.
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
#ifndef __STM32F4_EVB_FSMC_PSRAM_H
#define __STM32F4_EVB_FSMC_PSRAM_H

#ifdef __cplusplus
	extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4_evb.h"

/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM32F4_EVB
  * @{
  */
  
/** @addtogroup STM32F4_EVB_FSMC_PSRAM
  * @{
  */  

/** @defgroup STM32F4_EVB_FSMC_PSRAM_Exported_Types
  * @{
  */
/**
  * @}
  */
  
/** @defgroup STM32F4_EVB_FSMC_PSRAM_Exported_Constants
  * @{
  */ 
/**
  * @}
  */ 
  
/** @defgroup STM32F4_EVB_FSMC_PSRAM_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup STM32F4_EVB_FSMC_PSRAM_Exported_Functions
  * @{
  */      

void PSRAM_Init(void);
void PSRAM_WriteBuffer(uint16_t* pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite);
void PSRAM_ReadBuffer(uint16_t* pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4_EVB_FSMC_PSRAM_H */
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

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
