#include "detection.h"
void (*g_Detection_fun)();
vusint32_t H_P_D=0;
Detection_status D_status;
extern vusint32_t pval;

STATE_define(NORMAL){

if(pval>=Threshold_Pressure){
	D_status=High_PressureDetection;
	g_Detection_fun=STATE_call(High_PressureDetection);
}else{
	D_status=NORMAL;
	g_Detection_fun=STATE_call(NORMAL);
}
}
STATE_define(High_PressureDetection){
	H_P_D=1;
if(pval>=Threshold_Pressure){
	D_status=High_PressureDetection;
	g_Detection_fun=STATE_call(High_PressureDetection);
}else{
	D_status=NORMAL;
	g_Detection_fun=STATE_call(NORMAL);
	H_P_D=0;
}

}
void Detection_Setup(){
	g_Detection_fun=STATE_call(NORMAL);
}