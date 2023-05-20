/*
 * CA.c
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */


#include "CA.h"





void (*g_MOROT_fun)();
int Motor_speed;

MOTOR_states Motor_id;
void Motor_setup(){

	g_MOROT_fun=STATE_call(Not_Working);

}
STATE_define(Not_Working){
	Motor_id = Not_Working;
	(g_MOROT_fun=STATE_call(Working)) ;
	printf("State:Not_Working ----Motor_speed:%d\n",Motor_speed);
	printf("file:%s------------- FUNC:%s \n",__FILE__,__func__);

}


STATE_define(Working){
	Motor_speed=Motor_recive_speed();
	Motor_id = Working;
	printf("State:Working ----Motor_speed:%d\n",Motor_speed);
	printf("file:%s------------- FUNC:%s \n",__FILE__,__func__);
	(g_MOROT_fun=STATE_call(Not_Working)) ;


}

int Motor_recive_speed(){
	int v_Motor_speed =Set_Motor_speed();
	return v_Motor_speed;

}
