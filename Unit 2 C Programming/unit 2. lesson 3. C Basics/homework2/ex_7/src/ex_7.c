/*
 ============================================================================
 Name        : ex_7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,i,fact=1;
		printf("Enter a number:");
			fflush(stdin); fflush(stdout);
			scanf("%d",&x);
			if(x>=0){
				for(i=1;i<=x;i++){
					fact*=i;
				}
			}else{
				printf("Error !!! Factorial of nigative number dosen't exist");
			}
			x==0?fact=0:fact;

			printf("fact = %d",fact);

	return 0;
}
