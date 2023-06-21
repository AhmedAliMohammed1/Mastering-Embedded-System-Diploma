#ifndef __ALARM_H_
#define __ALARM_H_
#include"Platform_Types.h"
#include "driver.h"
#include "state.h"

STATE_define(Alarm_Start);

void Alarm_Setup();
#endif /* __ALARM_H_ */