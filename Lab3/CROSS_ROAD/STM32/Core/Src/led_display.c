/*
 * led_display.c
 *
 *  Created on: 6 thg 1, 2023
 *      Author: Nhat Khai
 */

#include "main.h"
#include "button_reading.h"
#include "input_processing.h"
#include "led_display.h"
#include "mode_control.h"
#include "software_timer.h"

void displayNumber(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
	  	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
	 	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
	 	break;
	case 1:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	default:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		break;
	}
}

void displayLED(int index) {
	switch (index) {
	case 0:
		displayNumber(getMode());
		HAL_GPIO_WritePin(EN_MODE_GPIO_Port, EN_MODE_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_7S1_GPIO_Port, EN1_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S2_GPIO_Port, EN1_7S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S1_GPIO_Port, EN2_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S2_GPIO_Port, EN2_7S2_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		displayNumber(getDisplayValue(0) / 10);
		HAL_GPIO_WritePin(EN_MODE_GPIO_Port, EN_MODE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S1_GPIO_Port, EN1_7S1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_7S2_GPIO_Port, EN1_7S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S1_GPIO_Port, EN2_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S2_GPIO_Port, EN2_7S2_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		displayNumber(getDisplayValue(0) % 10);
		HAL_GPIO_WritePin(EN_MODE_GPIO_Port, EN_MODE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S1_GPIO_Port, EN1_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S2_GPIO_Port, EN1_7S2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_7S1_GPIO_Port, EN2_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S2_GPIO_Port, EN2_7S2_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		displayNumber(getDisplayValue(1) / 10);
		HAL_GPIO_WritePin(EN_MODE_GPIO_Port, EN_MODE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S1_GPIO_Port, EN1_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S2_GPIO_Port, EN1_7S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S1_GPIO_Port, EN2_7S1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_7S2_GPIO_Port, EN2_7S2_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		displayNumber(getDisplayValue(1) % 10);
		HAL_GPIO_WritePin(EN_MODE_GPIO_Port, EN_MODE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S1_GPIO_Port, EN1_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_7S2_GPIO_Port, EN1_7S2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S1_GPIO_Port, EN2_7S1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_7S2_GPIO_Port, EN2_7S2_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}

int indexLED = 0;
void displayController(void) {
	displayLED(indexLED);
	if (finishedTimer3()) {
		setTimer3();
		switch (getMode()) {
		case 1:
			indexLED ++;
			if (indexLED > 4) indexLED = 0;
			break;
		case 2:
		case 3:
		case 4:
			indexLED ++;
			if (indexLED > 2) indexLED = 0;
			break;
		case 5:
		case 6:
		case 7:
			if (indexLED == 0) indexLED = 3;
			else {
				indexLED ++;
				if (indexLED > 4) indexLED = 0;
			}
			break;
		default:
			break;
		}
	}
}
void resetIndexLED(void) {
	indexLED = 0;
}
