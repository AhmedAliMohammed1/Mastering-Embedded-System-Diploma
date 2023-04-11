/*
 ============================================================================
 Name        : ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void binary_count(int num);
int main(void) {
	int x;
	printf("Enter Number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	binary_count(x);


}
void binary_count(int num){
	int counter=0;
	printf("binary of %d is :",num);
	for(int i=0;i<8;i++){
		if(num&(1<<(7-i))){
			printf("1");
			counter++;
		}else{
			printf("0");

		}

	}
	printf(" so has %d one's",counter);


}

