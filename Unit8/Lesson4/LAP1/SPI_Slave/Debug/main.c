/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Ahmed
 */




#include "spi.h"
#include <util/delay.h>
static int i,flag;

void call_back(){
	flag=1;
}

void main(void){
	SPI_config_t SPI_CONFIG ={Enable,Interrupt_Enable,Slave,Rising,F_CPU_4,call_back};
	MCAL_SPI_init(&SPI_CONFIG);
	DDRA =0xFF;
	while(1){

		PORTA=	MCAL_SPI_ReciveData(i);

		if(flag==1){
			for( i=255;i>0;i--){
				PORTA=	MCAL_SPI_ReciveData(i);
				_delay_ms(500);
				flag=0;

			}
	}



	}
}
