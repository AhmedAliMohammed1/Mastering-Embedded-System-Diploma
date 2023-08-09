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
#include "USART_Driver.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
	uint8_t data=0;

void call_Back(void){
	if(	USART1->SR &(1<<5)){
			data=	MCAL_USART_ReciveData(USART1);

		}if((USART1->SR &(1<<7))){
		MCAL_USART_SendData(USART1, data);

	}
}
int main(void)
{
	USART_Config_t UART1_CON={115200,EGHIT_BITS,DISABLE,Interrupt,ONE_STOP_BIT,Disabled,Asynchronous,call_Back};
	MCAL_USART_init(USART1, &UART1_CON);
    /* Loop forever */
	for(;;){

	}
}