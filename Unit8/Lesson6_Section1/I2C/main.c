/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ahmed
 */

#include "i2c.h"
#include <util/delay.h>
#define F_CPU 8000000UL
void main(void){
	unsigned char i=0;
	I2C_init();

	DDRA=0xFF;
	while(1){
//			Master_Recive_Data(0x03,&PORTA);
			I2C_PACKET_TRANSSEMET(0x03, ++i);
			_delay_ms(1000);

	}



}
