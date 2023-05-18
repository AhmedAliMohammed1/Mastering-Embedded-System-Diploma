/*
 * CA.h
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

typedef enum{
	wating,
	driving

}CA_states;

void setup();
int get_rand_num(int l,int h,int count);
STATE_define(wating);
STATE_define(driving);

#endif /* CA_H_ */
