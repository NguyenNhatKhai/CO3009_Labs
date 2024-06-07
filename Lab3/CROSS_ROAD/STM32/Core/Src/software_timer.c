/*
 * software_timer.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Nhat Khai
 */

#include "main.h"
#include "button_reading.h"
#include "input_processing.h"
#include "led_display.h"
#include "mode_control.h"
#include "software_timer.h"

#define TIMER_CYCLE 10
#define LED_BLINKY_CYCLE 500
#define LED7SEG_CYCLE 1000
#define AUTO_MODIFY_CYCLE 500

int timer0_counter = 0;
int timer0_flag = 0;
void setTimer0(void) {
	timer0_counter = 1000 / TIMER_CYCLE;
	timer0_flag = 0;
}
void runTimer0(void) {
	if (timer0_counter > 0) {
		timer0_counter --;
		if (timer0_counter == 0) timer0_flag = 1;
	}
}
unsigned char finishedTimer0(void) {
	return (timer0_flag == 1);
}

int timer1_counter = 0;
int timer1_flag = 0;
void setTimer1(void) {
	timer1_counter = 1000 / TIMER_CYCLE;
	timer1_flag = 0;
}
void runTimer1(void) {
	if (timer1_counter > 0) {
		timer1_counter --;
		if (timer1_counter == 0) timer1_flag = 1;
	}
}
unsigned char finishedTimer1(void) {
	return (timer1_flag == 1);
}

int timer2_counter = 0;
int timer2_flag = 0;
void setTimer2(void) {
	timer2_counter = LED_BLINKY_CYCLE / TIMER_CYCLE;
	timer2_flag = 0;
}
void runTimer2(void) {
	if (timer2_counter > 0) {
		timer2_counter --;
		if (timer2_counter == 0) timer2_flag = 1;
	}
}
unsigned char finishedTimer2(void) {
	return (timer2_flag == 1);
}

int timer3_counter = 0;
int timer3_flag = 0;
void setTimer3(void) {
	timer3_counter = LED7SEG_CYCLE / TIMER_CYCLE;
	timer3_flag = 0;
}
void runTimer3(void) {
	if (timer3_counter > 0) {
		timer3_counter --;
		if (timer3_counter == 0) timer3_flag = 1;
	}
}
unsigned char finishedTimer3(void) {
	return (timer3_flag == 1);
}

int timer4_counter = 0;
int timer4_flag = 0;
void setTimer4(void) {
	timer4_counter = AUTO_MODIFY_CYCLE / TIMER_CYCLE;
	timer4_flag = 0;
}
void runTimer4(void) {
	if (timer4_counter > 0) {
		timer4_counter --;
		if (timer4_counter == 0) timer4_flag = 1;
	}
}
unsigned char finishedTimer4(void) {
	return (timer4_flag == 1);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	runTimer0();
	runTimer1();
	runTimer2();
	runTimer3();
	runTimer4();
	if (htim -> Instance == TIM2) {
		buttonReading();
	}
}
