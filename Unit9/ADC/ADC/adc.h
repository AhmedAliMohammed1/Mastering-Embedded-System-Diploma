/*
 * adc.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Ahmed
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define NULL ((void*)0)

#define ERROR 123
typedef enum{
	AREF,AVCC,Internal_2_56V=3
}ADC_voltage_select;
typedef enum{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ADC_Channel_select;
typedef enum{
	DISABLE,ENABLE
}ADC_Interrupt_ENABLE;
typedef enum{
	F_2,F_2_1,F_4,F_8,F_16,F_32,F_64,F_128
}ADC_Prescaler_select;
typedef struct{
	ADC_Channel_select CS;
	ADC_voltage_select VS;
	ADC_Prescaler_select PS;
	ADC_Interrupt_ENABLE IEN;
	void (*P_CALLBACK)(void);
}ADC_Config_t;


void ADC_init(ADC_Config_t* ADC_config);
uint32_t ADC_read(ADC_Channel_select ADC_CH);
uint32_t ADC_read_VOLT(ADC_Channel_select ADC_CH);
uint8_t ADC_read_PERSCENT(ADC_Channel_select ADC_CH);


#endif /* ADC_H_ */
