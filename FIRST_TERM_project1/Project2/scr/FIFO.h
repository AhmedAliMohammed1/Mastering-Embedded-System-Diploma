/*
 * FIFO.h
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "Platform_Types.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Courses_N 5
typedef struct{
	vusint32_t ID;
	char* F_name;
	char* L_name;
	float GPA;
	vusint32_t Courses_ID[Courses_N];

}Data;

#define element_type Data
#define NULL (void *)0
/*************User Data Type*************/
typedef struct {
	usint32_t length;
	element_type* head;
	element_type* base;
	element_type* tail;
	usint32_t count;

}FIFO_t;
typedef enum{

	FIFO_no_error,FIFO_FULL,FIFO_empty,FIFO_null
}FIFO_status;
typedef enum{

	ID_exist,ID_Not_exist
}Student_status;

/*************APIs*************/
FIFO_status FIFO_init(FIFO_t *FIFO,element_type *buff,usint32_t length);
FIFO_status FIFO_PUSH_Manually(FIFO_t *FIFO,usint32_t ID);
FIFO_status FIFO_POP_ID(FIFO_t *FIFO,usint32_t ID);
Student_status Chek_ID_Status(FIFO_t *FIFO,usint32_t ID);
void FIFO_print(FIFO_t *FIFO);
void Find_From_ID(FIFO_t *FIFO,usint32_t ID);
void Find_From_F_Name(FIFO_t *FIFO,char* name);
void Find_From_Course_ID(FIFO_t *FIFO,usint32_t ID);
usint32_t Total_number(FIFO_t *FIFO);
FIFO_status ADD_from_FILE(FIFO_t *FIFO);
void Update_From_ID(FIFO_t *FIFO,usint32_t ID);
#endif /* FIFO_H_ */
