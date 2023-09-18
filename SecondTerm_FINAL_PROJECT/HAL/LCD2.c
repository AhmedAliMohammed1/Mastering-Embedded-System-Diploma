#include "LCD2.h"
	PIN_config PIN_C;

void EN_PULS_V2(){
	MCAL_write_PIN(CTRL_PORT, EN, LOGIC_HIGH);
	dms(1);
	MCAL_write_PIN(CTRL_PORT, EN, LOGIC_LOW);

}

void LCD_sendCommand_V2(usint8_t command){
	MCAL_write_PIN(CTRL_PORT, RS, LOGIC_LOW);
	dms(1);
#ifdef EIGHT_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D0, GET_BIT(command,0));
	MCAL_write_PIN(DATA_PORT, D1, GET_BIT(command,1));
	MCAL_write_PIN(DATA_PORT, D2, GET_BIT(command,2));
	MCAL_write_PIN(DATA_PORT, D3, GET_BIT(command,3));
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(command,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(command,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(command,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(command,7));
	dus(1);

	EN_PULS_V2();
#endif
#ifdef FOUR_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(command,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(command,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(command,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(command,7));
	EN_PULS_V2();
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(command,0));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(command,1));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(command,2));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(command,3));
	EN_PULS_V2();

#endif

}

void LCD_init_V2(){
	dms(20); // wait until power

	// COFIGEUR RS Pin as output OD

		PIN_C.PIN_number=RS;
		PIN_C.MODE=OUTPUT_PP;
		PIN_C.SPEED=SPEED_2;

	MCAL_GPIO_init(CTRL_PORT,&PIN_C);
	// COFIGEUR RW Pin as output OD
	dus(1);

//		PIN_C.PIN_number=RW;
//	MCAL_GPIO_init(CTRL_PORT,&PIN_C);

	// COFIGEUR EN Pin as output OD
//	dus(1);

		PIN_C.PIN_number=EN;
	MCAL_GPIO_init(CTRL_PORT,&PIN_C);
	dus(15); // wait until power
//	MCAL_write_PIN(CTRL_PORT, RW, LOGIC_LOW);

#ifdef EIGHT_BIT_MODE
	// COFIGEUR PORT A  as output OD


		PIN_C.PIN_number=D0;
		PIN_C.MODE=OUTPUT_PP;
		PIN_C.SPEED=SPEED_2;

	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D1;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D2;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D3;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D4;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D5;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D6;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D7;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
dus(1);
LCD_sendCommand_V2(LCD_GO_TO_HOME);

	LCD_sendCommand_V2(LCD_TWO_LINES_EIGHT_BITS_MODE);


	dus(1);

#endif
#ifdef FOUR_BIT_MODE
	/////////////////////////////////////
	PIN_C.MODE=OUTPUT_PP;
	PIN_C.SPEED=SPEED_2;
	/////////////////////////////////////
	PIN_C.PIN_number=D4;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D5;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D6;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	PIN_C.PIN_number=D7;
	MCAL_GPIO_init(DATA_PORT,&PIN_C);
	dus(1);
	LCD_sendCommand_V2(LCD_GO_TO_HOME);

	LCD_sendCommand_V2(LCD_TWO_LINES_FOUR_BITS_MODE);

	dus(10);



#endif
	LCD_sendCommand_V2(LCD_CURSOR_ON);

}
void LCD_clearScreen_V2(){
	LCD_sendCommand_V2(LCD_CLEAR_COMMAND);


}

void LCD_sendCharcter_V2(usint8_t data){
	MCAL_write_PIN(CTRL_PORT, RS, LOGIC_HIGH);
//	MCAL_write_PIN(CTRL_PORT, RW, LOGIC_LOW);

	dus(10);
#ifdef EIGHT_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D0, GET_BIT(data,0));
	MCAL_write_PIN(DATA_PORT, D1, GET_BIT(data,1));
	MCAL_write_PIN(DATA_PORT, D2, GET_BIT(data,2));
	MCAL_write_PIN(DATA_PORT, D3, GET_BIT(data,3));
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(data,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(data,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(data,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(data,7));
	dus(1);

	EN_PULS_V2();
#endif
#ifdef FOUR_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(data,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(data,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(data,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(data,7));
	EN_PULS_V2();
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(data,0));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(data,1));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(data,2));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(data,3));
	EN_PULS_V2();

#endif

}
void LCD_sendString_V2(char *data){
	usint8_t counter=0;
	while(*data != 0){
		LCD_sendCharcter_V2(*data++);
	}
}
void LCD_moveCURSER_V2(unsigned char row,unsigned char col){
	switch(row){
	case 0:
		LCD_sendCommand_V2(LCD_SET_CURSOR_LOCATION + col);
		break;
	case 1:
		LCD_sendCommand_V2(LCD_SET_CURSOR_LOCATION_2nd + col);
		break;

	case 2:
		LCD_sendCommand_V2(0x90+ col);
		break;
	case 3:
		LCD_sendCommand_V2(0xD0+ col);
		break;

	}
}

void LCD_intgerToString_V2_V2(unsigned int num){
	int buff[16];
	itoa(num,buff,10);
	LCD_sendString_V2(buff);


}


