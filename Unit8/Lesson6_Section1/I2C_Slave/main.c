/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ahmed
 */

#include "i2c.h"

void main(void){
	I2C_init();
	uint8_t data=0;
	DDRA=0xFF;
	while(1){
		I2C_PACKET_Recive(0x02, &PORTA);
//			Slave_Send_Data(0x02, ++data);
//			PORTA=data;
	}



}
