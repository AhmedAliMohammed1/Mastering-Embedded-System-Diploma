/*
 * main.c
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */
#include "CA.h"
extern void (*g_fun)();

int main(){
 volatile unsigned long long i;
	setup();
	while(1){
		g_fun();

		for(i=0;i<200000;i++);

	}

	return 0;
}

