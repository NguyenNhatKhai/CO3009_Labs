/*
 * software_timer.h
 *
 *  Created on: 6 thg 1, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

void setTimer0(void);
void runTimer0(void);
unsigned char finishedTimer0(void);

void setTimer1(void);
void runTimer1(void);
unsigned char finishedTimer1(void);

void setTimer2(void);
void runTimer2(void);
unsigned char finishedTimer2(void);

void setTimer3(void);
void runTimer3(void);
unsigned char finishedTimer3(void);

void setTimer4(void);
void runTimer4(void);
unsigned char finishedTimer4(void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_SOFTWARE_TIMER_H_ */
