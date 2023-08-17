/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Ahmed
 */


#include "spi.h"
#include  "lcd.h"
#include <util/delay.h>
static uint8_t i,flag,dummy;
char data='A';
void call_back(){
	flag=1;
}
void main(void){
	SPI_config_t SPI_CONFIG ={Enable,Interrupt_Disable,Master,Rising,F_CPU_4,call_back};
	MCAL_SPI_init(&SPI_CONFIG);
	PORTB |=(1<<PB4);
	LCD_init();
	LCD_clearScreen();
	LCD_sendString("MASTER");
	while(1){

		LCD_moveCURSER(0,7);
		PORTB &=~(1<<PB4);

		MCAL_SPI_SendData(i);
		PORTB |=(1<<PB4);

		PORTB &=~(1<<PB4);
		MCAL_SPI_SendData(data);
		PORTB |=(1<<PB4);

		PORTB &=~(1<<PB4);
		dummy=MCAL_SPI_ReciveData();
		PORTB |=(1<<PB4);

		LCD_intgerToString(i);
		LCD_moveCURSER(1,0);
		LCD_intgerToString(dummy);

i++;
if(i==10){
	i=0;
}
if(data++ =='Z') (data)='A';

_delay_ms(1000);
}
}
