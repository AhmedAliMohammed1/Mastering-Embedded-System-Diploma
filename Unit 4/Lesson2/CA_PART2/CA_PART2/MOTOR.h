/*
 * CA.h
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "state.h"

typedef enum{
	Working,
	Not_Working

}MOTOR_states;

void Motor_setup();
int Motor_recive_speed();
STATE_define(Working);
STATE_define(Not_Working);

#endif /* MOTOR_H_ */
