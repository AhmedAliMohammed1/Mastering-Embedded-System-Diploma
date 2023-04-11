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
void reveres_arr(int arr[],int n){

	int temp,i,y;
	for(i=0,y=(n-1);i<y;i++,y--){
			temp=arr[i];
			arr[i]=arr[y];
			arr[y]=temp;
	}
}
int check_3_power(int num){
	int flag;
	if(num==3){
		return 1;
	}else{
		for(int i=0;i<=num;i++){
			num/=3;
			if(num==1){
				flag= 1;
			}else{
				flag=0;
			}
		}
}
	return flag;
}
int main(void) {
	int num;
	scanf("%d",&num);
printf("%d",check_3_power(num));

	return 0;
}


