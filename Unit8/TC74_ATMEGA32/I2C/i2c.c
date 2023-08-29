/*
 * i2c.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ahmed
 */
#include "i2c.h"
#include <util/delay.h>

void I2C_init(void){
	TWSR =0x00; // select the TWI Prescaler Bits accourding to the data sheet
	TWBR = 0x02;

	TWAR =0x03; // if i will be a slave my address will be 0x02
	TWCR |=(1<<TWEN);
}
void I2C_start(void){
	TWCR |=(1<<TWEN) |(1<<TWSTA) |(1<<TWINT);
	while (!(TWCR &(1<<TWINT))) ; // wait until  TWINT Flag is set by hardware, and the status code in TWSR will be $08

}
void I2C_stop(void){
	TWCR |=(1<<TWEN) |(1<<TWSTO) |(1<<TWINT);
//	while (!(TWCR &(1<<TWINT))) ; // wait until  TWINT Flag is set by hardware, and the status code in TWSR will be $08

}
void I2C_writeByte(uint8_t data){
	TWDR=data;
	TWCR |=(1<<TWEN)  |(1<<TWINT);
	while (!(TWCR &(1<<TWINT))) ; // wait until  TWINT Flag is set by hardware, Possible status codes in master mode are $18, $20, or $38

}
uint8_t I2C_readByteWithACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWEN) ;
	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while (!(TWCR &(1<<TWINT))) ;     /* Read Data */
	return TWDR;
}
uint8_t I2C_getStatus(void)
{

	return (TWSR &0xF8);
}


uint8_t I2C_PACKET_TRANSSEMET(uint8_t slave_address,uint8_t config_reg ,uint8_t data){
	unsigned char x=0;
	I2C_start();
	while (I2C_getStatus() != START_condition_DONE);
	x=(slave_address <<1)+0;
	I2C_writeByte(x);
	while(I2C_getStatus() != SLA_W_DONE);
	I2C_writeByte(config_reg);
	while(I2C_getStatus() != Data_transmitted_DONE);
	I2C_writeByte(data);
	while(I2C_getStatus() != Data_transmitted_DONE);

		I2C_stop();
		TWCR=0;
//	I2C_RESET();
	return Send_DONE;
}
uint8_t I2C_PACKET_Recive(uint8_t slave_address,uint8_t *data){
	slave_address =I2C_readByteWithACK();
	while(I2C_getStatus() != 0x60);

	*data=I2C_readByteWithACK();
	while(I2C_getStatus() != 0x80);


	return Send_DONE;
}


uint8_t Master_Recive_Data(uint8_t slave_address,uint8_t *data){
	unsigned char x=0;
	I2C_start();
	while (I2C_getStatus() != START_condition_DONE);
	x=(slave_address <<1)+1;
	I2C_writeByte(x);
	while(I2C_getStatus() != 0x40);
	*data=I2C_readByteWithACK();
	while(I2C_getStatus() != 0x58);
	I2C_stop();


	return Send_DONE;




}
uint8_t Slave_Send_Data(uint8_t slave_address,uint8_t data){
//	TWCR |=(1<<TWEN)  |(1<<TWINT);
	//	while (!(TWCR &(1<<TWINT))) ;

	slave_address =I2C_readByteWithACK();
	while(I2C_getStatus() != 0xA8);

	TWDR=data;
	TWCR |=(1<<TWEN)  |(1<<TWINT);
	while (!(TWCR &(1<<TWINT))) ; // wait until  TWINT Flag is set by hardware, Possible status codes in master mode are $18, $20, or $38
	while(I2C_getStatus() != 0xB8);
//	I2C_RESET();
_delay_ms(30);
//	I2C_stop();

	return Send_DONE;
}


