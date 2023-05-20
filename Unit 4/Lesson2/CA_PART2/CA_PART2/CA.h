/*
 * CA.h
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
#include "US.h"
#include "MOTOR.h"
typedef enum{
	wating,
	driving

}CA_states;

void US_setup();
int US_recive_distance();
int Set_Motor_speed();
STATE_define(wating);
STATE_define(driving);

#endif /* CA_H_ */
