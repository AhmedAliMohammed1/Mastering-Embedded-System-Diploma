



#include "TFT.h"
#include "TFT_signs.h"


/**================================================================
 * @Fn- TFT_init
 * @brief - this fun shall to Init the tft
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void TFT_init(RGB_fromat RGB){

	/**************init the moudles used*************/
	SPI_Config_t TFT_Config={enabled,Master,SPI_8_BITS,MSB,SW,F_CPU_2,idle_0,first_clock};
	PIN_config PINx={TFT_RESET_PIN,OUTPUT_PP,SPEED_10};
	MCAL_SPI_init(TFT_SPI_inistant, &TFT_Config);
	MCAL_GPIO_init(TFT_PORT, &PINx);
	PINx.PIN_number =TFT_A0_PIN;
	MCAL_GPIO_init(TFT_PORT, &PINx);
	/**************Start the init*************/
	MCAL_write_PIN(TFT_PORT, TFT_CS_PIN, LOGIC_HIGH);
	MCAL_write_PIN(TFT_PORT, TFT_RESET_PIN, LOGIC_LOW);
	_TIM1_delay_ms( 120);
	MCAL_write_PIN(TFT_PORT, TFT_RESET_PIN, LOGIC_HIGH);
	_TIM1_delay_ms( 120);

	TFT_send_command(0x01);
	_TIM1_delay_ms( 120);

	TFT_send_command(TFT_Sleep_Out_MODE);
	_TIM1_delay_ms( 110);

	TFT_send_command(TFT_Pixel_Format_MODE); // Interface Pixel Format
	TFT_send_data(0x6); //18 bit
	_TIM1_delay_ms( 120);

	//	TFT_send_command(0x23); // Interface Pixel Format
	TFT_send_command(0x36);
	_TIM1_delay_ms( 120);

	TFT_send_data(0b00001000 );

	_TIM1_delay_ms( 120);

	///////////////////////

	/////////////////////////
	TFT_send_command(TFT_Display_On_MODE);
	_TIM1_delay_ms( 120);






	TFT_SET_BACKGROUND(0x0000,0x01DF,0x0000,0x013F,0xff,0xff,0xff);



}
void TFT_SET_LOCATION(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2){
	/***********************************/
	TFT_send_command(TFT_SET_Column_MODE);
	TFT_send_data((y1>>8));
	TFT_send_data(((uint8_t)y1));


	TFT_send_data((y2>>8));
	TFT_send_data(((uint8_t)y2));
	/***********************************/
	TFT_send_command(TFT_SET_Row_MODE);
	TFT_send_data((x1>>8));
	TFT_send_data(((uint8_t)x1));


	TFT_send_data((x2>>8));
	TFT_send_data(((uint8_t)x2));
}

void TFT_SEND_Image(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,uint16_t* image){
	uint32_t image_size=(((x2+1)-x1)*((y2+1)-y1));
	uint8_t r=0,g=0,b=0;

	TFT_SET_LOCATION(x1,x2,y1,y2);
	TFT_send_command(TFT_Memory_Write_MODE);
	for(uint32_t i=0;i<image_size;i++){
		r = (image[i] & 0xF800) >> 11;
		g = (image[i] & 0x07E0) >> 5;
		b = image[i] & 0x001F;
		r = (r * 255) / 31;
		g = (g * 255) / 63;
		b = (b * 255) / 31;

		TFT_send_data(r);
		TFT_send_data(g);
		TFT_send_data(b);
	}
	TFT_send_command(0x00);


}
void TFT_SET_BACKGROUND(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,uint8_t r,uint8_t g,uint8_t b){
	uint32_t image_size=(((x2+1)-x1)*((y2+1)-y1));
	TFT_SET_LOCATION(x1,x2,y1,y2);
	TFT_send_command(TFT_Memory_Write_MODE);
	for(uint32_t i=0;i<image_size;i++){
		TFT_send_data(r);
		TFT_send_data(g);
		TFT_send_data(b);
	}
	TFT_send_command(0x00);


}
void TFT_MAKE_option(IMAGE_option OPTION){
	TFT_send_command(TFT_Memory_Access_Control);
	_TIM1_delay_ms( 120);
	switch(OPTION){
	case X_ROTATE:
		TFT_send_data(0b01001000 );
		break;
	case Y_ROTATE:
		TFT_send_data(0b10001000 );
		break;
	default:
		TFT_send_data(0b00001000 );
		break;
	}
}
void TFT_send_command(uint8_t command)
{
	MCAL_write_PIN(TFT_PORT, TFT_CS_PIN, LOGIC_LOW); // MAKE CS LOW TO START COMMUCATION USING SPI


	MCAL_write_PIN(TFT_PORT, TFT_A0_PIN, LOGIC_LOW);

	MCAL_SPI_SendData(TFT_SPI_inistant, command);


	MCAL_write_PIN(TFT_PORT, TFT_CS_PIN, LOGIC_HIGH);

}


void TFT_send_data(uint8_t data){

	MCAL_write_PIN(TFT_PORT, TFT_CS_PIN, LOGIC_LOW); // MAKE CS LOW TO START COMMUCATION USING SPI


	MCAL_write_PIN(TFT_PORT, TFT_A0_PIN, LOGIC_HIGH);

	MCAL_SPI_SendData(TFT_SPI_inistant, data);


	MCAL_write_PIN(TFT_PORT, TFT_CS_PIN, LOGIC_HIGH);


}



uint8_t TFT_send_image(uint8_t image_flag){


	TFT_SET_BACKGROUND(0x008C,0x0153,0x006E,0x00D1,0xff,0xff,0xff);
	switch(image_flag){
	case (_100_KM_SIGN_FLAG):
	TFT_MAKE_option(default_option);
	TFT_SEND_Image(0x008C, 0x0153, 0x006E, 0x009F, _100_KM_SIGN);
	TFT_SEND_Image(0x008C, 0x0153, 0x00A0, 0x00D1, image_data_zeroh);

	return 0;
	break;

	case _120_KM_SIGN_FLAG:
		TFT_SEND_Image(0x008C, 0x0153, 0x006E, 0x009F, _120_KM_SIGN);
		TFT_SEND_Image(0x008C, 0x0153, 0x00A0, 0x00D1, image_data_zeroh);


		return 0;
		break;


		break;
	case NO_WAITING_SIGN_FLAG:
		TFT_MAKE_option(default_option);
		TFT_SEND_Image(0x008C, 0x0153, 0x006E, 0x009F, NO_WAITING_SIGN);
		TFT_MAKE_option(X_ROTATE);
		TFT_SEND_Image(0x008C, 0x0153, 0x006E, 0x009F, NO_WAITING_SIGN);
		TFT_MAKE_option(default_option);

		return 0;
		break;
	case _40_KM_SIGN_FLAG:
		TFT_MAKE_option(default_option);
		TFT_SEND_Image(0x008C, 0x0153, 0x006E, 0x009F, _40_KM_SIGN);
		TFT_SEND_Image(0x008C, 0x0153, 0x00A0, 0x00D1, image_data_zeroh);

		return 0;
		break;
	default:
		TFT_SET_BACKGROUND(0x008C,0x0153,0x006E,0x00D1,0xff,0xff,0xff);

		TFT_SEND_Image(0x00D7, 0x0108, 0x0087, 0x00B8, _NO_SIGN);


		return 1;

		break;

	}






}



