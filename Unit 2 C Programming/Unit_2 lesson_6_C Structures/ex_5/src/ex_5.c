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
#define pi 3.14
#define area(x) pi*x*x
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);

	float y;
	printf("Enter the radius");
	scanf("%f",&y);
	printf("Area is : %f",area(y));
	return 0;
}
