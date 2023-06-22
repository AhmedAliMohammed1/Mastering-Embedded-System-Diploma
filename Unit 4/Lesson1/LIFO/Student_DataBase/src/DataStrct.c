/*
 * DataStrct.c
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */
#include "DataStruct.h"

Student_Node *g_fStudent=NULL;
void Fill_info(Student_Node *Student){
	usint8_t temp[40];
	printf("Please Enter ID:");
	gets(temp);
	Student->student.id=atoi(temp);
	printf("Please Enter Name:");
	gets(Student->student.name);
	printf("Please Enter Age:");
	gets(temp);
	Student->student.age=atoi(temp);
	printf("Please Enter Height:");
	gets(temp);
	Student->student.hight=atof(temp);




}
void Add_student(){
	Student_Node *New_student,*last_student;
	if(g_fStudent==NULL){
		New_student= (Student_Node *)malloc(sizeof(Student_Node));
		g_fStudent=New_student;


	}else{
		last_student=g_fStudent;
		while(last_student->PNxStudent){
			last_student=last_student->PNxStudent;
		}
		New_student=(Student_Node *)malloc(sizeof(Student_Node));
		last_student->PNxStudent=New_student;
	}
	Fill_info(New_student);
	New_student->PNxStudent=NULL;



}
Student_Status Delet_student(usint32_t wanted_id)
{
	Student_Node* current_student=g_fStudent,*prev_student=NULL;
	while(current_student){
		if(current_student->student.id==wanted_id){
		if(prev_student){
			prev_student->PNxStudent=current_student->PNxStudent;

		}else{
			g_fStudent=current_student->PNxStudent;
		}
		free(current_student);
		return FOUND;
	}
	else{


		prev_student=current_student;
		current_student=current_student->PNxStudent;
	}

	}
	return NOTFOUND;


}
void view_AllStudents(){
	Student_Node *Student=g_fStudent;
	while(Student){
		Student_Print(Student);
		Student=Student->PNxStudent;
	}

}
void Delet_AllStudents(){
	Student_Node *current_student=g_fStudent;
	while(current_student){
		Student_Node *prev_student=current_student;
		current_student=current_student->PNxStudent;
		free(prev_student);


	}

}
void Student_Print(Student_Node *Student){
	printf("Name:%s\n",Student->student.name);
	printf("ID:%d\n",Student->student.id);
	printf("Age:%d\n",Student->student.age);
	printf("Hight:%f\n",Student->student.hight);
	printf("==============================\n");


}
