/*
 * button_reading.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Nhat Khai
 */

#include "main.h"

#define NUMBER_OF_BUTTONS 4
#define DURATION_FOR_AUTO_INCREASING 100
#define PRESS_BUTTON GPIO_PIN_RESET
#define RELEASE_BUTTON GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NUMBER_OF_BUTTONS];
static GPIO_PinState debounceBuffer1[NUMBER_OF_BUTTONS];
static GPIO_PinState debounceBuffer2[NUMBER_OF_BUTTONS];
static unsigned char flagForHoldButtonBuffer[NUMBER_OF_BUTTONS];
static int counterForHoldButtonBuffer[NUMBER_OF_BUTTONS];

void buttonReading(void) {
	for (int i = 0; i < NUMBER_OF_BUTTONS; i ++) {
		debounceBuffer1[i] = debounceBuffer2[i];
		switch (i) {
		case 0:
			debounceBuffer2[i] = HAL_GPIO_ReadPin(BUT_0_GPIO_Port, BUT_0_Pin);
			break;
		case 1:
			debounceBuffer2[i] = HAL_GPIO_ReadPin(BUT_1_GPIO_Port, BUT_1_Pin);
			break;
		case 2:
			debounceBuffer2[i] = HAL_GPIO_ReadPin(BUT_2_GPIO_Port, BUT_2_Pin);
			break;
		case 3:
			debounceBuffer2[i] = HAL_GPIO_ReadPin(BUT_3_GPIO_Port, BUT_3_Pin);
			break;
		default:
			break;
		}
		if (debounceBuffer1[i] == debounceBuffer2[i]) {
			buttonBuffer[i] = debounceBuffer1[i];
		}
		if (buttonBuffer[i] == PRESS_BUTTON) {
			if (counterForHoldButtonBuffer[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForHoldButtonBuffer[i] ++;
			}
			else {
				flagForHoldButtonBuffer[i] = 1;
			}
		}
		else {
			counterForHoldButtonBuffer[i] = 0;
			flagForHoldButtonBuffer[i] = 0;
		}
	}
}

unsigned char pressedButton(int index) {
	if (index < 0 || index >= NUMBER_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == PRESS_BUTTON);
}

unsigned char holdingButton(int index) {
	if (index < 0 || index >= NUMBER_OF_BUTTONS) return 0;
	return (flagForHoldButtonBuffer[index] == 1);
}
