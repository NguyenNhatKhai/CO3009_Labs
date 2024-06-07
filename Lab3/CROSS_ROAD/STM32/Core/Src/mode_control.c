/*
 * data_processing.c
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

// For all mode
int durationBuffer[6] = {5,5,5,5,5,5};
int displayBuffer[2] = {1,1};

void setDurationValue(int index, int value) {
	durationBuffer[index] = value;
}
int getDurationValue(int index) {
	return durationBuffer[index];
}
void setDisplayValue(int index, int value) {
	displayBuffer[index] = value;
}
int getDisplayValue(int index) {
	return displayBuffer[index];
}

// For mode 1
int counterBuffer[6] = {5,5,5,5,5,5};
void resetCounterBuffer1(void) {
	for (int i = 0; i < 3; i ++) {
		counterBuffer[i] = durationBuffer[i];
	}
}
void resetCounterBuffer2(void) {
	for (int i = 3; i < 6; i ++) {
		counterBuffer[i] = durationBuffer[i];
	}
}
void resetCounterBuffer(void) {
	resetCounterBuffer1();
	resetCounterBuffer2();
}

// Processing
void dataProcessing(void) {
	displayController();
	modeSelection();
	increaseDurationValue();
	decreaseDurationValue();
	setupDurationValue();
	switch (getMode()) {
	case 1:
		if (counterBuffer[2] > 0) {
			HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_RESET);
			displayBuffer[0] = counterBuffer[2];
			if (finishedTimer0()) {
				setTimer0();
				counterBuffer[2] --;
			}
		}
		else if (counterBuffer[1] > 0) {
			HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_SET);
			displayBuffer[0] = counterBuffer[1];
			if (finishedTimer0()) {
				setTimer0();
				counterBuffer[1] --;
			}
		}
		else if (counterBuffer[0] > 0) {
			HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_SET);
			displayBuffer[0] = counterBuffer[0];
			if (finishedTimer0()) {
				setTimer0();
				counterBuffer[0] --;
			}
		}
		else {
			resetCounterBuffer1();
		}
		if (counterBuffer[3] > 0) {
			HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_SET);
			displayBuffer[1] = counterBuffer[3];
			if (finishedTimer1()) {
				setTimer1();
				counterBuffer[3] --;
			}
		}
		else if (counterBuffer[5] > 0) {
			HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_RESET);
			displayBuffer[1] = counterBuffer[5];
			if (finishedTimer1()) {
				setTimer1();
				counterBuffer[5] --;
			}
		}
		else if (counterBuffer[4] > 0) {
			HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_SET);
			displayBuffer[1] = counterBuffer[4];
			if (finishedTimer1()) {
				setTimer1();
				counterBuffer[4] --;
			}
		}
		else {
			resetCounterBuffer2();
		}
		break;
	case 2:
		HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_SET);
		if (finishedTimer2()) {
			setTimer2();
			HAL_GPIO_TogglePin(EN1_RED_GPIO_Port, EN1_RED_Pin);
		}
		break;
	case 3:
		HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_SET);
		if (finishedTimer2()) {
			setTimer2();
			HAL_GPIO_TogglePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin);
		}
		break;
	case 4:
		HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_SET);
		if (finishedTimer2()) {
			setTimer2();
			HAL_GPIO_TogglePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin);
		}
		break;
	case 5:
		HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_SET);
		if (finishedTimer2()) {
			setTimer2();
			HAL_GPIO_TogglePin(EN2_RED_GPIO_Port, EN2_RED_Pin);
		}
		break;
	case 6:
		HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin, GPIO_PIN_SET);
		if (finishedTimer2()) {
			setTimer2();
			HAL_GPIO_TogglePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin);
		}
		break;
	case 7:
		HAL_GPIO_WritePin(EN1_RED_GPIO_Port, EN1_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_AMB_GPIO_Port, EN1_AMB_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GRE_GPIO_Port, EN1_GRE_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_RED_GPIO_Port, EN2_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_AMB_GPIO_Port, EN2_AMB_Pin, GPIO_PIN_SET);
		if (finishedTimer2()) {
			setTimer2();
			HAL_GPIO_TogglePin(EN2_GRE_GPIO_Port, EN2_GRE_Pin);
		}
		break;
	default:
		break;
	}
}
