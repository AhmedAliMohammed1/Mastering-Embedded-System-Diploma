/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Ahmed
 */




#include "spi.h"
#include <util/delay.h>
static int i;


void main(void){
	SPI_config_t SPI_CONFIG ={Enable,Interrupt_Disable,Master,Rising,F_CPU_4,NULL};
	MCAL_SPI_init(&SPI_CONFIG);
	MAX7219_SendData(0x0C,0x01); //Shutdown Register Format (Address (Hex) = 0xXC) Normal Operation ==1
	MAX7219_SendData(0x09,0xFF); //Decode-Mode Register Examples (Address (Hex) = 0xX9) Code B decode for digits 7–0 =0XFF
	MAX7219_SendData(0x0A,0x0F); //Intensity Register Format (Address (Hex) = 0xXA) 15/16 31/32 (max on) =0x0F
	MAX7219_SendData(0x0B,0x07); //Scan-Limit Register Format (Address (Hex) = 0xXB) Display digits 0 1 2 3 4 5 6 7 =0x07

	while(1){
		for(i=1;i<9;i++){
			MAX7219_SendData(i,i-1);
			_delay_ms(1000);
		}
		MAX7219_SendData(1,0b1100);		_delay_ms(1000);
		MAX7219_SendData(2,0b1011);		_delay_ms(1000);
		MAX7219_SendData(3,0b1101);		_delay_ms(1000);
		MAX7219_SendData(4,0b1110);		_delay_ms(1000);
		MAX7219_SendData(5,0b1111);		_delay_ms(1000);





	}



	}

void MAX7219_SendData(uint8_t address,uint8_t data){
	PORTB &=~(1<<PB4);
	MCAL_SPI_SendData(address);
	MCAL_SPI_SendData(data);
	PORTB |=(1<<PB4);

}
