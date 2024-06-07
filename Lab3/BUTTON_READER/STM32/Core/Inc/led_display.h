/*
 * led_display.h
 *
 *  Created on: 5 thg 1, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

extern int led_buffer[4];
void display7SEG(int num);
void update7SEG(int index);
void display7SEGs(void);

#endif /* INC_LED_DISPLAY_H_ */
