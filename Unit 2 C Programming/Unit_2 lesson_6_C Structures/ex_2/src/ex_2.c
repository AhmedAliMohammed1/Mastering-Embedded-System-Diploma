/*
 ============================================================================
 Name        : ex_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct SAdd_feet{
	float feet,inchs;

};
struct SAdd_feet add(struct SAdd_feet c,struct SAdd_feet c1);
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);

	struct SAdd_feet f1,f2,sum;
	printf("Enter information for 1st distance:\n");
	printf("Enter Feet");
	scanf("%f",&f1.feet);
	printf("Enter inch");
	scanf("%f",&f1.inchs);
	printf("Enter information for 2nd distance:\n");
	printf("Enter Feet");
	scanf("%f",&f2.feet);
	printf("Enter inch");
	scanf("%f",&f2.inchs);
	sum=add(f1,f2);
	printf("sum of distance = %f '%.3f \"",sum.feet,sum.inchs);


	return 0;
}

struct SAdd_feet add(struct SAdd_feet c,struct SAdd_feet c1){
	struct SAdd_feet add_feet;
	add_feet.feet=c.feet+c1.feet;
	add_feet.inchs=c.inchs+c1.inchs;
	if(add_feet.inchs>12){
		add_feet.feet++;
		add_feet.inchs=12-add_feet.inchs;
	}

	return add_feet;
}
