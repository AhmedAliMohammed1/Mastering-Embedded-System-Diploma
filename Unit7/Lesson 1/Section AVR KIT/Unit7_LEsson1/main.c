/*
 * main.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Ahmed
 */


#include "GPIO.h"
#include <util/delay.h>
#define BIT_IS_SET(REG,num) (REG & (1<<num))
#define SET_BIT(REG,num) (REG|=(1<<num))
#define Clear_BIT(REG,num) (REG&=~(1<<num))
	unsigned char counter,i,c1,c2;
void main(void){
	DDRC=0xFF;
	DDRD=0b11111000;

		while(1){
			if(counter ==0){
				SET_BIT(PORTD,5);
				_delay_ms(1000);
				SET_BIT(PORTD,6);
				_delay_ms(1000);
				SET_BIT(PORTD,7);
				_delay_ms(1000);
				Clear_BIT(PORTD,7);
				_delay_ms(1000);
				Clear_BIT(PORTD,6);
				_delay_ms(1000);
				Clear_BIT(PORTD,5);
				_delay_ms(1000);
				if(BIT_IS_SET(PIND,0)||BIT_IS_SET(PIND,1)||BIT_IS_SET(PIND,2))
					counter++;

			}else{

				if(BIT_IS_SET(PIND,0)){
					if(i==3){
						Clear_BIT(PORTD,5);
						Clear_BIT(PORTD,6);
						Clear_BIT(PORTD,7);
						i=0;
					}else{
						SET_BIT(PORTD,(5+i));
						while((BIT_IS_SET(PIND,0)));
						i++;
						_delay_ms(1000);

					}
				}else if (BIT_IS_SET(PIND,1)){
					for(c1=0;c1<10;c1++){
						for(c2=0;c2<10;c2++){
							PORTC=0b0100 |(c2<<4);
							_delay_ms(600);

							PORTC=0b1000 |(c1<<4);
							_delay_ms(1000);

						}

					}


//					while(BIT_IS_SET(PIND,1));
				}else if (BIT_IS_SET(PIND,2)){
					SET_BIT(PORTD,4);
					while((BIT_IS_SET(PIND,2)));
					Clear_BIT(PORTD,4);
						}

					}


//					while(BIT_IS_SET(PIND,1));
				}

			}










