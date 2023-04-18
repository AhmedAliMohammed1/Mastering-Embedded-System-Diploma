#include "uart.h"
char str[100]="learn-in-depth:<ahmed ali>";
const char str1[100]="learn-in-depth:<ahmed ali>";
char arr;
void not_main(void){
	UART_sendString(str);
	
}