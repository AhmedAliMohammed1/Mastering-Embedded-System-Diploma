/*
 * UART.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Ahmed
 */

#ifndef UART_H_
#define UART_H_
#include <stdint.h>

/////////////////////////
typedef enum{
	U2X_DISABLE,U2X_ENABLE
}UART_U2X_ENABLE;
typedef enum{
	Interrupt_DISABLE,Interrupt_ENABLE
}UART_Interrupt_ENABLE;
typedef enum{
	Asynchronous,Synchronous
}UART_Mode_Select;
typedef enum{
	DISABLE,Even_Parity=2,Odd_Parity
}UART_Parity_ENABLE;
typedef enum{
	One_bit,Two_Bit
}UART_Stop_Bit ;
typedef enum{
	Five_BITs,Six_BITs,Seven_BITs,Eight_BITs
}UART_Character_Size ;



typedef struct{
	UART_U2X_ENABLE U2X_EN;
	UART_Interrupt_ENABLE Interrupt;
	UART_Mode_Select MODE;
	UART_Stop_Bit Stop_BIT;
	UART_Parity_ENABLE PARITY;
	UART_Character_Size SIZE;
	uint32_t BAUD_RATE;

}UART_config_t;



////////////////////////

void UART_init(UART_config_t *UART);
void UART_sendData(uint8_t data);
uint8_t UART_ReciveData();
void UART_sendString(char *data);
void UART_ReciveString(char *data);


#endif /* UART_H_ */
