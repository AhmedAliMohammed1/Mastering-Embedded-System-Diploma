/*
 * LCD_I2C.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed
 */

#ifndef LCD_I2C_H_
#define LCD_I2C_H_
#include "i2c.h"
#include <util/delay.h>

#define SLA 0b0111000
#define RS	0
#define RW	1
#define EN	2
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define FOUR_BIT_MODE

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80


void I2C_LCD_sendCommand(unsigned char command);
void I2C_LCD_sendCharcter(char data);
void I2C_LCD_init();
void I2C_LCD_sendString(char *data);
void I2C_LCD_moveCURSER(unsigned char row,unsigned char col);
void I2C_LCD_clearScreen();
void I2C_LCD_intgerToString(unsigned int num);
#endif /* LCD_I2C_H_ */
