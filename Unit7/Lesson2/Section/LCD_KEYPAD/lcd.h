/*
 * lcd.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */

#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#include <util/delay.h>
#define DATA_PORT	PORTA
#define DATA_DIR DDRA
#define CTRL_DIR DDRB
#define CTRL_PORT PORTB
#define RS	1
#define RW	2
#define EN	3

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE
/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80
void LCD_sendCommand(unsigned char command);
void LCD_sendCharcter(char data);
void LCD_init();
void LCD_sendString(char *data);
void LCD_moveCURSER(unsigned char row,unsigned char col);
void LCD_clearScreen();
#endif /* LCD_H_ */
