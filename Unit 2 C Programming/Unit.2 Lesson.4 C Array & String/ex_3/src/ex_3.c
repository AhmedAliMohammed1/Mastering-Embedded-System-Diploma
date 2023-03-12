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

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int arr[4][4],row,column,temp;
	/*Get number of row and column */
	printf("Enter rows and column of matrix");
	scanf("%d %d",&row,&column);
	/*Get elements of the matrix*/
	printf("Enter elements of Matrix:\n");

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("Enter elements of a%d%d:",(i+1),(j+1));
			scanf("%d",&arr[i][j]);
		}
	}
	/*Print the matrix before transpose*/
	printf("Entered  Matrix:\n");

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");

	}

	/*Print the matrix after transpose*/
	printf("Transpose  Matrix:\n");

	for(int i=0;i<column;i++){
		for(int j=0;j<row;j++){
			printf("%d\t",arr[j][i]);
		}
		printf("\n");

	}


	return 0;
}
