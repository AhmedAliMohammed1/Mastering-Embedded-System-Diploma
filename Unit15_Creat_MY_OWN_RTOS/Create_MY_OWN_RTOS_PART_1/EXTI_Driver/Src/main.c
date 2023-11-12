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

#include "scheduler.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void TASKA_Handler(){
	while(1);
}
void TASKB_Handler(){
	while(1);
}
void TASKC_Handler(){
	while(1);
}
int main(void)
{
	Task_sitting_t TASKA={"TASKA",0,1024,TASKA_Handler};
	Task_sitting_t TASKB={"TASKB",0,1024,TASKB_Handler};
	Task_sitting_t TASKC={"TASKC",0,1024,TASKC_Handler};
	if(RTOS_init()!=NO_Error)
		while(1);
	RTOS_Create_Task(&TASKA);
	RTOS_Create_Task(&TASKB);
	RTOS_Create_Task(&TASKC);


//	Main_OS();

	/* Loop forever */
	for(;;);
}