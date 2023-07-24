#include "lcd.h"
#include  "KEYPAD.h"



	unsigned char pressed_key;


void main(){
	LCD_init();
	KEYPAD_init();
	while(1){
		pressed_key=Get_Pressed_KEY();
		switch(pressed_key){
		case 'N':
			break;
		case 'D':
			LCD_clearScreen();
			break;
		default:
			LCD_sendCharcter(pressed_key);
		}

	}




}
