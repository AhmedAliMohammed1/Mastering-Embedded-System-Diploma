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
unsigned char CONTORL_VAL=0;
unsigned char IPSR_VAL=0;
typedef enum{
	Privileged,Unprivileged
}Thread_mode_level;
typedef enum{
	MSP,PSP
}SP_mode;
typedef enum{
	TASKA,TASKB
}TASKS;
#define OS_SWITCH_PREV_UnPREV(x)\
		switch(x){\
		case Privileged:\
		__asm("MRS r3,CONTROL \n\t"\
				"AND r3,r3,#0xE \n\t"\
				"MSR CONTROL,r3");\
				break;\
		case Unprivileged:\
		__asm("MRS r3,CONTROL \n\t"\
				"ORR r3,r3,#0x01 \n\t"\
				"MSR CONTROL,r3");\
				break;\
		}
#define OS_SWITCH_SP(x)\
		switch(x){\
		case MSP:\
		__asm("MRS r3,CONTROL \n\t"\
				"AND r3,r3,#0x5 \n\t"\
				"MSR CONTROL,r3");\
				break;\
		case PSP:\
		__asm("MRS r3,CONTROL \n\t"\
				"ORR r3,r3,#0x02 \n\t"\
				"MSR CONTROL,r3");\
				break;\
		}

#define SET_PSP(x) __asm("MSR PSP,%[input0]": :[input0] "r" (x))
#define HANDELLER_CALL __asm("SVC #0x04")
extern int _estack;
uint32_t _S_MSP;
uint32_t _E_MSP;
uint32_t _S_TASKA_PSP;
uint32_t _E_TASKA_PSP;
uint32_t _S_TASKB_PSP;
uint32_t _E_TASKB_PSP;

uint8_t EXTI_flag;
int TASKA_HANDLER(int a,int b,int c){
	return a+b+c;
}
int TASKB_HANDLER(int a,int b,int c,int d){
	return a+b+c,d;
}
void SVC_Handler(){
	OS_SWITCH_PREV_UnPREV(Privileged);
}
void Main_OS()
{
	_S_MSP =((uint32_t)&_estack);
	_E_MSP = (_S_MSP - 512); //MSP is 512 byte

	_S_TASKA_PSP=(_E_MSP -8);
	_E_TASKA_PSP=(_S_TASKA_PSP -100);

	_S_TASKB_PSP=(_E_TASKA_PSP -8);
	_E_TASKB_PSP=(_S_TASKB_PSP -100);

	while(1){
		if(EXTI_flag==TASKA){
			SET_PSP(_S_TASKA_PSP); //SET PSP TO START OF TASK A
			OS_SWITCH_SP(PSP); //SWITCH STACK POINTER TO PSP SHADOW REG
			OS_SWITCH_PREV_UnPREV(Unprivileged); //SWITCH TO USER LEVER
			TASKA_HANDLER(1,2,3); // start do the task
			HANDELLER_CALL; //to retrun to prev
			OS_SWITCH_SP(MSP); //SWITCH STACK POINTER TO PSP SHADOW REG


		}else if(EXTI_flag==TASKB){
			SET_PSP(_S_TASKB_PSP); //SET PSP TO START OF TASK A
			OS_SWITCH_SP(PSP); //SWITCH STACK POINTER TO PSP SHADOW REG
			OS_SWITCH_PREV_UnPREV(Unprivileged); //SWITCH TO USER LEVER
			TASKB_HANDLER(1,2,3,4); // start do the task
			HANDELLER_CALL; //to retrun to prev
			OS_SWITCH_SP(MSP); //SWITCH STACK POINTER TO PSP SHADOW REG


		}
	}


}

void EXTI9_callBack(){

	if(EXTI_flag==TASKA){
		EXTI_flag=TASKB;
	}else if(EXTI_flag==TASKB){
		EXTI_flag=TASKA;

	}
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
	MCAL_EXTI_init(&EXTI);
	__asm("nop \n\t nop \n\t nop \n\t"
			"MRS %[CONTORL_VAL],CONTROL"
			:[CONTORL_VAL] "=r" (CONTORL_VAL));

	__asm("nop \n\t nop \n\t nop \n\t");
	Main_OS();
	/* Loop forever */
	for(;;);
}
