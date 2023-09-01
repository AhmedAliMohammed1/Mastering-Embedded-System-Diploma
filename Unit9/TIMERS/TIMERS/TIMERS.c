/*
 * TIMERS.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Ahmed
 */

#include "TIMERS.h"
TIMERS_config_t *G_P_CONFIG_=NULL;
void TIMER0_init(TIMERS_config_t* TIMER_CONFIG){
	G_P_CONFIG_=TIMER_CONFIG;
	TCNT0 =0; // clear Timer/Counter Register every time init the timer
	//• Bit 2:0 – CS02:0: Clock Select
	TCCR0 &=~(0x07 <<0);
	TCCR0 |=(TIMER_CONFIG->P_S <<0);
	switch(TIMER_CONFIG->MODE){
	case OVF:
		TCCR0 |=(1<<FOC0);
		TCCR0 &=~((1<<WGM00) |(1<<WGM01));
		break;
	case P_PWM:
		TCCR0 &=~((1<<WGM01));
		TCCR0 |=(1<<WGM00);
//		Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting
		TCCR0 &=~(1<<COM00);
		TCCR0|=(1<<COM01);
		break;
	case CTC: //2 1 0 CTC

		TCCR0 |=(1<<FOC0);
		TCCR0 &=~((1<<WGM00));
		TCCR0 |=(1<<WGM01);
		OCR0 = TIMER_CONFIG->Compare_Register;
		//0 1 Toggle OC0 on compare match
		TCCR0 &=~(1<<COM01);
		TCCR0&=~(1<<COM00);
		break;
	case F_PWM:
		TCCR0 |=(1<<WGM00)|(1<<WGM01); //3 1 1 Fast PWM
		OCR0=TIMER_CONFIG->PWM;
//		Clear OC0 on compare match, set OC0 at BOTTOM,(nin-inverting mode)
		TCCR0 &=~(1<<COM00);
		TCCR0|=(1<<COM01);
		DDRB |=(1<<PB3);
		break;
	}



	////////////////////////
	if(TIMER_CONFIG->EN){
		if(TIMER_CONFIG->MODE==OVF) TIMSK |=(1<<TOIE0);
		else if(TIMER_CONFIG->MODE==CTC) TIMSK |=(1<<OCIE0);
		SREG|=(1<<7);
	}else{

		if(TIMER_CONFIG->MODE==OVF){   while(!TIFR &(1<<TOV0));
		TIFR |=(1<<TOV0);}
				else if(TIMER_CONFIG->MODE==CTC) {
					while(!(TIFR &(1<<OCF0)));
				TIFR |=(1<<OCF0); }
	}
}





ISR(TIMER0_OVF){
	G_P_CONFIG_->P_CALLBACK();
}

ISR(TIMER0_COMP){
	G_P_CONFIG_->P_CALLBACK();

}


void WATCH_DOG_TIMER_init(void){
	WDTCR=0x0F;
}
void WATCH_DOG_TIMER_KICK(void){
	WDTCR|=(1<<WDTOE)|(1<<WDE) ;
	WDTCR=0;
}
