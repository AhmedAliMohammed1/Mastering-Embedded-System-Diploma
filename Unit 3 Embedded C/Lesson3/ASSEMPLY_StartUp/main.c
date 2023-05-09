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
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800
#define RCC_APB2ENR *(volatile usint32_t  *)(RCC_BASE+ 0x18)
#define GPIOA_CRH *(volatile usint32_t    *)(GPIOA_BASE+ 0x04)
#define GPIOA_ODR *(volatile usint32_t     *)(GPIOA_BASE+ 0x0C)
typedef union{
	vusint32_t all_regs;
	struct{
		vusint32_t reserved:13;
		vusint32_t pin13:1;
	}pin;

}GPIOA_O;


int main(void)
{
	RCC_APB2ENR|=(1<<2);
	GPIOA_CRH&=0xFF0FFFFF;
	GPIOA_CRH|=0x00200000;
	volatile GPIOA_O * pins=(volatile GPIOA_O *)(GPIOA_BASE+0x0C);
	pins->pin.pin13 =0;
	for(;;){
//		GPIOA_ODR^=(1<<13);
		// another sol.
		pins->pin.pin13 =	pins->pin.pin13 ^ 0x01; // led off


		for(int i=0;i<5000;i++);
//		pins->pin.pin13 =	0; // led on
//
//		for(int i=0;i<5000;i++);


	}
}

