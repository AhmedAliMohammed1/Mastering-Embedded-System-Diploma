/*
 ============================================================================
 Name        : ex_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void print_primes(int x,int y);
int main(void) {
	int x,y;
	printf("Enter Two numbers:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&x,&y);
	print_primes(x,y);
	return 0;
}

void print_primes(int x,int y){
	int flag_prime;
	printf("Prime numbers between two  %d and %d is :",x,y);
	for(int i=x;i<=y;i++){
		for(int j=2;j<i;j++){
			if(i%j==0){
				flag_prime=0;
				break;
			}else{
				flag_prime=1;
			}
		}
		if(flag_prime==1){
			printf("%d ",i);

		}

	}

}


