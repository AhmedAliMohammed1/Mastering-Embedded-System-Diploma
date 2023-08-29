/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ahmed
 */

#include "TC74.h"
#include "lcd.h"
#include <util/delay.h>
#define F_CPU 8000000UL
void main(void){
	unsigned char i=0;
	I2C_init();
	LCD_init();
	LCD_sendString("TC74:   C");
	TC74_WRITE_ON_REG(0x01,0x00);
//	I2C_PACKET_TRANSSEMET(0x4D,0x01,0x00);
//	I2C_PACKET_TRANSSEMET(0x4D,0x00,0x00);
	while(1){
//		I2C_PACKET_TRANSSEMET(0x4D,0x00,0x00);
		TC74_Read_TEMP(&i);
		if(i<10){
			LCD_moveCURSER(0, 6);
			LCD_sendCharcter(' ');
		}
		if(i<100){
			LCD_moveCURSER(0, 7);
			LCD_sendCharcter(' ');

		}
		LCD_moveCURSER(0, 5);
		LCD_intgerToString(i);
		_delay_ms(1000);

	}

}



