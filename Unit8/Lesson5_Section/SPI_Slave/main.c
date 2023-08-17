/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Ahmed
 */


#include "spi.h"
#include  "lcd.h"
#include <util/delay.h>
static uint8_t i,flag,dummy=255;
char data;

void call_back(){
	flag=1;
}
void main(void){
	SPI_config_t SPI_CONFIG ={Enable,Interrupt_Disable,Slave,Rising,F_CPU_4,call_back};
	MCAL_SPI_init(&SPI_CONFIG);
	LCD_init();
	LCD_clearScreen();
	LCD_sendString("Slave");
	LCD_moveCURSER(0,7);
	while(1){

//if(flag==1){
		LCD_moveCURSER(0,7);
		i=MCAL_SPI_ReciveData();
		data=MCAL_SPI_ReciveData();
		MCAL_SPI_SendData(dummy);
		LCD_intgerToString(i);
		LCD_moveCURSER(1,0);
		LCD_sendCharcter(data);
//		_delay_ms(200);
//}
//_delay_ms(200);


}
}
