/*
 * TIMERS.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Ahmed
 */

#ifndef TIMERS_H_
#define TIMERS_H_
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define NULL ((void *)0)
////////////////////////////////
typedef enum{
	OVF,P_PWM,CTC,F_PWM
}TIMER_MODE;
typedef enum{
	F_1=1,F_8,F_64,F_256,F_1024
}TIMER_Clock_Select;

typedef enum{
	DISABLE,ENABLE
}TIMER_Interrupt_control;

typedef enum{
	PWM_10=26,PWM_25=64,PWM_50=128,PWM_75=192,PWM_100=255
}TIMER_PWM_sitting;

typedef struct{
	TIMER_MODE MODE;
	TIMER_Clock_Select P_S;
	TIMER_Interrupt_control EN;
	uint8_t Compare_Register ;
	TIMER_PWM_sitting PWM;
	void(* P_CALLBACK)(void);
}TIMERS_config_t;



void TIMER0_init(TIMERS_config_t* TIMER_CONFIG);
void WATCH_DOG_TIMER_init(void);
void WATCH_DOG_TIMER_KICK(void);

#endif /* TIMERS_H_ */
