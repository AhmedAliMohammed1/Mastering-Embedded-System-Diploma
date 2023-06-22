#ifndef __ALARM_MONITOR_H_
#define __ALARM_MONITOR_H_
#include"Platform_Types.h"
#include "driver.h"
#include "state.h"


typedef enum{
 
	OFF,ON
}ALARM_MONIROE_status;

/*Prototypes*/
STATE_define(OFF);
STATE_define(ON);

void Alarm_Monitor_Setup();
#endif /* __ALARM_MONITOR_H_ */