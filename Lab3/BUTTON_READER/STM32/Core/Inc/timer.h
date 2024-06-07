/*
 * timer.h
 *
 *  Created on: 5 thg 1, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

extern int timer0_flag;

void setTimer0(void);
void runTimer0(void);
unsigned char flagTimer0(void);
void setTimer1(void);
void runTimer1(void);
unsigned char flagTimer1(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_TIMER_H_ */
