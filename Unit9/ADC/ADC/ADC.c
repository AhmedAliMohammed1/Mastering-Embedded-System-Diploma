/*
 * ADC.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmed
 */

#ifndef ADC_C_
#define ADC_C_
#include "adc.h"
ADC_Config_t *G_P_ADC_config = NULL ;
void ADC_init(ADC_Config_t* ADC_config){
	G_P_ADC_config=ADC_config;
	ADMUX&=~(0b11<<6);
	ADMUX|=(ADC_config->VS <<6); //Table 83. Voltage Reference Selections for ADC
	/////////////////////////////////////////
	ADMUX&=~(0b1111<<6);
	ADMUX|=(ADC_config->CS <<0); //Table 84. Input Channel and Gain Selections
	/////////////////////////////////////////
	ADCSRA&=~(0b111<<0);
	ADCSRA=(ADC_config->PS<<0);
	/////////////////////////////////////////
	if(ADC_config->IEN){
		ADCSRA|=(1<<ADIE);
		SREG|=(1<<7);
	}
	DDRA &=~(1<<ADC_config->CS); // MAKE PIN AS INPUT
	ADCSRA|=(1<<ADEN);// • Bit 7 – ADEN: ADC Enable
}


uint32_t ADC_read(ADC_Channel_select ADC_CH){
	if(G_P_ADC_config ==NULL){
		return ERROR;
	}else{
		ADCSRA|=(1<<ADSC);
		while(ADCSRA &(1<<ADSC));
		return ADC;
	}
}


uint32_t ADC_read_VOLT(ADC_Channel_select ADC_CH){ // mV
	uint32_t Vin_mv,Vref_mv;
	if(G_P_ADC_config ==NULL){
		return ERROR;
	}else{
		// Vin=Vout*DELTA;
		switch(G_P_ADC_config->VS){
		case AREF:
			Vref_mv=5*1000; //
			break;
		case AVCC:
			Vref_mv=5*1000; //
			break;

		case Internal_2_56V:
			Vref_mv=((2.56)*1000); //
			break;
		}
		Vin_mv =((ADC_read(ADC_CH) *Vref_mv)/1024);  //DELTA = Vref/1024


		return Vin_mv;

	}

}
uint8_t ADC_read_PERSCENT(ADC_Channel_select ADC_CH){
	if(G_P_ADC_config ==NULL){
			return ERROR;
		}else{
	  return (uint8_t)(((ADC_read(ADC_CH))*100)/1023);
		}
}


ISR(ADC_vect){
	if(G_P_ADC_config==NULL){

	}else{
		G_P_ADC_config->P_CALLBACK();
	}
}


#endif /* ADC_C_ */
