/*
 * Cortex_Mx_Os_Porting.c
 *
 *  Created on: Nov 8, 2023
 *      Author: medoo
 */

#include "Cortex_Mx_Os_Porting.h"
__attribute((naked))void SVC_Handler(){
	//	OS_SWITCH_PREV_UnPREV(Privileged);
	//1.The stacking happend and i need to know where is the stack (MSP/PSP)
	__asm("TST LR,#0x04 \n\t"//LR NOW HAVE THE EXECUTE_RET and if i compared it with 0x04
			//						i will know the source or the stack (MSP/PSP)
			"ITE EQ \n\t"
			"MRSEQ R0,MSP \n\t"//if equal so the 3rd bit is 1 so put the msp in r0
			"MRSNE R0,PSP \n\t"
			"B OS_SVC_ACTION");


}

void HW_init(){
	__NVIC_SetPriority(PendSV_IRQn,15);
}
void SET_PendSV(){
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}
void NMI_Handler(){
}

void HardFault_Handler(){
}
void MemManage_Handler(){
}
void BusFault_Handler(){
}
void UsageFault_Handler(){
}






