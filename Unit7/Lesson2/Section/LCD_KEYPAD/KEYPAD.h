/*
 * KEYPAD.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "avr/io.h"
#define KEYPAD_DIR DDRD
#define KEYPAD_PORT	PORTD
#define KEYPAD_PIN	PIND
#define ROW_N 4
#define COL_N 4
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

unsigned char Get_Pressed_KEY(void);
void KEYPAD_init();
#endif /* KEYPAD_H_ */
