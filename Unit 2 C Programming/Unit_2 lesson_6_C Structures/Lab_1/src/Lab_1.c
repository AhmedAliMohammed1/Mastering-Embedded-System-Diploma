/*
 ============================================================================
 Name        : Lab_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct SComplex{
	double m_R;
	double m_i;

};

struct SComplex ReadComplex(char name[]){
	struct SComplex c;
	printf("Please enter %s Complex Value ,Ex:(5,-3)",name);
	scanf("%lf",&c.m_R);
	scanf("%lf",&c.m_i);


	return c;
}

struct SComplex AddComplex(struct SComplex A,struct SComplex B){
	struct SComplex c;
	c.m_R=A.m_R+B.m_R;
	c.m_i=A.m_i+B.m_i;
	return c;
}
void PrintComplex(char name[],struct SComplex c){
	printf("%s = (%lf)+(%lf) j",name,c.m_R,c.m_i);


}
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
	struct SComplex x,y,z;
	x=ReadComplex("X");
	y=ReadComplex("Y");
	z=AddComplex(x,y);
	PrintComplex("Z",z);


	return 0;
}
