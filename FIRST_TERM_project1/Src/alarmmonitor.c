#include "alarmmonitor.h"
void (*g_Alarm_Monitor_fun)();
vusint32_t Alarm_START=0;
extern vusint32_t Alarm;
ALARM_MONIROE_status A_M_status;
STATE_define(OFF){
	Alarm_START=0;
if(Alarm){
	A_M_status=ON;
	g_Alarm_Monitor_fun=STATE_call(ON);
	}else{
	A_M_status=OFF;
	g_Alarm_Monitor_fun=STATE_call(OFF);
 	}
}
STATE_define(ON){
	Alarm_START=1;
		A_M_status=OFF;
	g_Alarm_Monitor_fun=STATE_call(OFF);
}

void Alarm_Monitor_Setup(){
	g_Alarm_Monitor_fun=STATE_call(OFF);
}