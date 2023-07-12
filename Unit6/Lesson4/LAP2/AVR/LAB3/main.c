/*
 * main.c
 *
 *  Created on: Jul 12, 2023
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



void EXTI0_init(){
	DDRD&=~(1<<2);
	MCUCR|=0b01;
	GICR|=(1<<INT0);

}
void EXTI1_init(){
	DDRD&=~(1<<3);
	MCUCR|=0b1100;
	GICR|=(1<<INT1);


}
void EXTI2_init(){
	DDRB&=~(1<<2);
	MCUCSR|=(1<<ISC2);
	GICR|=(1<<INT2);

}
void main(){
	EXTI0_init();
	EXTI1_init();
	EXTI2_init();
	DDRD|=(1<<PD5)|(1<<PD7)|(1<<PD6);
	SREG|=(1<<7);

	while(1)
	{
		PORTD&=~(1<<5);
		PORTD&=~(1<<6);
		PORTD&=~(1<<7);
		_delay_ms(1000);

	}


}

ISR(INT0_vect){
	PORTD|=(1<<5);
	_delay_ms(1500);

//	GIFR|=(1<<INTF0);
}
ISR(INT1_vect){
	PORTD|=(1<<6);
	_delay_ms(1000);

//	GIFR|=(1<<INTF1);

}
ISR(INT2_vect){
	PORTD|=(1<<7);
	_delay_ms(1000);

//	GIFR|=(1<<INTF2);

}
