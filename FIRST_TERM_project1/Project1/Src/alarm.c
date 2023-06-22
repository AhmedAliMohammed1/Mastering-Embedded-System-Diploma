

#include "alarm.h"
extern vusint32_t Alarm_START;
void (*g_alarm_fun)();
STATE_define(Alarm_Start){
Set_Alarm_actuator(Alarm_START);
	Delay(100000);
}
void Alarm_Setup(){
g_alarm_fun=STATE_call(Alarm_Start);
}