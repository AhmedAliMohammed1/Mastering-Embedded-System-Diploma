/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Ahmed
 */


#include "TIMERS.h"
#include <util/delay.h>
#define F_CPU 1000000UL

void main(void){
	TIMERS_config_t CONFIG={CTC,F_1024,DISABLE,100,0};
	DDRB |=(1<<0);
	while(1){
		PORTB^=(1<<0);
		for(int i=0;i<20;i++){ //wait I*100 msec
			TIMER0_init(&CONFIG);

		}
	}
}
