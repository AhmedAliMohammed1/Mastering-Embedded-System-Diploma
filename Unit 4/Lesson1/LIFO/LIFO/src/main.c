/*
 * main.c
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */

#include "LIFO.h"
#include <stdio.h>
#define size 5

element_type arr[size],temp;
LIFO_t UART_t,I2C;
int main(void){
	LIFO_init(&UART_t, arr, size);
	int i;
	// lifo Push
	for(i=0;i<7;i++){
		if(LIFO_PUSH(&UART_t, i)==LIFO_no_error)
			printf("LIFO PUSH %d ====Done\n",i);
		else{
			printf("LIFO PUSH %d ====Failed\n",i);
		}
	}
	//LIFO PULL
	for(i=0;i<7;i++){
		if(LIFO_POP(&UART_t, &temp)==LIFO_no_error){
			printf("LIFO PULL %d ====Done\n",temp);

		}else if(LIFO_POP(&UART_t, &temp)==LIFO_empty){
			printf("LIFO is EMPTY\n");
		}
	}



return 0;
}
