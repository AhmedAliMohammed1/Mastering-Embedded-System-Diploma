
#ifndef __SENSOR__H
#define __SENSOR__H
#include"Platform_Types.h"
#include "driver.h"
#include "state.h"


typedef enum{

ideal,read

}Sensor_status;

STATE_define(ideal);

STATE_define(read);
vusint32_t readPval();
void Sensor_Setup();

#endif