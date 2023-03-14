/*
 ============================================================================
 Name        : ex_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int fact(int num);
int main(void) {
	int num;
	printf("Enter an positive integer :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	printf("Factorial of %d is :%d",num,fact(num));
	return 0;
}

int fact(int num){
	if(num!=1){
		return num*fact(num-1);
	}

}
