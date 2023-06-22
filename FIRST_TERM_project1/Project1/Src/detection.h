#ifndef __DETECTION__H
#define __DETECTION__H
#include"Platform_Types.h"
#include "driver.h"
#include "sensor.h"

#define Threshold_Pressure 20
typedef enum{
NORMAL,High_PressureDetection

}Detection_status;

/*Prototypes*/
STATE_define(NORMAL);
STATE_define(High_PressureDetection);

void Detection_Setup();
#endif