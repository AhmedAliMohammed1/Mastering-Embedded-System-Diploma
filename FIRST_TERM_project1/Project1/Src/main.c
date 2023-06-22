#include <stdint.h>
#include <stdio.h>
#include"sensor.h"
#include "algor.h"
#include "alarmmonitor.h"
#include "alarm.h"
#include "detection.h"
#include "driver.h"
extern void (*g_Sensor_fun)();
extern void (*g_ALGRO_fun)();
extern void (*g_Alarm_Monitor_fun)();
extern void (*g_Detection_fun)();
extern void (*g_alarm_fun)();
void setup();
int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
g_Sensor_fun();
g_ALGRO_fun();
g_Alarm_Monitor_fun();
g_Detection_fun();
g_alarm_fun();
		//Implement your Design 
	}


}

void setup(){
Sensor_Setup();
Detection_Setup();
Algro_Setup();
Alarm_Monitor_Setup();
Alarm_Setup();



}