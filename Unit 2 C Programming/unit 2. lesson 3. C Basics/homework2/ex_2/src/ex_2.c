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
	char x;
	printf("Enter an alphabet :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	if(x=='a'||x=='A'||x=='e'||x=='E'||x=='i'||x=='I'||x=='o'||x=='O'||x=='u'||x=='U'){
		printf("%c is vowel",x);
	}else{
		printf("%c is consonant",x);

	}
	return 0;
}
