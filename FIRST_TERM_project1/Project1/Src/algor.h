#ifndef __ALGRO_H_
#define __ALGRO_H_
#include"Platform_Types.h"
#include "driver.h"

#include "state.h"

extern vusint32_t H_P_D;
typedef enum{
 
	Normal,HighPressureDetection
}Main_status;

/*Prototypes*/
STATE_define(Normal);
STATE_define(HighPressureDetection);
void Algro_Setup();

#endif /* __ALGRO_H_ */