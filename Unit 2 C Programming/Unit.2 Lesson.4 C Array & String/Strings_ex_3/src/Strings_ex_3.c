/*
 ============================================================================
 Name        : Strings_ex_3.c
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
			 char arr[30],i,temp,j;
			 /*Gets The string*/
			 printf("Enter a string:");
			 gets(arr);
			 /*loop in string to get its len*/
			 for(i=0;arr[i]!=0;i++){

			 }
			 for(j=0,--i;j!=i&&arr[j]!='/0';j++,i--){
				 temp=arr[j];
				 arr[j]=arr[i];
				 arr[i]=temp;
			 }
			 printf("%s",arr);

	return 0;
}
