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
#include <string.h>
#include <conio.h>
#define NULL (void *)0

/*************User Data Type*************/
typedef struct{
	char *name;
	int age;
	int id;

	float hight;

}information;
typedef struct Node{
	information student;
	struct Node* PNxStudent;
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
void Student_Print(Student_Node Student);
#endif /* DATASTRUCT_H_ */
