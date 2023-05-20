/*
 * main.c
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */
#include "CA.h"
#include "MOTOR.h"
#include  "US.h"
extern void (*g_fun)();
extern void (*g_US_fun)();
extern void (*g_MOROT_fun)();

int main(){
	volatile unsigned long long i;
	US_setup();
	setup();
	Motor_setup();
	while(1){
		g_US_fun();
		g_fun();
		g_MOROT_fun();
		for(i=0;i<200000;i++);

	}

	return 0;
}

