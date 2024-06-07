/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TR1_R_Pin GPIO_PIN_6
#define TR1_R_GPIO_Port GPIOA
#define TR1_Y_Pin GPIO_PIN_7
#define TR1_Y_GPIO_Port GPIOA
#define SE2_B_Pin GPIO_PIN_10
#define SE2_B_GPIO_Port GPIOB
#define SE2_C_Pin GPIO_PIN_11
#define SE2_C_GPIO_Port GPIOB
#define SE2_D_Pin GPIO_PIN_12
#define SE2_D_GPIO_Port GPIOB
#define SE2_E_Pin GPIO_PIN_13
#define SE2_E_GPIO_Port GPIOB
#define SE2_F_Pin GPIO_PIN_14
#define SE2_F_GPIO_Port GPIOB
#define SE2_G_Pin GPIO_PIN_15
#define SE2_G_GPIO_Port GPIOB
#define TR1_G_Pin GPIO_PIN_8
#define TR1_G_GPIO_Port GPIOA
#define SE1_A_Pin GPIO_PIN_9
#define SE1_A_GPIO_Port GPIOA
#define SE1_B_Pin GPIO_PIN_10
#define SE1_B_GPIO_Port GPIOA
#define SE1_C_Pin GPIO_PIN_11
#define SE1_C_GPIO_Port GPIOA
#define SE1_D_Pin GPIO_PIN_12
#define SE1_D_GPIO_Port GPIOA
#define SE1_E_Pin GPIO_PIN_13
#define SE1_E_GPIO_Port GPIOA
#define SE1_F_Pin GPIO_PIN_14
#define SE1_F_GPIO_Port GPIOA
#define SE1_G_Pin GPIO_PIN_15
#define SE1_G_GPIO_Port GPIOA
#define TR2_R_Pin GPIO_PIN_6
#define TR2_R_GPIO_Port GPIOB
#define TR2_Y_Pin GPIO_PIN_7
#define TR2_Y_GPIO_Port GPIOB
#define TR2_G_Pin GPIO_PIN_8
#define TR2_G_GPIO_Port GPIOB
#define SE2_A_Pin GPIO_PIN_9
#define SE2_A_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
