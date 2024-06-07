/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include <stdio.h>
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
const int TIMER_CYCLE = 10;
const int MAX_LED_MATRIX = 8;
const int MATRIX_CYCLE = 100; // divisible by TIMER_CYCLE
const int SHIFT_CYCLE = 1600; // divisible by MATRIX_CYCLE * MAX_LED_MATRIX

int timer0_counter = 0;
int timer0_flag = 0;
void setTimer0(int duration) {
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
}
void runTimer0() {
	if (timer0_counter > 0) {
		timer0_counter --;
		if (timer0_counter == 0) timer0_flag = 1;
	}
}
int timer1_counter = 0;
int timer1_flag = 0;
void setTimer1(int duration) {
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}
void runTimer1() {
	if (timer1_counter > 0) {
		timer1_counter --;
		if (timer1_counter == 0) timer1_flag = 1;
	}
}
int index_led_matrix = 0;
void updateLEDMatrix(int index) {
	switch (index) {
	case 0:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
		break;
	default:
		HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
		break;
	}
}
int matrix_buffer[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
void displayLEDMatrix(int index) {
	if ((matrix_buffer[0][index]) == 1)
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_RESET);
	if ((matrix_buffer[1][index]) == 1)
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_RESET);
	if ((matrix_buffer[2][index]) == 1)
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_RESET);
	if ((matrix_buffer[3][index]) == 1)
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_RESET);
	if ((matrix_buffer[4][index]) == 1)
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, GPIO_PIN_RESET);
	if ((matrix_buffer[5][index]) == 1)
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, GPIO_PIN_RESET);
	if ((matrix_buffer[6][index]) == 1)
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, GPIO_PIN_RESET);
	if ((matrix_buffer[7][index]) == 1)
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, GPIO_PIN_RESET);
	updateLEDMatrix(index);
}
void setMatrixBuffer(int arr[8][8]) {
	for (int i = 0; i < 8; i ++) {
		for (int j = 0; j < 8; j ++) {
			matrix_buffer[i][j] = arr[i][j];
		}
	}
}
void setCharacter(char chr) {
	switch (chr) {
	case '0': {
		int character0[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,1,1,1,0},{0,1,1,1,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(character0);
		break;
	}
	case '1': {
		int character1[8][8] = {{0,0,0,1,1,0,0,0},{0,0,1,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(character1);
		break;
	}
	case '2': {
		int character2[8][8] = {{0,0,1,1,1,1,0,0},{0,1,0,0,0,1,1,0},
				{0,0,0,0,0,1,1,0},{0,0,0,0,0,1,1,0},{0,0,0,0,1,1,0,0},
				{0,0,0,1,1,0,0,0},{0,0,1,1,0,0,0,0},{0,1,1,1,1,1,1,0}};
		setMatrixBuffer(character2);
		break;
	}
	case '3': {
		int character3[8][8] = {{0,0,1,1,1,1,0,0},{0,1,0,0,0,1,1,0},
				{0,0,0,0,0,1,1,0},{0,0,0,1,1,1,0,0},{0,0,0,0,0,1,1,0},
				{0,0,0,0,0,1,1,0},{0,1,0,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(character3);
		break;
	}
	case '4': {
		int character4[8][8] = {{0,0,0,0,1,1,0,0},{0,0,0,1,1,1,0,0},
				{0,0,1,0,1,1,0,0},{0,0,1,0,1,1,0,0},{0,1,0,0,1,1,0,0},
				{0,1,1,1,1,1,1,0},{0,0,0,0,1,1,0,0},{0,0,0,1,1,1,1,0}};
		setMatrixBuffer(character4);
		break;
	}
	case '5': {
		int character5[8][8] = {{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},
				{0,1,1,1,1,1,0,0},{0,1,0,0,0,1,1,0},{0,0,0,0,0,1,1,0},
				{0,0,0,0,0,1,1,0},{0,1,0,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(character5);
		break;
	}
	case '6': {
		int character6[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,0,1,0},
				{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(character6);
		break;
	}
	case '7': {
		int character7[8][8] = {{0,1,1,1,1,1,1,0},{0,1,0,0,0,1,1,0},
				{0,0,0,0,1,1,0,0},{0,0,0,0,1,1,0,0},{0,0,0,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,1,1,0,0,0,0},{0,0,1,1,0,0,0,0}};
		setMatrixBuffer(character7);
		break;
		}
	case '8': {
		int character8[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(character8);
			break;
		}
	case '9': {
		int character9[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,1,0},
				{0,0,0,0,0,1,1,0},{0,1,0,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(character9);
		break;
	}
	case 'A': {
		int characterA[8][8] = {{0,0,0,1,1,0,0,0},{0,0,1,0,0,1,0,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0}};
		setMatrixBuffer(characterA);
		break;
	}
	case 'B': {
		int characterB[8][8] = {{0,1,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,0,0}};
		setMatrixBuffer(characterB);
		break;
	}
	case 'C': {
		int characterC[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(characterC);
		break;
	}
	case 'D': {
		int characterD[8][8] = {{0,1,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,0,0}};
		setMatrixBuffer(characterD);
		break;
	}
	case 'E': {
		int characterE[8][8] = {{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},
				{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,1,0,0,0,0,0},
				{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,0}};
		setMatrixBuffer(characterE);
		break;
	}
	case 'F': {
		int characterE[8][8] = {{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},
				{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,1,0,0,0,0,0},
				{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0}};
		setMatrixBuffer(characterE);
		break;
	}
	case 'G': {
		int characterG[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,0,1,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(characterG);
		break;
	}
	case 'H': {
		int characterH[8][8] = {{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0}};
		setMatrixBuffer(characterH);
		break;
	}
	case 'I': {
		int characterI[8][8] = {{0,0,1,1,1,1,0,0},{0,0,0,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(characterI);
		break;
	}
	case 'J': {
		int characterJ[8][8] = {{0,0,0,0,0,1,1,0},{0,0,0,0,0,1,1,0},
				{0,0,0,0,0,1,1,0},{0,0,0,0,0,1,1,0},{0,0,0,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(characterJ);
		break;
	}
	case 'K': {
		int characterK[8][8] = {{0,1,1,0,0,0,1,0},{0,1,1,0,0,1,0,0},
				{0,1,1,0,1,0,0,0},{0,1,1,1,0,0,0,0},{0,1,1,0,1,0,0,0},
				{0,1,1,0,0,1,0,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0}};
		setMatrixBuffer(characterK);
		break;
	}
	case 'L': {
		int characterL[8][8] = {{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},
				{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},
				{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,0}};
		setMatrixBuffer(characterL);
		break;
	}
	case 'M': {
		int characterM[8][8] = {{1,1,0,0,0,0,1,1},{1,1,1,0,0,1,1,1},
				{1,1,0,1,1,0,1,1},{1,1,0,0,0,0,1,1},{1,1,0,0,0,0,1,1},
				{1,1,0,0,0,0,1,1},{1,1,0,0,0,0,1,1},{1,1,0,0,0,0,1,1}};
		setMatrixBuffer(characterM);
		break;
	}
	case 'N': {
		int characterN[8][8] = {{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,1,0,1,1,0},{0,1,1,0,1,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0}};
		setMatrixBuffer(characterN);
		break;
	}
	case 'O': {
		int characterO[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(characterO);
		break;
	}
	case 'P': {
		int characterP[8][8] = {{0,1,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,0,0},
				{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0}};
		setMatrixBuffer(characterP);
		break;
	}
	case 'Q': {
		int characterQ[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,1,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,1}};
		setMatrixBuffer(characterQ);
		break;
	}
	case 'R': {
		int characterR[8][8] = {{0,1,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,0,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0}};
		setMatrixBuffer(characterR);
		break;
	}
	case 'S': {
		int characterS[8][8] = {{0,0,1,1,1,1,0,0},{0,1,1,0,0,0,1,0},
				{0,1,1,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,1,1,0},
				{0,0,0,0,0,1,1,0},{0,1,0,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(characterS);
		break;
	}
	case 'T': {
		int characterT[8][8] = {{0,1,1,1,1,1,1,0},{0,0,0,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0}};
		setMatrixBuffer(characterT);
		break;
	}
	case 'U': {
		int characterU[8][8] = {{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0}};
		setMatrixBuffer(characterU);
		break;
	}
	case 'V': {
		int characterV[8][8] = {{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,0,1,0,0,1,0,0},{0,0,0,1,1,0,0,0}};
		setMatrixBuffer(characterV);
		break;
	}
	case 'W': {
		int characterW[8][8] = {{1,1,0,0,0,0,1,1},{1,1,0,0,0,0,1,1},
				{1,1,0,1,1,0,1,1},{1,1,0,1,1,0,1,1},{1,1,0,1,1,0,1,1},
				{1,1,0,1,1,0,1,1},{1,1,1,0,0,1,1,1},{0,1,0,0,0,0,1,0}};
		setMatrixBuffer(characterW);
		break;
	}
	case 'X': {
		int characterX[8][8] = {{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,0,1,0,0,1,0,0},{0,0,0,1,1,0,0,0},{0,0,1,0,0,1,0,0},
				{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0}};
		setMatrixBuffer(characterX);
		break;
	}
	case 'Y': {
		int characterY[8][8] = {{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},
				{0,1,1,0,0,1,1,0},{0,0,1,0,0,1,0,0},{0,0,0,1,1,0,0,0},
				{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0}};
		setMatrixBuffer(characterY);
		break;
	}
	case 'Z': {
		int characterZ[8][8] = {{0,1,1,1,1,1,1,0},{0,0,0,0,0,1,1,0},
				{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,0},
				{0,0,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,0}};
		setMatrixBuffer(characterZ);
		break;
	}
	default:
		break;
	}
}
void shiftLeft() {
	int temp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	for (int i = 0; i < 8; i ++) {
		temp[i] = matrix_buffer[i][0];
	}
	for (int i = 0; i < 8; i ++) {
		for (int j = 0; j < 7; j ++) {
			matrix_buffer[i][j] = matrix_buffer[i][j+1];
		}
	}
	for (int i = 0; i < 8; i ++) {
		matrix_buffer[i][7] = temp[i];
	}
}
void shiftRight() {
	int temp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	for (int i = 0; i < 8; i ++) {
		temp[i] = matrix_buffer[i][7];
	}
	for (int i = 0; i < 8; i ++) {
		for (int j = 7; j > 0; j --) {
			matrix_buffer[i][j] = matrix_buffer[i][j-1];
		}
	}
	for (int i = 0; i < 8; i ++) {
		matrix_buffer[i][0] = temp[i];
	}
}
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
  setTimer0(MATRIX_CYCLE);
  setTimer1(SHIFT_CYCLE);
  setCharacter('H');
  while (1)
  {
	  displayLEDMatrix(index_led_matrix);
	  if (timer0_flag == 1) {
		  index_led_matrix ++;
		  if (index_led_matrix >= MAX_LED_MATRIX) index_led_matrix = 0;
		  setTimer0(MATRIX_CYCLE);
	  }
	  if (timer1_flag == 1) {
		  shiftRight();
		  setTimer1(SHIFT_CYCLE);
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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ENM0_Pin|ENM1_Pin|ENM2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin ENM2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|ENM2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef *htim) {
	runTimer0();
	runTimer1();
}
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
