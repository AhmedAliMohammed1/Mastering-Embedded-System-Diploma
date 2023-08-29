/*
 * LCD_I2C.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed
 */
#include "LCD_I2C.h"
	unsigned char COMMAND_var=0;

void I2C_LCD_init(){
	_delay_ms(20);
	I2C_LCD_sendCommand(LCD_GO_TO_HOME);
		_delay_ms(1);
	#ifdef EIGHT_BIT_MODE
		DATA_DIR =0xFF;
		_delay_ms(1);

		I2C_LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
		_delay_ms(1);
	#endif
	#ifdef FOUR_BIT_MODE
		I2C_LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
		_delay_ms(1);
	#endif
		I2C_LCD_sendCommand(LCD_CURSOR_ON);
}
void I2C_LCD_sendCommand(unsigned char command)
{
	unsigned char x=0;
	I2C_start();
	while (I2C_getStatus() != START_condition_DONE);
	x=(SLA <<1)+0;
		I2C_writeByte(x);
		while(I2C_getStatus() != SLA_W_DONE);

		COMMAND_var &=~((1<<RS)|(1<<RW));
		I2C_writeByte(COMMAND_var);
		while(I2C_getStatus() != Data_transmitted_DONE);
	_delay_ms(1);
#ifdef EIGHT_BIT_MODE
	DATA_PORT = command;
#endif
#ifdef FOUR_BIT_MODE
	COMMAND_var = (COMMAND_var &0x0F) |(command &0xF0);
	I2C_writeByte(COMMAND_var);
	while(I2C_getStatus() != Data_transmitted_DONE);

	I2C_EN_PULS();
	COMMAND_var = (COMMAND_var &0x0F) |(command <<4);
	I2C_writeByte(COMMAND_var);
	while(I2C_getStatus() != Data_transmitted_DONE);

#endif
	_delay_ms(1);
	I2C_EN_PULS();

	I2C_stop();
	TWCR=0;

}


void I2C_EN_PULS(){

	COMMAND_var |=(1<<EN);
	I2C_writeByte(COMMAND_var);
	while(I2C_getStatus() != Data_transmitted_DONE);
	_delay_ms(30);

	COMMAND_var &=~(1<<EN);
	I2C_writeByte(COMMAND_var);
	while(I2C_getStatus() != Data_transmitted_DONE);
}

/////////////////////////////
void I2C_LCD_sendCharcter(char data){
	unsigned char x=0;
	I2C_start();
//	while (I2C_getStatus() != START_condition_DONE); // THERE IS BUG HERE IN PROUTES
	x=(SLA <<1)+0;
		I2C_writeByte(x);
		while(I2C_getStatus() != SLA_W_DONE);
	COMMAND_var |=((1<<RS));
	I2C_writeByte(COMMAND_var);
	while(I2C_getStatus() != Data_transmitted_DONE);
	_delay_ms(1);
#ifdef EIGHT_BIT_MODE
	DATA_PORT = data;
#endif
#ifdef FOUR_BIT_MODE
	COMMAND_var = (COMMAND_var &0x0F) |(data &0xF0);
	I2C_writeByte(COMMAND_var);
	while(I2C_getStatus() != Data_transmitted_DONE);

	I2C_EN_PULS();
	COMMAND_var = (COMMAND_var &0x0F) |(data <<4);
	I2C_writeByte(COMMAND_var);
	while(I2C_getStatus() != Data_transmitted_DONE);

#endif
	_delay_ms(1);
	I2C_EN_PULS();
	I2C_stop();
	TWCR=0;
}
void I2C_LCD_sendString(char *data){
	unsigned char counter=0;
	while(*data != 0){
		counter++;
		if(!(counter >=0 && counter <=16)){
			counter=0;
			I2C_LCD_moveCURSER(1,0);
		}
		I2C_LCD_sendCharcter(*data++);


	}



}
void I2C_LCD_moveCURSER(unsigned char row,unsigned char col){
	switch(row){
		case 0:
			if(col >= 0 && col <=16)
				I2C_LCD_sendCommand(0x80+col);
			break;
		case 1:
			if(col >= 0 && col <=16)
				I2C_LCD_sendCommand(0xC0+col);
			break;
	}


}
void I2C_LCD_clearScreen(){
	I2C_LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void I2C_LCD_intgerToString(unsigned int num){
	int buff[16];
	itoa(num,buff,10);
	I2C_LCD_sendString(buff);


}
