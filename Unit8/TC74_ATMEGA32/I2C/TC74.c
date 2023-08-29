/*
 * TC74.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed
 */


#include "TC74.h"


void TC74_WRITE_ON_REG(uint8_t reg_add,uint8_t data){
	unsigned char x=0,slave_address=0x4D;
	I2C_start();
	while (I2C_getStatus() != START_condition_DONE);
	x=(slave_address <<1)+0;
	I2C_writeByte(x);
	while(I2C_getStatus() != SLA_W_DONE);
	I2C_writeByte(reg_add);
	while(I2C_getStatus() != Data_transmitted_DONE);
	I2C_writeByte(data);
	while(I2C_getStatus() != Data_transmitted_DONE);

		I2C_stop();
		TWCR=0;


}
void TC74_Read_TEMP(uint8_t *data){
	unsigned char x=0,slave_address=0x4D;
	I2C_start();
//	while (!I2C_getStatus() != START_condition_DONE); // there is bug here in proteus
	x=(slave_address <<1)+0;
	I2C_writeByte(x);
	while(I2C_getStatus() != SLA_W_DONE);
	I2C_writeByte(0x00);
	while(I2C_getStatus() != Data_transmitted_DONE);
	TWCR=0;

	I2C_start();
	x=(slave_address <<1)+1;
	I2C_writeByte(x);
	while(I2C_getStatus() != 0x40);
	*data=I2C_readByteWithACK();
	while(I2C_getStatus() != 0x58);
	I2C_stop();


}
