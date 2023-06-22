#include"sensor.h"

vusint32_t pval;
void (*g_Sensor_fun)();
Sensor_status s_status;
STATE_define(ideal){

	s_status=read;
	g_Sensor_fun=STATE_call(read);

}
STATE_define(read){
	pval=getPressureVal();
	s_status=ideal;
	g_Sensor_fun=STATE_call(ideal);

}


vusint32_t readPval(){


	return pval;
}

void Sensor_Setup(){
	g_Sensor_fun=STATE_call(ideal);
}