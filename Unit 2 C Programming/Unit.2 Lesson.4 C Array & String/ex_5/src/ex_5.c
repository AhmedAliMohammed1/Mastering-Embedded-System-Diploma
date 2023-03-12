/*
 ============================================================================
 Name        : ex_5.c
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
	int arr[10],s_num,n_elements,i;
	/*Get array elemnts*/
		printf("Enter no. of elemnts : ");
		scanf("%d",&n_elements);
		for(int i=0;i<n_elements;i++){
			scanf("%d",&arr[i]);
		}
		/*Get the element to be searched*/
		printf("Enter  the element to be searched: ");
		scanf("%d",&s_num);
		for(i=0;i<n_elements;i++){
			if(s_num==arr[i]){
				break;
			}
		}
		if(i==n_elements){
			printf("Not Found");
		}else{
			printf("Number found at location : %d",i+1);

		}

		return 0;
}
