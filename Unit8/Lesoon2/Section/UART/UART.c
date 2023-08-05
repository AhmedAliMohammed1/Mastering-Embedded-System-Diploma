/*
 * UART.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Ahmed
 */


#include "UART.h"
#include <avr/io.h>

void UART_init(UART_config_t *UART){
	uint16_t BUAD=0;
	//// Set Buad RATE
	if((UART->U2X_EN) == U2X_DISABLE){
		BUAD =(uint16_t)(F_CPU/(16*UART->BAUD_RATE)) -1 ;
	}else if((UART->U2X_EN) == U2X_ENABLE){
		UCSRA |=(1<<U2X);
		BUAD =(uint16_t)((F_CPU/(8*UART->BAUD_RATE)) -1) ;

	}
	UBRRH = (BUAD >>8);
	UBRRL =(uint8_t) BUAD;
	/// Make The Configuration
	UCSRC |=(1<<URSEL); //If URSEL is one, the UCSRC setting will be updated.
	UCSRC &=~(1<<UMSEL); 	UCSRC |=(UART->MODE<<UMSEL); //This bit selects between Asynchronous and Synchronous mode of operation
	UCSRC &=~(1<<UPM1); UCSRC &=~(1<<UPM0); UCSRC |=(UART->PARITY<<UPM0); //These bits enable and set type of parity generation and check
	UCSRC &=~(1<<USBS); 	UCSRC |=(UART->Stop_BIT<<USBS); //This bit selects the number of Stop Bits to be inserted by the Transmitter
	// This Driver Dosen't Support 9-bit mode
	UCSRC &=~(1<<UCSZ0); UCSRC &=~(1<<UCSZ1); UCSRC |=(UART->SIZE<<UCSZ0); //sets the number of data bits

	//////////////// Enable
	UCSRB |=(1<<RXEN) |(1<<TXEN);
	if(UART->Interrupt == Interrupt_ENABLE){
		UCSRB |=(1<<RXCIE) |(1<<TXCIE) | (1<<UDRIE);
	}



}
void UART_sendData(uint8_t data){
	while(!( (UCSRA & 1<<UDRE) ));

	UDR = data;
}

uint8_t UART_ReciveData(){
	while(!(UCSRA & 1<<RXC));
	return UDR;
}
void UART_sendString(char *data){
	while(*data !=0){
		UART_sendData(*data);
		data++;
	}
}
void UART_ReciveString(char *data){

	*data= UART_ReciveData();
	while(*data != '\n' &&*data != '\r' ){ // when press enter stop recive
		data++;
		*data= UART_ReciveData();
	}
	*data =0;
}

