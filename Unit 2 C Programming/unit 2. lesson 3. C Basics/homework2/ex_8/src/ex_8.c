/*
 ============================================================================
 Name        : ex_8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x,y;
	char oprator;
	printf("Enter Operator either + or - or * or divide ");
	fflush(stdin); fflush(stdout);

	scanf("%c",&oprator);
	printf("Enter two numbers");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&x,&y);
	switch(oprator){
	case '+':
		printf("%0.1f %c %0.1f= %0.1f",x,oprator,y,(x+y));
		break;
	case '-':
		printf("%0.1f %c %0.1f= %0.1f",x,oprator,y,(x-y));
		break;
	case '*':
		printf("%0.1f %c %0.1f= %0.1f",x,oprator,y,(x*y));
		break;
	case '/':
		printf("%0.1f %c %0.1f= %0.1f",x,oprator,y,(x/y));
		break;
	default :
		printf("ERROR");
	}
	return 0;

}
