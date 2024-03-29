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
#include "Platform_Types.h"
#include "GPIO_Driver.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "EXTI_Driver.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void EXTI9_callBack(){
	LCD_clearScreen();
	LCD_sendString("EXTI9 RISING _|--_");
}
void clock_init(){

	RCC->APB2ENR|=(1<<2) ;
	RCC->APB2ENR|=(1<<3) ;
	RCC->APB2ENR|=(1<<0);
}
int main(void)
{
	EXTI_config_t EXTI={EXT9PB9,RISEING,ENABLE,EXTI9_callBack};
	clock_init();
		LCD_init();
		MCAL_EXTI_init(&EXTI);
    /* Loop forever */
	for(;;);
}
