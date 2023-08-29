/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ahmed
 */

#include "TC74.h"
#include "LCD_I2C.h"
#include <util/delay.h>
#define F_CPU 8000000UL
void main(void){
	unsigned char i=0,LED=0x0F;
	I2C_init();
	I2C_LCD_init();
	I2C_LCD_sendString("TC74:   C");
	TC74_WRITE_ON_REG(0x01,0x00);
//	I2C_PACKET_TRANSSEMET(0b0111000,LED);
//	I2C_PACKET_TRANSSEMET(0x4D,0x00,0x00);
	while(1){
//		LED^=0xFF;
//		I2C_PACKET_TRANSSEMET(0b0111000,LED);
//		I2C_PACKET_TRANSSEMET(0x4D,0x00,0x00);
		TC74_Read_TEMP(&i);
		if(i<10){
			I2C_LCD_moveCURSER(0, 6);
			I2C_LCD_sendCharcter(' ');
		}
		if(i<100){
			I2C_LCD_moveCURSER(0, 7);
			I2C_LCD_sendCharcter(' ');

		}
		I2C_LCD_moveCURSER(0, 5);
		I2C_LCD_intgerToString(i);
		_delay_ms(1000);

	}

}



