/*
 * TFT.h
 *
 *  Created on: Feb 3, 2024
 *      Author: medoo
 */

#ifndef INC_TFT_H_
#define INC_TFT_H_

/********includes*******/
#include "GPIO_Driver.h"
#include "Timer1_8.h"
#include "SPI.h"

/********Defines*******/
#define TFT_SPI_inistant SPI1
#define TFT_PORT GPIOA
#define TFT_RESET_PIN PIN_0
#define TFT_A0_PIN PIN_1
#define TFT_CS_PIN PIN_4
#define TFT_Sleep_Out_MODE 0x11
#define TFT_Display_On_MODE 0x29
#define TFT_Pixel_Format_MODE 0x3A
#define TFT_SET_Column_MODE 0x2A
#define TFT_SET_Row_MODE 0x2B
#define TFT_Memory_Write_MODE 0x2C
#define TFT_Software_Reset_MODE 0x1

#define TFT_width 320
#define TFT_height 480



/********enums*******/
typedef enum{
	RGB_4_4_4=0x33,RGB_5_6_5=0x55,RGB_6_6_6=0x66
}RGB_fromat;


/********Fun*******/
void TFT_init(RGB_fromat RGB);
void TFT_send_command(uint8_t command);
void TFT_send_data(uint8_t data);
void TFT_send_image(uint8_t image_flag);
void send_frame();
void send_frame1();

/********Defines*******/
#define STOP_SIGN_FLAG 1

#endif /* INC_TFT_H_ */
