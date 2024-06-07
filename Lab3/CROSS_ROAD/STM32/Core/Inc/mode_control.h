/*
 * data_processing.h
 *
 *  Created on: 6 thg 1, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_DATA_PROCESSING_H_
#define INC_DATA_PROCESSING_H_

void setDurationValue(int index, int value);
int getDurationValue(int index);
void setDisplayValue(int index, int value);
int getDisplayValue(int index);

void resetCounterBuffer1(void);
void resetCounterBuffer2(void);
void resetCounterBuffer(void);

void dataProcessing(void);

#endif /* INC_DATA_PROCESSING_H_ */
