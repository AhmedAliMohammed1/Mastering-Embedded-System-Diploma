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

void reverse(){
	char c;
	scanf("%c",&c);
	if(c!='\n'){
		reverse();
		printf("%c",c);
	}
}

int main(void) {
	printf("Enter a sentence:");
	fflush(stdin); fflush(stdout);
	reverse();
	return 0;
}
