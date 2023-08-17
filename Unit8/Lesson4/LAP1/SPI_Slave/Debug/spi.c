/*
 * spi.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Ahmed
 */


#include "spi.h"
SPI_config_t *G_P_SPI=NULL;
void MCAL_SPI_init(SPI_config_t * SPI){
	G_P_SPI=SPI;
	// 1. Select if the device Master or slave
	if(SPI->M_S==Master){
		DDRB |= (1<<PB4) | (1<<PB5) |(1<<PB7) ;
		DDRB &=~ (1<<PB6);
		SPCR |= (1<<MSTR);
	}else{
		DDRB |= (1<<PB6);
		DDRB &=~ (1<<PB4) | (1<<PB5) |(1<<PB7) ;
		SPCR &= ~(1<<MSTR);

	}
	//2.: SPI Clock Rate Select 1 and 0
	switch(SPI->clock)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		SPCR = (SPCR &0xFC) | (SPI->clock);
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		SPCR = (SPCR &0xFC) | (SPI->clock &0x03);
		SPSR &=~(1<0);
		SPSR |=((SPI->clock >>3)<0);
break;

	}
	//3.Clock Polarity
	SPCR |=(SPI->R_F<<CPOL);
	// 4. Enable Interrupt
	if(SPI->IN_EN){
		SPCR |=(1<<SPIE);
	}else{
		SPCR &=~(1<<SPIE);

	}
	// 5.SPI Enable
	SPCR =(SPCR&0xDF) |(SPI->EN<<SPE);

}
uint8_t MCAL_SPI_SendData(uint8_t data){
	SPDR=data;
	if(G_P_SPI->IN_EN){ // will jump to isr
		SREG |=(1<<7);
	}else{
		while(!(SPSR &(1<<SPIF)));

	}
	return SPDR;

}
uint8_t MCAL_SPI_ReciveData(uint8_t data){
	SPDR=data;
	if(G_P_SPI->IN_EN){ // will jump to isr
		SREG |=(1<<7);
	}else{
		while(!(SPSR &(1<<SPIF)));

	}
	return SPDR;

}

ISR(SPI_STC_vect){
	G_P_SPI->callback_fun();
}
