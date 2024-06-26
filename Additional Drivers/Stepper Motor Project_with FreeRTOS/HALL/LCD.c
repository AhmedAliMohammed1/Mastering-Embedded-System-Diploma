#include "LCD.h"
	PIN_config PIN_C;

void EN_PULS(){
	MCAL_write_PIN(CTRL_PORT, EN, LOGIC_HIGH);
_TIM1_delay_ms(1);
	MCAL_write_PIN(CTRL_PORT, EN, LOGIC_LOW);
	_TIM1_delay_ms(1);


}

void LCD_sendCommand(usint8_t command){
	MCAL_write_PIN(CTRL_PORT, RS, LOGIC_LOW);
_TIM1_delay_ms(1);
#ifdef EIGHT_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D0, GET_BIT(command,0));
	MCAL_write_PIN(DATA_PORT, D1, GET_BIT(command,1));
	MCAL_write_PIN(DATA_PORT, D2, GET_BIT(command,2));
	MCAL_write_PIN(DATA_PORT, D3, GET_BIT(command,3));
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(command,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(command,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(command,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(command,7));
	_TIM1_delay_ms(1);

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
_TIM1_delay_ms(20); // wait until power

	// COFIGEUR RS Pin as output OD

		PIN_C.PIN_number=RS;
		PIN_C.MODE=OUTPUT_PP;
		PIN_C.SPEED=SPEED_2;

	MCAL_GPIO_init(CTRL_PORT,&PIN_C);
	// COFIGEUR RW Pin as output OD
//	_TIM1_delay_ms(1);

//		PIN_C.PIN_number=RW;
//	MCAL_GPIO_init(CTRL_PORT,&PIN_C);

	// COFIGEUR EN Pin as output OD
//	_delay_us(1);

		PIN_C.PIN_number=EN;
	MCAL_GPIO_init(CTRL_PORT,&PIN_C);
	_TIM1_delay_ms(15); // wait until power
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
_TIM1_delay_ms(1);
LCD_sendCommand(LCD_GO_TO_HOME);

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);


	_TIM1_delay_ms(1);

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
	_TIM1_delay_ms(1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

	_TIM1_delay_ms(10);



#endif
	LCD_sendCommand(LCD_CURSOR_ON);
	LCD_sendCommand(LCD_GO_TO_HOME);
	LCD_clearScreen();

}
void LCD_clearScreen(){
	LCD_sendCommand(LCD_CLEAR_COMMAND);


}

void LCD_sendCharcter(usint8_t data){
	MCAL_write_PIN(CTRL_PORT, RS, LOGIC_HIGH);
//	MCAL_write_PIN(CTRL_PORT, RW, LOGIC_LOW);

	_TIM1_delay_ms(10);
#ifdef EIGHT_BIT_MODE
	MCAL_write_PIN(DATA_PORT, D0, GET_BIT(data,0));
	MCAL_write_PIN(DATA_PORT, D1, GET_BIT(data,1));
	MCAL_write_PIN(DATA_PORT, D2, GET_BIT(data,2));
	MCAL_write_PIN(DATA_PORT, D3, GET_BIT(data,3));
	MCAL_write_PIN(DATA_PORT, D4, GET_BIT(data,4));
	MCAL_write_PIN(DATA_PORT, D5, GET_BIT(data,5));
	MCAL_write_PIN(DATA_PORT, D6, GET_BIT(data,6));
	MCAL_write_PIN(DATA_PORT, D7, GET_BIT(data,7));
	_TIM1_delay_ms(1);

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
	uint8_t i=0;
	while(data[i] != 0){
		LCD_sendCharcter(data[i++]);

	}
}
void LCD_moveCURSER(unsigned char row,unsigned char col){
	uint8_t lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x10;
				break;
		case 3:
			lcd_memory_address=col+0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_intgerToString(unsigned int num){
	char buff[16];
	itoa(num,buff,10);
	LCD_sendString(buff);


}


