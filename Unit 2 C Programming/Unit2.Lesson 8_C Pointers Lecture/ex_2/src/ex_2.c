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
	char s='A',*p_s=&s;
	while(*p_s<='Z'){
		printf("%c  ",(*p_s)++);



	}


	return 0;
}
