/*
 ============================================================================
 Name        : ex_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct SInformation{
	char name[15];
	int roll_num;
	float marks;

}student;
void print(struct SInformation c);
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter information of students: \n");
	printf("Enter name:");
	gets(student.name);
	printf("Enter roll:");
	scanf("%d",&student.roll_num);
	printf("Enter marks:");
	scanf("%f",&student.marks);
	print(student);

	return 0;
}
void print(struct SInformation c){
	printf("Displaying information");
	printf("name : %s\n",c.name);
	printf("Roll : %d\n",student.roll_num);
	printf("Marks : %f\n",student.marks);

}
