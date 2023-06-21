#include "algor.h"

void (*g_ALGRO_fun)();
Main_status main_status;
vusint32_t Alarm=0;
STATE_define(Normal){
	Alarm=0;

if(H_P_D){
	main_status=HighPressureDetection;
	g_ALGRO_fun=STATE_call(HighPressureDetection);
}else{
	main_status=Normal;
	g_ALGRO_fun=STATE_call(Normal);
}
}
STATE_define(HighPressureDetection){
	Alarm=1;
	main_status=Normal;
	g_ALGRO_fun=STATE_call(Normal);
			Delay(10);
		}

void Algro_Setup(){
	g_ALGRO_fun=STATE_call(Normal);
}