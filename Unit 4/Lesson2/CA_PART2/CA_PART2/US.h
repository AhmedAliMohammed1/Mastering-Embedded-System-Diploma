/*
 * CA.h
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */

#ifndef US_H_
#define US_H_
#include "state.h"
#include"CA.h"
typedef enum{
	read

}US_states;

void setup();
int get_rand_num(int l,int h,int count);
STATE_define(read);
int US_set_distance();

#endif /* US_H_ */
