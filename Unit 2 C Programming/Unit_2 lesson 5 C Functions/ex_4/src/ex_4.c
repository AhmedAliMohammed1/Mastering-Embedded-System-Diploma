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
int power(int num,int power_num);
int main(void) {
	int x,y;
	printf("Enter base number");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	printf("Enter power number");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);
	printf("%d ^%d = %d",x,y,power(x,y));
	return 0;
}
int power(int num,int power_num){
	if(power_num!=1){
		return num*power(num,(power_num-1));
	}
}
