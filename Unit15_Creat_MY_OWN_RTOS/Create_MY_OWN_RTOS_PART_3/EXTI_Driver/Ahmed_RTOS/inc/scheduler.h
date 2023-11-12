/*
 * scheduler.h
 *
 *  Created on: Nov 8, 2023
 *      Author: medoo
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>
#include "Cortex_Mx_Os_Porting.h"
typedef enum{
	Suspend,
	ready,
	Wait,
	Running
}TASK_state;
typedef struct{
	enum{
		Disable,
		Enable
	}Blocking;
	uint32_t Ticks_Count ;
}TimingWaiting;

typedef enum{
	NO_Error,
	Create_stack_error,
	FIFO_ERROR
}ERROR_id;
//////////////////////
typedef struct{
	char *TASK_NAME;
	uint8_t priority; //range from 0-255
	uint16_t task_size; // the task size
	void (*p_function)(void); // the c task
	TimingWaiting TIM_wait;
	TASK_state TSK_state;
	uint8_t AutoStart ;
	uint32_t _S_PSP_; // not enterd by user
	uint32_t _E_PSP_;  // not enterd by user
	uint32_t *Current_PSP_; // not enterd by user // if the task interuptted i need to save the psp
}Task_sitting_t;

typedef enum{
	Mutex_NO_ERROR,
	Mutex_OverLoad_Acquire,
	Mutex_Release_ERROR

}Mutex_ERROR;
typedef struct{
	char *Mutex_NAME;
	uint32_t *P_req_Place;
	Task_sitting_t* Current_Task;
	Task_sitting_t* Next_TASK;

}Mutex_sitting;






ERROR_id RTOS_init();
ERROR_id RTOS_Create_Task(Task_sitting_t* TASKx);
void OS_Active_TASK(Task_sitting_t* TASKx);
void OS_TERMINATE_TASK(Task_sitting_t* TASKx);
void OS_TASK_wait(Task_sitting_t* TASKx,uint32_t TIME);
Mutex_ERROR Release_Mutex(Mutex_sitting* MUTEX,Task_sitting_t* TASKx);
Mutex_ERROR Acquire_Mutex(Mutex_sitting* MUTEX,Task_sitting_t* TASKx);
#endif /* INC_SCHEDULER_H_ */
