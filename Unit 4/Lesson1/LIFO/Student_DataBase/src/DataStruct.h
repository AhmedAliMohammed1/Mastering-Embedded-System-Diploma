/*
 * DataStruct.h
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */

#ifndef DATASTRUCT_H_
#define DATASTRUCT_H_
#include "Platform_Types.h"
#include <stdlib.h>
#include <stdio.h>
#define NULL (void *)0
/*************User Data Type*************/
typedef struct{
	char *name;
	usint8_t age;
	usint32_t id;

	double hight;

}information;
typedef struct{
	information student;
	struct Student_Node* PNxStudent;
}Student_Node;
typedef enum{
	FOUND,NOTFOUND

}Student_Status;

/*************APIs*************/
void Fill_info(Student_Node *Student);
void Add_student();
Student_Status Delet_student(usint32_t wanted_id);
void view_AllStudents();
void Delet_AllStudents();
void Student_Print(Student_Node *Student);
#endif /* DATASTRUCT_H_ */
