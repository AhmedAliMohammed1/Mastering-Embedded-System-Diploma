/*
 * Cortex_Mx_Os_Porting.h
 *
 *  Created on: Nov 8, 2023
 *      Author: medoo
 */

#ifndef INC_CORTEX_MX_OS_PORTING_H_
#define INC_CORTEX_MX_OS_PORTING_H_
#include "core_cm3.h"
typedef enum{
	Privileged,Unprivileged
}Thread_mode_level;
typedef enum{
	MSP,PSP
}SP_mode;
#define OS_SWITCH_PREV_UnPREV(x)\
		switch(x){\
		__attribute((naked)); case Privileged:\
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
		__attribute((naked));	switch(x){\
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
#define GET_PSP(x) __asm("MRS %[Output0],PSP":[Output0] "=r" (x) )

#define HANDELLER_CALL __asm("SVC #0x04")

#endif /* INC_CORTEX_MX_OS_PORTING_H_ */
