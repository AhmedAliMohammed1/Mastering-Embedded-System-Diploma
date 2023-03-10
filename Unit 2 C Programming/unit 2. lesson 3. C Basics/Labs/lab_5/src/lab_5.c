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
	int x,sum=0,i;
	fflush(stdin); fflush(stdout);
		scanf("%d",&x);
		for(i=1;i<=x;i++){
			sum+=i;
		}
		printf("summtion values between (1 and %d) = %d",x,sum);
		return 0;

}
