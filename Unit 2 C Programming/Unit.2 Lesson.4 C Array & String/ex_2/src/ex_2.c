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

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float arr[30],average,sum=0;
	int i,num;
	printf("Enter the numbers of data:");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		printf("Enter The number :");
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}
	average=(float)sum/num;
	printf("Avrage= %0.2f",average);
	return 0;
}
