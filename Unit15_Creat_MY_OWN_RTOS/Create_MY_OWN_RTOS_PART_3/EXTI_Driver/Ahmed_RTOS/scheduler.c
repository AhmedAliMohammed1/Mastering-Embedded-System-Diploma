/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2023
 *      Author: medoo
 */
#include "scheduler.h"
#include "MY_RTOS_fifo.h"

#define MAIN_stack_size (3*1024)
uint8_t idel_task_LED=0,SYSTICK_LED;
typedef enum{
	POWER_SAVE,RUINNG
}OS_mode;
typedef enum{
	SVC_ACTIVE_,
	SVC_TERMINATE_
	,SVC_Task_WAIT
	,SVC_Acquire_Mutex
	,SVC_Release_Mutex
}SVC_TASK_state;
typedef struct{
	Task_sitting_t* TASKs[100]; // Task Table when task ready i will push it here
	uint32_t _S_MSP_;
	uint32_t _E_MSP_;
	uint32_t _PSP_LOCATIOR;
	uint8_t N_of_Active_Tasks;
	Task_sitting_t *Current_TASK;
	Task_sitting_t *NEXT_TASK;
	OS_mode MODE;
}OS_controller;
OS_controller MAIN_OS_Controller;
FIFO_t Ready_FIFO;
Task_sitting_t *TASKs[100];
Task_sitting_t MYRTOS_idleTask ;
extern uint32_t _estack;
extern uint32_t _eheap;


__attribute ((naked)) void PendSV_Handler(){
	/***********Save The last stack of the crrunt task***********/
	GET_PSP((MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r4":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r5":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r6":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r7":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r8":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r9":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r10":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ --;
	__asm volatile ("mov %[out1],r11":[out1] "=r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));


	/***********************Restor the data of the next mov ***********************/
	if (MAIN_OS_Controller.NEXT_TASK != NULL){
		MAIN_OS_Controller.Current_TASK = MAIN_OS_Controller.NEXT_TASK ;
		MAIN_OS_Controller.NEXT_TASK = NULL ;
	}

	__asm volatile ("mov r11,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	__asm volatile ("mov r10,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	__asm volatile ("mov r9,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	__asm volatile ("mov r8,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	__asm volatile ("mov r7,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	__asm volatile ("mov r6,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	__asm volatile ("mov r5,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	__asm volatile ("mov r4,%[in1]": :[in1] "r" (*MAIN_OS_Controller.Current_TASK->Current_PSP_));
	MAIN_OS_Controller.Current_TASK->Current_PSP_ ++;
	SET_PSP(MAIN_OS_Controller.Current_TASK->Current_PSP_);



	__asm volatile ("BX LR");





}
ERROR_id Create_main_stack(){
	ERROR_id ERROR=NO_Error;

	MAIN_OS_Controller._S_MSP_=((uint32_t)(&_estack));
	MAIN_OS_Controller._E_MSP_=(MAIN_OS_Controller._S_MSP_ -MAIN_stack_size);
	MAIN_OS_Controller._PSP_LOCATIOR =(MAIN_OS_Controller._E_MSP_ -8);
	if(MAIN_OS_Controller._E_MSP_ <((uint32_t)(&_eheap)))
		ERROR=Create_stack_error;

	return ERROR;
}
void RTOS_Create_Task_Stack(Task_sitting_t* TASKx){
	/*
	 *
	 * xPSR
	 * PC
	 * LR
	 * R12
	 * R3
	 * R2
	 * R1
	 * R0
	 * */
	TASKx->Current_PSP_ = (uint32_t *)TASKx->_S_PSP_;
	/*********************xPSR*********************/
	*TASKx->Current_PSP_ =0x01000000;
	TASKx->Current_PSP_--;
	/*********************PC*********************/
	*(TASKx->Current_PSP_)=((uint32_t )TASKx->p_function);
	TASKx->Current_PSP_--;
	/*********************LR*********************/
	*TASKx->Current_PSP_=0xFFFFFFFD;
	TASKx->Current_PSP_--;
	/*********************GP_REG*********************/
	for(int i=0;i<12;i++){
		*TASKx->Current_PSP_=0;
		TASKx->Current_PSP_--;
	}

}
ERROR_id RTOS_Create_Task(Task_sitting_t* TASKx){
	ERROR_id ERROR=NO_Error;
	//create the  stack boundry of the task
	TASKx->_S_PSP_= MAIN_OS_Controller._PSP_LOCATIOR;
	TASKx->_E_PSP_ =(TASKx->_S_PSP_ -(TASKx ->task_size));
	MAIN_OS_Controller._PSP_LOCATIOR=(TASKx->_E_PSP_ -8);
	if(TASKx->_E_PSP_ <((uint32_t)(&_eheap)))
		ERROR=Create_stack_error;

	//Create Frame Task
	RTOS_Create_Task_Stack(TASKx);
	//update Schadulr
	MAIN_OS_Controller.TASKs[MAIN_OS_Controller.N_of_Active_Tasks++]=TASKx;



	//update task state
	TASKx->TSK_state=Suspend; //the beganning is Suspend state

	return	ERROR;

}
void RTOS_ideal_task(){
	while(1){
		idel_task_LED ^=1;
	}
}
ERROR_id RTOS_init(){
	ERROR_id ERROR=NO_Error;
	//at first the os in PWOER_SAVING mode
	MAIN_OS_Controller.MODE=POWER_SAVE;
	//create the main stack boundry of my os
	if(Create_main_stack() !=NO_Error )
		return Create_stack_error;
	//creat the queue
	if(FIFO_init(&Ready_FIFO,TASKs,100)!= FIFO_no_error)
		return FIFO_ERROR;
	//create the ideal task
	MYRTOS_idleTask=(Task_sitting_t){"Ideal_TASK",255,1024,RTOS_ideal_task};
	RTOS_Create_Task(&MYRTOS_idleTask);
	return	ERROR;
}
void OS_set_SVC(uint8_t SVC_id){
	switch(SVC_id){
	case SVC_ACTIVE_:
		__asm("SVC #0x00");
		break;
	case SVC_TERMINATE_:
		__asm("SVC #0x01");
		break;
	case SVC_Task_WAIT:
		__asm("SVC #0x02");
		break;
	case SVC_Acquire_Mutex:
		__asm("SVC #0x03");
		break;
	case SVC_Release_Mutex:
		__asm("SVC #0x04");
		break;
	}
}
void Swap(Task_sitting_t **arg1,Task_sitting_t** arg2){
	Task_sitting_t   *temp=NULL;
	temp=(*arg1);
	(*arg1)=(*arg2);
	(*arg2)=temp;
}
void Selection_sort(){
	uint8_t n=MAIN_OS_Controller.N_of_Active_Tasks,min;

	for(uint8_t i=0;i<(n);i++){
		min=i;
		for(uint8_t j=i+1;j<(n);j++){
			if(MAIN_OS_Controller.TASKs[j]->priority <MAIN_OS_Controller.TASKs[min]->priority){
				min=j;
			}
		}
		Swap(&MAIN_OS_Controller.TASKs[i],&MAIN_OS_Controller.TASKs[min]);

	}

}
void Re_Arrange_Queue_Buffer(){ // accourding to sch. TABLe
	Task_sitting_t *P_task;
	Task_sitting_t *P_next_task;

	for(uint8_t i=0;i<MAIN_OS_Controller.N_of_Active_Tasks;i++){
		P_task=(MAIN_OS_Controller.TASKs[i]);
		P_next_task=MAIN_OS_Controller.TASKs[i+1];



		if(P_task->TSK_state!=Suspend){
			if(P_next_task->TSK_state==Suspend){ //reached to last of queue
				P_task->TSK_state=ready;
				FIFO_PUSH(&Ready_FIFO, P_task);
				break;
			} if(P_task->priority==P_next_task->priority){
				P_task->TSK_state=ready;
				FIFO_PUSH(&Ready_FIFO, P_task);

			}
			if(P_task->priority<P_next_task->priority){
				P_task->TSK_state=ready;
				FIFO_PUSH(&Ready_FIFO, P_task);
				break;
			}
			//			 if(P_task->priority>P_next_task->priority){
			//				//will not happend
			//				break;
			//			}
		}
		else{
		}
	}
}

void Decide_Who_next(){
	if(Ready_FIFO.count ==0 && MAIN_OS_Controller.Current_TASK->TSK_state != Suspend){
		MAIN_OS_Controller.Current_TASK->TSK_state =Running;
		FIFO_PUSH(&Ready_FIFO, MAIN_OS_Controller.NEXT_TASK);
		MAIN_OS_Controller.NEXT_TASK =MAIN_OS_Controller.Current_TASK;

	}else{
		MAIN_OS_Controller.NEXT_TASK->TSK_state =Running;
		FIFO_POP(&Ready_FIFO, &MAIN_OS_Controller.NEXT_TASK);
		if(MAIN_OS_Controller.Current_TASK ==MAIN_OS_Controller.NEXT_TASK){
			MAIN_OS_Controller.Current_TASK->TSK_state =ready;
			FIFO_POP(&Ready_FIFO, &MAIN_OS_Controller.NEXT_TASK);
		}
		if(MAIN_OS_Controller.Current_TASK->priority == MAIN_OS_Controller.NEXT_TASK->priority && MAIN_OS_Controller.Current_TASK->TSK_state != Suspend){
			MAIN_OS_Controller.Current_TASK->TSK_state =ready;
			FIFO_PUSH(&Ready_FIFO, MAIN_OS_Controller.Current_TASK);


		}else{

		}

	}
}
void OS_UPdate_Scadular_TABLE(){
	Task_sitting_t *temp=NULL;

	//Selection_sort for the active os tacks
	Selection_sort();
	//free queue
	while(FIFO_POP(&Ready_FIFO,&temp)!=FIFO_empty);
	//fill the queue accourding to the os tasks after shorting
	Re_Arrange_Queue_Buffer();


}
void OS_SVC_ACTION(uint32_t *Frame_Stack_pointer){
	uint8_t SVC_num=0;

	//now i have the frame stack pointer SP->r0->(MSP/PSP)
	//The stacking is R0,R1,R2,R3,R12,LR,PC,xPSR and i need the pc to go back and know what is the SVC number
	SVC_num=*((char *)(((char *)Frame_Stack_pointer[6])-2));
	switch(SVC_num){
	case SVC_ACTIVE_:
	case SVC_TERMINATE_:

		OS_UPdate_Scadular_TABLE();

		//check if th os is running or not
		if(MAIN_OS_Controller.MODE==RUINNG){
			//DECIDE WITCH TASK SHOULD GO TO QUEUE
			Decide_Who_next();
			//SWITCH CONTEXT (PendSV)
			SET_PendSV();
		}
		break;
	case SVC_Task_WAIT:
		OS_UPdate_Scadular_TABLE();

		break;
	case SVC_Acquire_Mutex:
		OS_UPdate_Scadular_TABLE();
		if(MAIN_OS_Controller.MODE==RUINNG){
			//DECIDE WITCH TASK SHOULD GO TO QUEUE
			Decide_Who_next();
			//SWITCH CONTEXT (PendSV)
			SET_PendSV();
		}
		break;

	case SVC_Release_Mutex:
		OS_UPdate_Scadular_TABLE();
		if(MAIN_OS_Controller.MODE==RUINNG){
			//DECIDE WITCH TASK SHOULD GO TO QUEUE
			Decide_Who_next();
			//SWITCH CONTEXT (PendSV)
			SET_PendSV();
		}
		break;

	}

}
void OS_Active_TASK(Task_sitting_t* TASKx){
	(TASKx->TSK_state)=Wait;
	OS_set_SVC(SVC_ACTIVE_);
}
void OS_TERMINATE_TASK(Task_sitting_t* TASKx){
	(TASKx->TSK_state)=Suspend;
	OS_set_SVC(SVC_TERMINATE_);
}
void OS_Ticker_Start(){
	//F_CPU 8000000UL
	//1 tick = 0.125us so if i need 1ms interrupt so i need 8000 tick
	SysTick_Config(8000);
}
void OS_TASK_wait(Task_sitting_t* TASKx,uint32_t TIME){
	TASKx->TIM_wait.Blocking=Enable;
	TASKx->TIM_wait.Ticks_Count=TIME;
	TASKx->TSK_state=Suspend;
	OS_set_SVC(SVC_Task_WAIT);

}


Mutex_ERROR Acquire_Mutex(Mutex_sitting* MUTEX,Task_sitting_t* TASKx)
{
	if(MUTEX->Current_Task ==NULL){
		MUTEX->Current_Task =TASKx;

	}else if(MUTEX->Next_TASK == NULL && (MUTEX->Current_Task != TASKx) ){
		MUTEX->Next_TASK =TASKx;
		MUTEX->Next_TASK->TSK_state =Suspend;
		OS_set_SVC(SVC_Acquire_Mutex);
	}else{
		return Mutex_OverLoad_Acquire;
	}

	return Mutex_NO_ERROR;
}
Mutex_ERROR Release_Mutex(Mutex_sitting* MUTEX,Task_sitting_t* TASKx)
{
	if(MUTEX->Current_Task ==TASKx){
		MUTEX->Current_Task=MUTEX->Next_TASK;
		MUTEX->Next_TASK=0;
		MUTEX->Current_Task->TSK_state=Wait;
		OS_set_SVC(SVC_Release_Mutex);

	}else{
		return Mutex_Release_ERROR;
	}

	return Mutex_NO_ERROR;
}
void OS_TIME_CHECK(){
	for(uint8_t i=0;i<MAIN_OS_Controller.N_of_Active_Tasks;i++){
		if(MAIN_OS_Controller.TASKs[i]->TSK_state ==Suspend){
			if(MAIN_OS_Controller.TASKs[i]->TIM_wait.Blocking == Enable ){
				if(MAIN_OS_Controller.TASKs[i]->TIM_wait.Ticks_Count ==0){
					MAIN_OS_Controller.TASKs[i]->TIM_wait.Blocking=Disable;
					MAIN_OS_Controller.TASKs[i]->TSK_state=ready;
					OS_Active_TASK(MAIN_OS_Controller.TASKs[i]);

				}else{
					MAIN_OS_Controller.TASKs[i]->TIM_wait.Ticks_Count --;
				}
			}
		}
	}

}
void SysTick_Handler(){
	SYSTICK_LED^=1;
	OS_TIME_CHECK(); // IF THERE IS A WAITING TASK
	Decide_Who_next();
	SET_PendSV();

}

void OS_start(){
	// change the mode of the OS
	MAIN_OS_Controller.MODE=RUINNG;
	MAIN_OS_Controller.Current_TASK=&MYRTOS_idleTask;
	SET_PSP(MAIN_OS_Controller.Current_TASK->Current_PSP_);
	OS_SWITCH_SP(PSP);
	OS_Ticker_Start();
	OS_SWITCH_PREV_UnPREV(Unprivileged);
	OS_Active_TASK(MAIN_OS_Controller.Current_TASK);
	MAIN_OS_Controller.Current_TASK->p_function();
}
