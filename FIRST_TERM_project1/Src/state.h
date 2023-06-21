/*
 * state.h
 *
 *  Created on: May 17, 2023
 *      Author: Ahmed
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdlib.h"
#include <stdio.h>
#define STATE_define(_statename_) void ST_##_statename_()
#define STATE_call(_statename_) ST_##_statename_
#endif /* STATE_H_ */
