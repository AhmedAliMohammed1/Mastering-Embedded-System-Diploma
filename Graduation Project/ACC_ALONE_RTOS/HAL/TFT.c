



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

	TFT_send_data(0x8 );
	_TIM1_delay_ms( 120);

	///////////////////////



	/////////////////////////
	TFT_send_command(TFT_Display_On_MODE);
	_TIM1_delay_ms( 120);




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


void TFT_send_image(uint8_t image_flag){

	volatile uint8_t *image=NULL;



	/***********************************/
	TFT_send_command(TFT_SET_Column_MODE);
	TFT_send_data(0x0);
	TFT_send_data(0x00);


	TFT_send_data(0x0);
	TFT_send_data(0xF9);
	/***********************************/
	TFT_send_command(TFT_SET_Row_MODE);
	TFT_send_data(0x0);
	TFT_send_data(0x00);


	TFT_send_data(0x0);
	TFT_send_data(0xB7);
	/***********************************/


	switch(image_flag){
	case 1:
		image =tr;

		break;
	}
	TFT_send_command(TFT_Memory_Write_MODE);

	for(uint32_t i=0;i<(184*255);i++){
		//		if(i<(76800)){
		//
		//
		//			TFT_send_data(0xf8);
		//			TFT_send_data(0xFF);
		//			TFT_send_data(0x00);
		//
		//		}else{
		//			TFT_send_data(0xF7);
		//			TFT_send_data(0x00);
		//			TFT_send_data(0x00);
		//		}
		//		R=(tr[i]>>11);
		//		R<<=3;
		//		G=(tr[i]>>5);
		//		G&=0x3F;
		//		TFT_send_data(tr[i]>>16);
		//		TFT_send_data(tr[i]>>8);
		//		TFT_send_data(tr[i]);
		uint8_t r = (tr[i] & 0xF800) >> 11;
		uint8_t g = (tr[i] & 0x07E0) >> 5;
		uint8_t b = tr[i] & 0x001F;

		r = (r * 255) / 31;
		g = (g * 255) / 63;
		b = (b * 255) / 31;

		TFT_send_data(r);
		TFT_send_data(g);
		TFT_send_data(b);
	}



	TFT_send_command(0x00);





}




