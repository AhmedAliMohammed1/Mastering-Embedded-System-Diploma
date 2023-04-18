#include "uart.h"

#define UART0DR *((volatile unsigned int *)((unsigned int *)0x101f1000))


void UART_sendString(char *str){
	while(*str!='\0'){
		UART0DR=(unsigned int)*str;
			str++;
	}

	
}