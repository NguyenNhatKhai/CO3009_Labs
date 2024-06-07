/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  void display7SEG1(int num) {
	  if (num == 0) {
	 	  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
	  	  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 1) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 2) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 3) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 4) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 5) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 6) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 7) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 8) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 9) {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_RESET);
	  }
	  else {
		  HAL_GPIO_WritePin(SE1_A_GPIO_Port, SE1_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_B_GPIO_Port, SE1_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_C_GPIO_Port, SE1_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_D_GPIO_Port, SE1_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_E_GPIO_Port, SE1_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_F_GPIO_Port, SE1_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE1_G_GPIO_Port, SE1_G_Pin, GPIO_PIN_SET);
	  }
  }
  void display7SEG2(int num) {
	  if (num == 0) {
	 	  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
	  	  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_RESET);
	 	  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 1) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 2) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 3) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 4) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 5) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 6) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 7) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 8) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 9) {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_RESET);
	  }
	  else {
		  HAL_GPIO_WritePin(SE2_A_GPIO_Port, SE2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_B_GPIO_Port, SE2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_C_GPIO_Port, SE2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_D_GPIO_Port, SE2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_E_GPIO_Port, SE2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_F_GPIO_Port, SE2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SE2_G_GPIO_Port, SE2_G_Pin, GPIO_PIN_SET);
	  }
  }
  // Preset LED status (All off)
  HAL_GPIO_WritePin(TR1_R_GPIO_Port, TR1_R_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(TR1_Y_GPIO_Port, TR1_Y_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(TR1_G_GPIO_Port, TR1_G_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(TR2_R_GPIO_Port, TR2_R_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(TR2_Y_GPIO_Port, TR2_Y_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(TR2_G_GPIO_Port, TR2_G_Pin, GPIO_PIN_SET);
  while (1)
  {
	  for (int i = 9; i >= 0; i --) {
		  if (i >= 5) {
			  HAL_GPIO_WritePin(TR1_Y_GPIO_Port, TR1_Y_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(TR1_R_GPIO_Port, TR1_R_Pin, GPIO_PIN_RESET);
			  display7SEG1(i - 5);
		  }
		  else if (i >= 2) {
			  HAL_GPIO_WritePin(TR1_R_GPIO_Port, TR1_R_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(TR1_G_GPIO_Port, TR1_G_Pin, GPIO_PIN_RESET);
			  display7SEG1(i - 2);
		  }
		  else {
			  HAL_GPIO_WritePin(TR1_G_GPIO_Port, TR1_G_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(TR1_Y_GPIO_Port, TR1_Y_Pin, GPIO_PIN_RESET);
			  display7SEG1(i);
		  }
		  if (i >= 7) {
			  HAL_GPIO_WritePin(TR2_R_GPIO_Port, TR2_R_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(TR2_G_GPIO_Port, TR2_G_Pin, GPIO_PIN_RESET);
			  display7SEG2(i - 7);
		  }
		  else if (i >= 5) {
			  HAL_GPIO_WritePin(TR2_G_GPIO_Port, TR2_G_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(TR2_Y_GPIO_Port, TR2_Y_Pin, GPIO_PIN_RESET);
			  display7SEG2(i - 5);
		  }
		  else {
			  HAL_GPIO_WritePin(TR2_Y_GPIO_Port, TR2_Y_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(TR2_R_GPIO_Port, TR2_R_Pin, GPIO_PIN_RESET);
			  display7SEG2(i);
		  }
		  HAL_Delay(1000);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, TR1_R_Pin|TR1_Y_Pin|TR1_G_Pin|SE1_A_Pin
                          |SE1_B_Pin|SE1_C_Pin|SE1_D_Pin|SE1_E_Pin
                          |SE1_F_Pin|SE1_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SE2_B_Pin|SE2_C_Pin|SE2_D_Pin|SE2_E_Pin
                          |SE2_F_Pin|SE2_G_Pin|TR2_R_Pin|TR2_Y_Pin
                          |TR2_G_Pin|SE2_A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : TR1_R_Pin TR1_Y_Pin TR1_G_Pin SE1_A_Pin
                           SE1_B_Pin SE1_C_Pin SE1_D_Pin SE1_E_Pin
                           SE1_F_Pin SE1_G_Pin */
  GPIO_InitStruct.Pin = TR1_R_Pin|TR1_Y_Pin|TR1_G_Pin|SE1_A_Pin
                          |SE1_B_Pin|SE1_C_Pin|SE1_D_Pin|SE1_E_Pin
                          |SE1_F_Pin|SE1_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SE2_B_Pin SE2_C_Pin SE2_D_Pin SE2_E_Pin
                           SE2_F_Pin SE2_G_Pin TR2_R_Pin TR2_Y_Pin
                           TR2_G_Pin SE2_A_Pin */
  GPIO_InitStruct.Pin = SE2_B_Pin|SE2_C_Pin|SE2_D_Pin|SE2_E_Pin
                          |SE2_F_Pin|SE2_G_Pin|TR2_R_Pin|TR2_Y_Pin
                          |TR2_G_Pin|SE2_A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
