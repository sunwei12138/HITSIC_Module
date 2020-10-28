/**
 * Copyright 2018 - 2020 HITSIC
 * All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef D_MK66F18_HITSIC_COMMON_H_
#define D_MK66F18_HITSIC_COMMON_H_

#include "inc_fsl_mk66f18.h"
#include "stdint.h"

/**
 * @brief : 软件版本产生方式定义
 */
#define HITSIC_MAKE_VERSION(major, minor, patch) (((major) << 16) | ((minor) << 8) | (patch))



#ifndef HITSIC_USE_FTFX_FLASH
#define HITSIC_USE_FTFX_FLASH (1U)
#endif // ! HITSIC_USE_FTFX_FLASH

#ifndef HITSIC_USE_DRV_IMU
#define HITSIC_USE_DRV_IMU (0U)
#endif // ! HITSIC_USE_DRV_IMU

#ifndef HITSIC_USE_DISP_SSD1306
#define HITSIC_USE_DISP_SSD1306 (1U)
#endif // ! HITSIC_USE_DISP_SSD1306

#ifndef HITSIC_USE_DISP_ST7789
#define HITSIC_USE_DISP_ST7789 (0U)
#endif // ! HITSIC_USE_DISP_ST7789

#ifndef HITSIC_USE_DRV_BUTTON
#define HITSIC_USE_DRV_BUTTON (1U)
#endif // ! HITSIC_USE_DRV_BUTTON

#ifndef HITSIC_USE_DMADVP
#define HITSIC_USE_DMADVP (1U)
#endif // ! HITSIC_USE_DMADVP

#ifndef HITSIC_USE_CAM_ZF9V034
#define HITSIC_USE_CAM_ZF9V034 (1U)
#endif // ! HITSIC_USE_CAM_ZF9V034





#ifndef HITSIC_USE_PITMGR
#define HITSIC_USE_PITMGR 		(1U)
#endif // ! HITSIC_USE_PITMGR

#ifndef HITSIC_USE_EXTINT
#define HITSIC_USE_EXTINT 		(1U)
#endif // ! HITSIC_USE_EXTINT

#ifndef HITSIC_USE_UARTMGR
#define HITSIC_USE_UARTMGR 		(0U)
#endif // ! HITSIC_USE_UARTMGR

#ifndef HITSIC_USE_RMCALL
#define HITSIC_USE_RMCALL 		(0U)
#endif // ! HITSIC_USE_RMCALL



#ifndef HITSIC_USE_APP_MENU
#define HITSIC_USE_APP_MENU (1U)
#endif // ! HITSIC_USE_APP_MENU

#ifndef HITSIC_USE_APP_SVBMP
#define HITSIC_USE_APP_SVBMP (1U)
#endif // ! HITSIC_USE_APP_SVBMP





typedef I2C_Type HAL_I2C_Type;
typedef SPI_Type HAL_SPI_Type;
typedef UART_Type HAL_UART_Type;

#ifdef __cplusplus
extern "C"{
#endif

//TODO: update this to save primask.
extern uint32_t hal_criticalCnt;

inline void HAL_EnterCritical(void)
{
	if(0u == hal_criticalCnt++)
	{
		__disable_irq();
	}
}

inline void HAL_ExitCritical(void)
{
	if(--hal_criticalCnt == 0u)
	{
		__enable_irq();
	}
}



//I2C MEM Wrapper

status_t HAL_I2C_Mem_ReadBlocking(HAL_I2C_Type *_i2c, uint8_t _addr, uint32_t _reg, uint8_t _regSize, uint8_t* _data, uint32_t _dataSize);
status_t HAL_I2C_Mem_WriteBlocking(HAL_I2C_Type *_i2c, uint8_t _addr, uint32_t _reg, uint8_t _regSize, uint8_t* _data, uint32_t _dataSize);

    
#ifdef __cplusplus
}
#endif

#endif // ! D_MK66F18_HITSIC_COMMON_H_
