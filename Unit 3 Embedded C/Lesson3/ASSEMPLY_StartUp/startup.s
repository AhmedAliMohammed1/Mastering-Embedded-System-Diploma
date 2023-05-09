/* Assemply startup*/
/*Eng: Ahmed Ali Mohammed*/

.section .vectors
.word 0x20001000  /* Addres ->SP*/
.word _vector_handler /* Reset Handler*/
.word _vector_handler /* NMI*/
.word _vector_handler //Hard Fault
.word _vector_handler //MemManage
.word _vector_handler //BusFault
.word _vector_handler //UsageFault
.word _vector_handler	//Reserved
.word _vector_handler	//SVCall
.word _vector_handler	//DebugMonitor
.word _vector_handler	//Reserved
.word _vector_handler	//PedSV
.word _vector_handler	//SysTick
.word _vector_handler	//WWDG
.word _vector_handler	//PVD
.word _vector_handler	//Tamper
.word _vector_handler	//RTC
.word _vector_handler	//Flash
.word _vector_handler	//RCC
.word _vector_handler	//EXTI0
.word _vector_handler	//EXTI1
.word _vector_handler	//EXTI2

.section .text
_reset:
	bl main
	b .
	

.thumb_func
_vector_handler:
	b _reset