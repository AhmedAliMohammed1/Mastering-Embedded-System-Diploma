/*
 ============================================================================
 Name        : Strings_ex_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);
		 char arr[30],i;
		 /*Gets The string*/
		 printf("Enter a string:");
		 gets(arr);
		 /*loop in string to get its len*/
		 for(i=0;arr[i]!=0;i++){

		 }
		 printf("Lenngth of string is : %d",i);
	return 0;
}
