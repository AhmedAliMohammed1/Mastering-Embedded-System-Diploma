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

int main(void) {
	int m=29,*ab;
	ab=&m;
	printf("Addres of ab is :%x and value of ab is :%d\n",ab,*ab);
	m=34;
	printf("Addres of m is :%x and value of m is :%d\n",&m,m);
	printf("Addres of ab is :%x and value of ab is :%d\n",ab,*ab);
	m=7;
	printf("Addres of m is :%x and value of m is :%d\n",&m,m);
	printf("Addres of ab is :%x and value of ab is :%d\n",ab,*ab);



	return 0;
}
