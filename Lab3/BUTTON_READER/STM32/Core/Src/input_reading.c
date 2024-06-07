/*
 * input_reading.c
 *
 *  Created on: Jan 5, 2023
 *      Author: Nhat Khai
 */

#include "input_reading.h"

#define NUMBER_OF_BUTTONS 4
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NUMBER_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NUMBER_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NUMBER_OF_BUTTONS];
static uint8_t flagForButtonPress1s[NUMBER_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NUMBER_OF_BUTTONS];

void button_reading(void) {
	for (int i = 0; i < NUMBER_OF_BUTTONS; i ++) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		switch (i) {
		case 0:
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUT0_GPIO_Port, BUT0_Pin);
			break;
		case 1:
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);
			break;
		case 2:
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin);
			break;
		case 3:
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin);
			break;
		default:
			break;
		}
		if (debounceButtonBuffer2[i] == debounceButtonBuffer1[i]) {
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForButtonPress1s[i] ++;
			}
			else {
				flagForButtonPress1s[i] = 1;
			}
		}
		else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

unsigned char is_button_pressed(uint8_t index) {
	if (index >= NUMBER_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(uint8_t index) {
	if (index >= NUMBER_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}
