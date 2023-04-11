/*
 ============================================================================
 Name        : ex_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct {
	 char *emp_name;
	 int emp_id;

}Exmployee;
int main(void) {
	Exmployee e1={"Alex",1002},*e2=&e1;
	printf("Exmployee Name : %s\n",e2->emp_name);
	printf("Exmployee ID : %d\n",e2->emp_id);

	return 0;
}
