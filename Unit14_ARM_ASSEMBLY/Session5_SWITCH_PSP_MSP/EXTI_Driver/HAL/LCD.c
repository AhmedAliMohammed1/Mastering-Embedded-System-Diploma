#include "LCD.h"
	PIN_config PIN_C;

void EN_PULS(){
	MCAL_write_PIN(CTRL_PORT, EN, LOGIC_HIGH);
	wait_ms(50);
	MCAL_write_PIN(CTRL_PORT, EN, LOGIC_LOW);

}

void LCD_sendCommand(usint8_t command){
	MCAL_write_PIN(CTRL_PORT, RS, LOGIC_LOW);
	wait_ms(1);
#ifdef EIGHT_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D0, GET_BIT(command,0));
	MCAL_write_PIN(DATA_PORT, D1, GET_BIT(command,1));
	MCAL_write_PIN(DATA_PORT, D2, GET_BIT(command,2));
	MCAL_write_PIN(DATA_PORT, D3, GET_BIT(command,3));
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(command,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(command,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(command,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(command,7));
	wait_ms(1);

	EN_PULS();
#endif
#ifdef FOUR_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(command,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(command,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(command,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(command,7));
	EN_PULS();
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(command,0));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(command,1));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(command,2));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(command,3));
	EN_PULS();

#endif

}

void LCD_init(){
	wait_ms(20); // wait until power

	// COFIGEUR RS Pin as output OD

		PIN_C.PIN_number=RS;
		PIN_C.MODE=OUTPUT_PP;
		PIN_C.SPEED=SPEED_2;

	MCAL_GPIO_init(CTRL_PORT,&PIN_C);
	// COFIGEUR RW Pin as output OD
//	wait_ms(1);

		PIN_C.PIN_number=RW;
	MCAL_GPIO_init(CTRL_PORT,&PIN_C);

	// COFIGEUR EN Pin as output OD
//	wait_ms(1);

		PIN_C.PIN_number=EN;
	MCAL_GPIO_init(CTRL_PORT,&PIN_C);
	wait_ms(15); // wait until power
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
wait_ms(1);
LCD_sendCommand(LCD_GO_TO_HOME);

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);


	wait_ms(1);

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
	wait_ms(1);
	LCD_sendCommand(LCD_GO_TO_HOME);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

	wait_ms(1);



#endif
	LCD_sendCommand(LCD_CURSOR_ON);

}
void LCD_clearScreen(){
	LCD_sendCommand(LCD_CLEAR_COMMAND);


}

void LCD_sendCharcter(usint8_t data){
	MCAL_write_PIN(CTRL_PORT, RS, LOGIC_HIGH);
	MCAL_write_PIN(CTRL_PORT, RW, LOGIC_LOW);

	wait_ms(1);
#ifdef EIGHT_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D0, GET_BIT(data,0));
	MCAL_write_PIN(DATA_PORT, D1, GET_BIT(data,1));
	MCAL_write_PIN(DATA_PORT, D2, GET_BIT(data,2));
	MCAL_write_PIN(DATA_PORT, D3, GET_BIT(data,3));
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(data,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(data,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(data,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(data,7));
	wait_ms(1);

	EN_PULS();
#endif
#ifdef FOUR_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(data,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(data,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(data,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(data,7));
	EN_PULS();
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(data,0));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(data,1));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(data,2));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(data,3));
	EN_PULS();

#endif

}
void LCD_sendString(char *data){
	usint8_t counter=0;
	while(*data != 0){
		counter++;
		if(!(counter >=0 && counter <=16)){
					counter=0;
					LCD_moveCURSER(1,0);
				}
		LCD_sendCharcter(*data++);

	}
}
void LCD_moveCURSER(unsigned char row,unsigned char col){
	switch(row){
	case 0:
		LCD_sendCommand(LCD_SET_CURSOR_LOCATION + col);
		break;
	case 1:
		LCD_sendCommand(LCD_SET_CURSOR_LOCATION_2nd + col);
		break;

	case 2:
		LCD_sendCommand(0x94 + col);
		break;
	case 3:
		LCD_sendCommand(0xD4  + col);
		break;

	}
}
void wait_ms(usint8_t ms){
	for(int i=0;i<ms;i++)
		for(int j=0;j<255;j++);
}

