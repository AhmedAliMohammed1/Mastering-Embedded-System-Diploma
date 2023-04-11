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

int main(void) {
	int arr[15],num,temp;
	printf("input the number of elements in the array (max 15):");
	fflush(stdout);
	scanf("%d",&num);
	int x=num-1;
	for(int i=0;i<num;i++){
		printf("elemnt %d:",i+1);
		fflush(stdout);

		scanf("%d",(arr+i));
	}
	for(int i=0;i<=x-1;i++,x--){
		temp=*(arr+i);
		*(arr+i)=*(arr+x);
		*(arr+x)=temp;

	}
	printf("The elements of array in reverse order are:\n");

	for(int i=0;i<num;i++){
		printf("elemnt %d:%d\n",i+1,*(arr+i));

	}
	return 0;
}
