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

void OS_SVC_ACTION(uint32_t *Frame_Stack_pointer){
	uint8_t SVC_num=0;
	uint32_t val1=0,val2=0;
	//now i have the frame stack pointer SP->r0->(MSP/PSP)
	//The stacking is R0,R1,R2,R3,R12,LR,PC,xPSR and i need the pc to go back and know what is the SVC number
	SVC_num=*((char *)(((char *)Frame_Stack_pointer[6])-2));
	//R0 will be the return value to OS_service_call so if i update the return value i will get the result
	//	automatic without do any thing in OS_service_call
	switch(SVC_num){
	case 1: //ADD
		break;
	case 2: //SUB

		break;
	case 3://MUL

		break;
	case 4://CALL THE PendSV after the end of SVC
		SCB->ICSR |=SCB_ICSR_PENDSVSET_Msk;
		break;
	}

}
void OS_service_call(int SCV_num){
	int result;
	switch(SCV_num){
	case 1:
		__asm("SVC #0x01"); //scv num 1 add
		break;
	case 2:
		__asm("SVC #0x02");//scv num 2 sub

		break;
	case 3:
		__asm("SVC #0x03");//scv num 3 mul

		break;
	case 4:
		__asm("SVC #0x04");//scv num 3 PendSv

		break;

	}


}
