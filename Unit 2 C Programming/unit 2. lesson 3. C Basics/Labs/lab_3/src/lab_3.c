/*
 ============================================================================
 Name        : ex_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y,z,min=0;
	printf("Enter three numbers");
	fflush(stdin); fflush(stdout);
		scanf("%d %d %d",&x,&y,&z);
		if(x<y){
			if(x<z){
				min=x;
			}else{
				min=z;
			}
		}else{
			if(y<z){
				min=y;
			}else{
				min=z;
			}
		}
		printf("the smallest =%d",min);
	return 0;
}
