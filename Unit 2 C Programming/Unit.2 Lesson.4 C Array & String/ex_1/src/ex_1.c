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
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a[2][2],b[2][2],sum[2][2];
	int i,j;
	/*Get the first matrix*/
	printf("Enter the elemnts of 1st matrix:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter a%d%d:",(i+1),(j+1));
			scanf("%f",&a[i][j]);

		}
	}
	/*Get the 2nd matrix*/

	printf("Enter the elemnts of 2nd matrix:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter b%d%d:",(i+1),(j+1));
			scanf("%f",&b[i][j]);

		}
	}
	/*Calculate The sum of 2 arrays*/
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			sum[i][j]=a[i][j]+b[i][j];
		}
	}
	/*Print The Sum Matrix*/
	printf("Sum of Matrix:\n");

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%0.1f\t",sum[i][j]);
		}
		printf("\n");
	}



	return 0;
}
