/*
 * mode_controller.c
 *
 *  Created on: 11 thg 1, 2023
 *      Author: Nhat Khai
 */

#include "main.h"
#include "button_reading.h"
#include "input_processing.h"
#include "led_display.h"
#include "mode_control.h"
#include "software_timer.h"

enum ButtonState {RELEASE, PRESSED, HOLDING};
enum ButtonState stateBuffer[4] = {PRESSED, PRESSED, PRESSED, PRESSED};

unsigned char mode = 0;

void modeSelection(void) {
	switch (stateBuffer[0]) {
	case RELEASE:
		if (pressedButton(0)) {
			stateBuffer[0] = PRESSED;
			setTimer3();
			resetIndexLED();
			mode ++;
			switch (mode) {
			case 1:
				setTimer0();
				setTimer1();
				resetCounterBuffer();
				break;
			case 2:
			case 3:
			case 4:
				setTimer2();
				setDisplayValue(0, getDurationValue(mode - 2));
				break;
			case 5:
			case 6:
			case 7:
				setTimer2();
				setDisplayValue(1, getDurationValue(mode - 2));
				break;
			default:
				setTimer0();
				setTimer1();
				resetCounterBuffer();
				mode = 1;
				break;
			}
		}
		break;
	case PRESSED:
		if (!pressedButton(0)) {
			stateBuffer[0] = RELEASE;
		}
		break;
	default:
		break;
	}
}

void increaseDurationValue(void) {
	switch (stateBuffer[1]) {
	case RELEASE:
		if (pressedButton(1)) {
			stateBuffer[1] = PRESSED;
			if (mode != 2 && mode != 3 && mode != 4 &&
					mode != 5 && mode != 6 && mode != 7) break;
			setDisplayValue((mode - 2) / 3, getDisplayValue((mode - 2) / 3) + 1);
			if (getDisplayValue((mode - 2) / 3) > 99) {
				setDisplayValue((mode - 2) / 3, 0);
			}
		}
		break;
	case PRESSED:
		if (!pressedButton(1)) {
			stateBuffer[1] = RELEASE;
		}
		else if (holdingButton(1)) {
			stateBuffer[1] = HOLDING;
			setTimer4();
		}
		break;
	case HOLDING:
		if (!pressedButton(1)) {
			stateBuffer[1] = RELEASE;
		}
		if (finishedTimer4()) {
			setTimer4();
			setDisplayValue((mode - 2) / 3, getDisplayValue((mode - 2) / 3) + 1);
			if (getDisplayValue((mode - 2) / 3) > 99) {
				setDisplayValue((mode - 2) / 3, 0);
			}
		}
		break;
	default:
		break;
	}
}

void decreaseDurationValue(void) {
	switch (stateBuffer[2]) {
	case RELEASE:
		if (pressedButton(2)) {
			stateBuffer[2] = PRESSED;
			if (mode != 2 && mode != 3 && mode != 4 &&
					mode != 5 && mode != 6 && mode != 7) break;
			setDisplayValue((mode - 2) / 3, getDisplayValue((mode - 2) / 3) - 1);
			if (getDisplayValue((mode - 2) / 3) < 0) {
				setDisplayValue((mode - 2) / 3, 99);
			}
		}
		break;
	case PRESSED:
		if (!pressedButton(2)) {
			stateBuffer[2] = RELEASE;
		}
		else if (holdingButton(2)) {
			stateBuffer[2] = HOLDING;
			setTimer4();
		}
		break;
	case HOLDING:
		if (!pressedButton(2)) {
			stateBuffer[2] = RELEASE;
		}
		if (finishedTimer4()) {
			setTimer4();
			setDisplayValue((mode - 2) / 3, getDisplayValue((mode - 2) / 3) - 1);
			if (getDisplayValue((mode - 2) / 3) < 0) {
				setDisplayValue((mode - 2) / 3, 99);
			}
		}
		break;
	default:
		break;
	}
}

void setupDurationValue(void) {
	switch (stateBuffer[3]) {
	case RELEASE:
		if (pressedButton(3)) {
			stateBuffer[3] = PRESSED;
			if (mode != 2 && mode != 3 && mode != 4 &&
					mode != 5 && mode != 6 && mode != 7) break;
			setDurationValue(mode - 2, getDisplayValue((mode - 2) / 3));
			HAL_GPIO_WritePin(LOAD_GPIO_Port, LOAD_Pin, GPIO_PIN_RESET);
		}
		break;
	case PRESSED:
		if (!pressedButton(3)) {
			stateBuffer[3] = RELEASE;
			HAL_GPIO_WritePin(LOAD_GPIO_Port, LOAD_Pin, GPIO_PIN_SET);
		}
		break;
	default:
		break;
	}
}

unsigned char getMode(void) {
	return mode;
}
