/*
 * CA.c
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */


#include "US.h"





void (*g_US_fun)();
int US_distance;

US_states US_id;
void US_setup(){

	g_US_fun=STATE_call(read);

}



STATE_define(read){
	US_id = read;
	US_distance=get_rand_num(45,55,1);
	g_US_fun=STATE_call(read);
	US_set_distance(US_distance);
	printf("----US_distance:%d---- --> US-->CA-\n",US_distance);
	printf("file:%s FUNC:%s ",__FILE__,__func__);
	//wait 10 msec

}


int get_rand_num(int l,int h,int count){
	int i;
	for(i=0;i<count;i++){
		int rand_num=(rand()%(h-l+1))+l;
		return rand_num;
	}


}

int US_set_distance(){

	return US_distance;
}

