/*
 * main.c
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */

#include "FIFO.h"
#include <stdio.h>
#define size 5

element_type arr[size],temp;
FIFO_t UART_t,I2C;
int main(void){
	FIFO_init(&UART_t, arr, size);
	int i;
	// FIFO Push
	for(i=0;i<7;i++){
		if(FIFO_PUSH(&UART_t, i)==FIFO_no_error)
			printf("FIFO PUSH %d ====Done\n",i);
		else{
			printf("FIFO PUSH %d ====Failed\n",i);
		}
	}
	for(i=0;i<3;i++){
			if(FIFO_POP(&UART_t, &temp)==FIFO_no_error){
				printf("FIFO PULL %d ====Done\n",temp);

			}else if(FIFO_POP(&UART_t, &temp)==FIFO_empty){
				printf("FIFO is EMPTY\n");
			}
		}
	FIFO_print(&UART_t);

	//FIFO PULL
	for(i=0;i<7;i++){
		if(FIFO_POP(&UART_t, &temp)==FIFO_no_error){
			printf("FIFO PULL %d ====Done\n",temp);

		}else if(FIFO_POP(&UART_t, &temp)==FIFO_empty){
			printf("FIFO is EMPTY\n");
		}
	}



return 0;
}
