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
	Set_Motor_speed(speed);
	id = wating;
	distance=US_recive_distance();
	(distance <= threshold) ? (g_fun=STATE_call(wating)) : (g_fun=STATE_call(driving));
	printf("State:Waiting ----Distance:%d-----Speed:%d\n",distance,speed);
	printf("file:%s------------- FUNC:%s \n",__FILE__,__func__);

}


STATE_define(driving){
	speed=30;
	Set_Motor_speed(speed);
	id = driving;
	distance=US_recive_distance();
	(distance <= threshold) ? (g_fun=STATE_call(wating)) : (g_fun=STATE_call(driving));
	printf("State:driving ----Distance:%d-----Speed:%d\n",distance,speed);
	printf("file:%s------------- FUNC:%s \n",__FILE__,__func__);

}



int US_recive_distance(){
	int v_distance =US_set_distance();
	return v_distance;

}
int Set_Motor_speed(){


	return speed;
}
