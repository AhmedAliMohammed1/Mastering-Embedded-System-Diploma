/*
 ============================================================================
 Name        : Lab_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
int main(void) {
	float r;
	char op;
	printf("Enter circle radius :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&r);
	printf("Enter your choice (a to print area , c to print circumference) ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&op);
	switch(op){
	case 'a':
		printf(" area is : %0.8f",(pi*r*r));
		break;
	case 'c':
		printf(" circumference is : %0.8f",(2*pi*r));
		break;
	default:
	}
	return 0;
}
