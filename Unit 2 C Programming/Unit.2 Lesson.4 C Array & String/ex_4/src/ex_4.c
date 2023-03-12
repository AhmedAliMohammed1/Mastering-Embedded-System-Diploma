/*
 ============================================================================
 Name        : ex_4.c
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
	int arr[30],new_num,location,n_elements,temp;
	/*Get array elemnts*/
	printf("Enter no. of elemnts : ");
	scanf("%d",&n_elements);
	for(int i=0;i<n_elements;i++){
		scanf("%d",&arr[i]);
	}
	/*Get the new num. and its location*/
	printf("Enter the element to be inserted :");
	scanf("%d",&new_num);

	printf("Enter the location :");
		scanf("%d",&location);
		temp=arr[location-1];
		arr[location-1]=new_num;
		for(int i=(n_elements+1);i>location;i--){
			arr[i]=arr[i-1];

		}
		arr[location]=temp;

		/*Print the new array*/
		for(int i=0;i<(n_elements+1);i++){
			printf("%d",arr[i]);
		}



	return 0;
}
