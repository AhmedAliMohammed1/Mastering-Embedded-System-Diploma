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
#include <string.h>
int main(void) {
	char str[]="w3resource",temp;
	int x=strlen(str)-1;
	for(int i=0;i<=x;i++,x--){
		temp=*(str+i);
		*(str+i)=*(str+x);
		*(str+x)=temp;

	}
	printf("%s",str);
	return 0;
}
