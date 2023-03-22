/*
 ============================================================================
 Name        : ex_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct infomations{
	char name[15];
	int roll;
	float marks;
};
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
	struct infomations students[10];
	for(int i=0;i<10;i++){
		(students[i].roll)=i+1;
		printf("For Roll number : %d\n",i+1);
		printf("Enter Name:\n");
		scanf("%s",students[i].name);
		printf("Enter Marks :\n");
		scanf("%f",&students[i].marks);

	}


	for(int i=0;i<10;i++){
		printf("For roll number %d",	students[i].roll);
		printf("Name :%s",	students[i].name);
		printf("Marks :%0.1f",	students[i].marks);
	}
	return 0;
}
