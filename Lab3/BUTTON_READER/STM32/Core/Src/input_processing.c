/*
 * input_processing.c
 *
 *  Created on: Jan 5, 2023
 *      Author: Nhat Khai
 */

#include "input_processing.h"
#include "input_reading.h"
#include "led_display.h"
#include "timer.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[4] =
		{BUTTON_PRESSED, BUTTON_PRESSED, BUTTON_PRESSED, BUTTON_PRESSED};

int led_buffer[4] = {0,0,0,0};

void fsm_for_input_processing(void) {
	display7SEGs();
	for (int i = 0; i < 4; i ++) {
		switch (buttonState[i]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(i)) {
				buttonState[i] = BUTTON_PRESSED;
				led_buffer[i] ++;
				if (led_buffer[i] > 9) led_buffer[i] = 0;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(i)) {
				buttonState[i] = BUTTON_RELEASED;
			}
			else {
				if (is_button_pressed_1s(i)) {
					buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
					setTimer0();
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(i)) {
				buttonState[i] = BUTTON_RELEASED;
			}
			if (flagTimer0()) {
				led_buffer[i] ++;
				if (led_buffer[i] > 9) led_buffer[i] = 0;
				setTimer0();
			}
			break;
		default:
			break;
		}
	}
//	update7SEG(0);
//	switch(buttonState) {
//	case BUTTON_RELEASED:
//		if (is_button_pressed(0)) {
//			buttonState = BUTTON_PRESSED;
//			led_buffer[0] ++;
//			if (led_buffer[0] > 9) led_buffer[0] = 0;
//		}
//		break;
//	case BUTTON_PRESSED:
//		if (!is_button_pressed(0)) {
//			buttonState = BUTTON_RELEASED;
//		}
//		else {
//			if (is_button_pressed_1s(0)) {
//				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
//				setTimer0();
//			}
//		}
//		break;
//	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
//		if (!is_button_pressed(0)) {
//			buttonState = BUTTON_RELEASED;
//		}
//		if (flagTimer0()) {
//			led_buffer[0] ++;
//			if (led_buffer[0] > 9) led_buffer[0] = 0;
//			setTimer0();
//		}
//		break;
//	}
}
