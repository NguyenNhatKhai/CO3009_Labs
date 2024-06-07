/*
 * timer.c
 *
 *  Created on: Jan 5, 2023
 *      Author: Nhat Khai
 */

#include "timer.h"
#include "input_reading.h"

const int TIMER_CYCLE = 10;
const int INCREASING_CYCLE = 500;
const int LED7SEG_CYCLE = 250;

int timer0_counter = 0;
int timer0_flag = 0;
void setTimer0(void) {
	timer0_counter = INCREASING_CYCLE / TIMER_CYCLE;
	timer0_flag = 0;
}
void runTimer0(void) {
	if (timer0_counter > 0) {
		timer0_counter --;
		if (timer0_counter == 0) timer0_flag = 1;
	}
}
unsigned char flagTimer0(void) {
	return (timer0_flag == 1);
}

int timer1_counter = 0;
int timer1_flag = 0;
void setTimer1(void) {
	timer1_counter = LED7SEG_CYCLE / TIMER_CYCLE;
	timer1_flag = 0;
}
void runTimer1(void) {
	if (timer1_counter > 0) {
		timer1_counter --;
		if (timer1_counter == 0) timer1_flag = 1;
	}
}
unsigned char flagTimer1(void) {
	return (timer1_flag == 1);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	runTimer0();
	runTimer1();
	if (htim -> Instance == TIM2) {
		button_reading();
	}
}
