/*
 * KEYPAD.h
 *
 *  Created on: Aug 2, 2023
 *      Author: Ahmed
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include "GPIO_Driver.h"

unsigned char Get_Pressed_KEY(void);
void KEYPAD_init();
////////////////////////////////////////////////
#define KEYPAD_PORT	GPIOA
#define Row_N 4
#define Col_N 4
#define R0 PIN_0
#define R1 PIN_1
#define R2 PIN_2
#define R3 PIN_3
#define C0 PIN_4
#define C1 PIN_5
#define C2 PIN_6
#define C3 PIN_7
#define BIT_IS_SET(REG,num) ((REG & (1<<num)))


#endif /* INC_KEYPAD_H_ */
