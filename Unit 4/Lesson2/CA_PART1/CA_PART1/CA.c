/*
 * CA.c
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */


#include "CA.h"





void (*g_fun)();
int distance,threshold=50,speed;

CA_states id;
void setup(){

	g_fun=STATE_call(wating);

}
STATE_define(wating){
	speed=0;
	id = wating;
	distance=get_rand_num(45,55,1);
	(distance <= threshold) ? (g_fun=STATE_call(wating)) : (g_fun=STATE_call(driving));
	printf("State:Waiting ----Distance:%d-----Speed:%d\n",distance,speed);
}


STATE_define(driving){
	speed=30;
	id = driving;
	distance=get_rand_num(45,55,1);
	(distance <= threshold) ? (g_fun=STATE_call(wating)) : (g_fun=STATE_call(driving));
	printf("State:driving ----Distance:%d-----Speed:%d\n",distance,speed);

}


int get_rand_num(int l,int h,int count){
	int i;
	for(i=0;i<count;i++){
		int rand_num=(rand()%(h-l+1))+l;
		return rand_num;
	}


}
