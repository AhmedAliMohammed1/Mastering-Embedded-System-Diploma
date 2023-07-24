/*
 * lcd.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed
 */
#include "lcd.h"
void LCD_init(){
	CTRL_DIR |=(1<<RS) |(1<<RW) | (1<<EN);
	_delay_ms(20);
	LCD_sendCommand(LCD_GO_TO_HOME);
	_delay_ms(1);
#ifdef EIGHT_BIT_MODE
	DATA_DIR =0xFF;
	_delay_ms(1);

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	_delay_ms(1);
#endif
#ifdef FOUR_BIT_MODE
	DATA_DIR |=0xF0;

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	_delay_ms(1);
#endif
	LCD_sendCommand(LCD_CURSOR_ON);


}
void LCD_sendCommand(unsigned char command){
	CTRL_PORT &=~((1<<RS)|(1<<RW));
	_delay_ms(1);
#ifdef EIGHT_BIT_MODE
	DATA_PORT = command;
#endif
#ifdef FOUR_BIT_MODE
	DATA_PORT = (DATA_PORT &0x0F) |(command &0xF0);
	EN_PULS();
	DATA_PORT = (DATA_PORT &0x0F) |(command <<4);

#endif
	_delay_ms(1);
	EN_PULS();

}
void EN_PULS(){

	CTRL_PORT |=(1<<EN);
	_delay_ms(30);

	CTRL_PORT &=~(1<<EN);
}
void LCD_sendCharcter(char data){
	CTRL_PORT |=((1<<RS));
	_delay_ms(1);
#ifdef EIGHT_BIT_MODE
	DATA_PORT = data;
#endif
#ifdef FOUR_BIT_MODE
	DATA_PORT = (DATA_PORT &0x0F) |(data &0xF0);
	EN_PULS();
	DATA_PORT = (DATA_PORT &0x0F) |(data <<4);

#endif
	_delay_ms(1);
	EN_PULS();

}

void LCD_sendString(char *data){
	unsigned char counter=0;
	while(*data != 0){
		counter++;
		if(!(counter >=0 && counter <=16)){
			counter=0;
			LCD_moveCURSER(1,0);
		}
		LCD_sendCharcter(*data++);


	}



}
void LCD_moveCURSER(unsigned char row,unsigned char col){
	switch(row){
		case 0:
			if(col >= 0 && col <=16)
				LCD_sendCommand(0x80+col);
			break;
		case 1:
			if(col >= 0 && col <=16)
				LCD_sendCommand(0xC0+col);
			break;
	}


}
void LCD_clearScreen(){
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}
