#include "Platform_Types.h"
extern int main(void);
void Reset();
extern usint32_t _stack_top;
extern usint32_t _E_text;
extern usint32_t _S_DATA;
extern usint32_t _E_DATA;
extern usint32_t _S_BSS;
extern usint32_t _E_BSS;

void Reset_Handled(){
	Reset();
}

void NMI(void)__attribute__((weak,alias("Reset_Handled")));;
void HardFault(void)__attribute__((weak,alias("Reset_Handled")));;
void MemManage(void)__attribute__((weak,alias("Reset_Handled")));;
void BusFualt(void)__attribute__((weak,alias("Reset_Handled")));;
void UsageFualt(void)__attribute__((weak,alias("Reset_Handled")));;
void Reserved(void)__attribute__((weak,alias("Reset_Handled")));;
void SVCall(void)__attribute__((weak,alias("Reset_Handled")));;
void DebugMonitor(void)__attribute__((weak,alias("Reset_Handled")));;
void Reserved1(void)__attribute__((weak,alias("Reset_Handled")));;
void PendSV(void)__attribute__((weak,alias("Reset_Handled")));;
void SysTick(void)__attribute__((weak,alias("Reset_Handled")));;
void WWDG(void)__attribute__((weak,alias("Reset_Handled")));;
void PVD(void)__attribute__((weak,alias("Reset_Handled")));;
void TAMPER(void)__attribute__((weak,alias("Reset_Handled")));;
void RTC(void)__attribute__((weak,alias("Reset_Handled")));;
void FLASH(void)__attribute__((weak,alias("Reset_Handled")));;
void RCC(void)__attribute__((weak,alias("Reset_Handled")));;
void EXTI0(void)__attribute__((weak,alias("Reset_Handled")));;
void EXTI1(void)__attribute__((weak,alias("Reset_Handled")));;
void EXTI2(void)__attribute__((weak,alias("Reset_Handled")));;

usint32_t vectors[]__attribute__((section(".vectors")))={
	(usint32_t) &_stack_top,
	(usint32_t) &Reset,
	(usint32_t) &NMI,
	(usint32_t) &HardFault,
	(usint32_t) &MemManage,
	(usint32_t) &BusFualt,
	(usint32_t) &UsageFualt,
	(usint32_t) &Reserved,	
	(usint32_t) &SVCall,
	(usint32_t) &DebugMonitor,
	(usint32_t) &Reserved1,
	(usint32_t) &PendSV,
	(usint32_t) &SysTick,
	(usint32_t) &WWDG,
	(usint32_t) &PVD,
	(usint32_t) &TAMPER,	
	(usint32_t) &RTC,
	(usint32_t) &FLASH,
	(usint32_t) &RCC,
	(usint32_t) &EXTI0,
	(usint32_t) &EXTI1,
	(usint32_t) &EXTI2,

};

void Reset(){
	usint32_t DATA_SIZE= (vusint8_t*)&_E_DATA - (vusint8_t*)&_S_DATA;
	usint32_t BSS_SIZE= (vusint8_t*)&_E_BSS - (vusint8_t*)&_S_BSS;
	vusint8_t *P_SRC=(vusint8_t*)&_E_text;
	vusint8_t *P_DIS=(vusint8_t*)&_S_DATA;
	usint8_t i;
	for(i=0;i<DATA_SIZE;i++){
		*P_DIS=*P_SRC;
		(vusint8_t*)P_DIS++;
		(vusint8_t*)P_SRC++;
	}
	P_DIS=(vusint8_t*)&_S_BSS;
	for(i=0;i<BSS_SIZE;i++){
		*P_DIS=0;
		(vusint8_t*)P_DIS++;
	}
	
main();
	
}