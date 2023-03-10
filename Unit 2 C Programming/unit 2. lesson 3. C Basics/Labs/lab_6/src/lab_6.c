/*
 ============================================================================
 Name        : lab_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,sum=0,i,degree;
	float avrage;

	printf("Enter number of the students");
	fflush(stdin); fflush(stdout);
		scanf("%d",&x);
		for(i=1;i<=x;i++){
			printf("Enter the student (%d) degree:",i);
			fflush(stdin); fflush(stdout);
				scanf("%d",&degree);
			sum+=degree;
		}
		avrage=(float)sum/x;
		printf("Average students degree =%f ",avrage);
		return 0;

}
