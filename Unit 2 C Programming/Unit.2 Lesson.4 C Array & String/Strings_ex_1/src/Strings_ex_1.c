/*
 ============================================================================
 Name        : Strings_ex_1.c
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
	 char Freq[256]={0},arr[30],s_char;
	 /*Gets The string*/
	 printf("Enter a string:");
	 gets(arr);
	 /*Get the freq of all char*/
	 for(int i=0;arr[i]!=0;i++){
		 Freq[arr[i]]++;
	 }
	 /*Get the character to find frequency*/
	 printf("Enter the character to find frequency: ");
	 scanf("%c",&s_char);
	 /*Print frequency of character*/
	 printf("Frequency of %c is %d",s_char,Freq[s_char]);

	return 0;
}
