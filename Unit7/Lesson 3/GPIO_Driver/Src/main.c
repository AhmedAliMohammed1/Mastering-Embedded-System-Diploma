/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Platform_Types.h"
#include "GPIO_Driver.h"
/*RCC REG*/



void clock_init(){

	RCC->APB2ENR|=(1<<2) |(1<<3);

}
void GPIO_init(){
	// GPIOA PIN 1 Floating input
	PIN_config PIN_C ={PIN_1,INPUT_FI};
	MCAL_GPIO_init(GPIOA,&PIN_C);
	// GPIOA PIN 13 Floating input

	PIN_C.PIN_number=PIN_13;
	PIN_C.MODE=INPUT_FI;
	MCAL_GPIO_init(GPIOA,&PIN_C);
	/*PORTB PIN 1 AS OUTPUT PUSH PULL*/
	PIN_C.PIN_number=PIN_1;
		PIN_C.MODE=OUTPUT_PP;
		PIN_C.SPEED=SPEED_2;
	MCAL_GPIO_init(GPIOB,&PIN_C);


	/*PORTB PIN 13 AS OUTPUT PUSH PULL*/
	PIN_C.PIN_number=PIN_13;
		PIN_C.MODE=OUTPUT_PP;
		PIN_C.SPEED=SPEED_2;

	MCAL_GPIO_init(GPIOB,&PIN_C);

}

int main(void)
{

	clock_init();
	GPIO_init();
	for(;;){
		if(!MCAL_Read_PIN(GPIOA,PIN_1)){
			MCAL_TOGGLE_PIN(GPIOB, PIN_1);
			while(!MCAL_Read_PIN(GPIOA,PIN_1));
		}else if(MCAL_Read_PIN(GPIOA,PIN_13)){
			MCAL_TOGGLE_PIN(GPIOB, PIN_13);
			for(int i=0;i<255;i++)
				for(int j=0;j<255;j++);
		}



	}
}

