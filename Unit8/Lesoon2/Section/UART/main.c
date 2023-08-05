/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Ahmed
 */


#include "lcd.h"
#include "UART.h"


void main(){
	uint8_t x,str[10];
	UART_config_t U={U2X_ENABLE,Interrupt_DISABLE,Asynchronous,One_bit,DISABLE,Eight_BITs,9600};
	LCD_init();
	UART_init(&U);
	UART_ReciveString(str);
	LCD_sendString(str);
	LCD_moveCURSER(1, 0);

	while(1){
		x=UART_ReciveData();
		LCD_sendCharcter(x);

	}

}
