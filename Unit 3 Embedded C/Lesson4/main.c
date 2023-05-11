/* Lesson 4 
Eng :Ahmed Ali Mohammed*/



#include "Platform_Types.h"

#define SYSCTL_Base 0x400FE000
#define GPIOF_Base 0x40025000
#define SYSCTL_RCGC2_R (*((vusint32_t * )(SYSCTL_Base + 0x108 )))
#define GPIO_PORTF_DATA_R (*((vusint32_t *) (GPIOF_Base + 0x3FC )))
#define GPIO_PORTF_DIR_R (*((vusint32_t * )(GPIOF_Base + 0x400 )))
#define GPIO_PORTF_DEN_R (*((vusint32_t *) (GPIOF_Base + 0x51c )))

int main(void){
	SYSCTL_RCGC2_R=0x00000020;
	vusint32_t i;
	for(i=0;i<400;i++); // very littel delay tm make sure that SYSCTL_RCGC2_R is set
	GPIO_PORTF_DIR_R |=(1<<3);
		for(i=0;i<400;i++); // very littel delay tm make sure that SYSCTL_RCGC2_R is set

	GPIO_PORTF_DEN_R |=(1<<3);
	while(1){
		
		GPIO_PORTF_DATA_R ^= 1<<3 ;
			for(i=0;i<200000;i++); 
	//	GPIO_PORTF_DATA_R &= ~(1<<3) ;	
	//		for(i=0;i<200000;i++); 

	}


	
	
	
	
	
	
	
	
	
	
	
	return 0;
}