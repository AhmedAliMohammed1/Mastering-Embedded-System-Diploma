/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2023
 *      Author: medoo
 */
#include "scheduler.h"
#include "MY_RTOS_fifo.h"
#define MAIN_stack_size (3*1024)
typedef enum{
	POWER_SAVE,RUINNG
}OS_mode;
typedef struct{
	Task_sitting_t *TASKs[100]; // Task Table when task ready i will push it here
	uint32_t _S_MSP_;
	uint32_t _E_MSP_;
	uint32_t _PSP_LOCATIOR;
	uint32_t N_of_Active_Tasks;
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


void PendSV_Handler(){
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
	for(int i=0;i<13;i++){
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
	MAIN_OS_Controller.TASKs[MAIN_OS_Controller.N_of_Active_Tasks]=TASKx;
	MAIN_OS_Controller.N_of_Active_Tasks++;


	//update task state
	TASKx->TSK_state=Suspend; //the beganning is Suspend state
	return	ERROR;

}
void RTOS_ideal_task(){
	while(1);
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
	Task_sitting_t IDEAL_task={"Ideal_TASK",255,1024,RTOS_ideal_task};
	RTOS_Create_Task(&IDEAL_task);
	return	ERROR;
}
