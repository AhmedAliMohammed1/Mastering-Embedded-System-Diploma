/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "SPI.h"
#include "USART_Driver.h"
void MAX7219_SendData(uint8_t address,uint8_t data){
	MCAL_write_PIN(GPIOA, PIN_4, LOGIC_LOW);
	MCAL_SPI_SendData(SPI1,address);
	MCAL_SPI_SendData(SPI1,data);
	MCAL_write_PIN(GPIOA, PIN_4, LOGIC_HIGH);

}
void _delay_ms(uint32_t num){
	for(int i=0;i<num;i++)
		for(int j=0;j<255;j++);
}
int main(void)
{
//	uint8_t data=0xF;
	SPI_Config_t CONFIG_S={enabled,Master,SPI_8_BITS,MSB,SW,F_CPU_8,idle_1,second_clock,interrupt_DS,NULL};
	USART_Config_t UART1_CON={115200,EGHIT_BITS,DISABLE,POLLING,ONE_STOP_BIT,Disabled,Asynchronous,NULL};
	MCAL_USART_init(USART1, &UART1_CON);
	MCAL_SPI_init(SPI1,&CONFIG_S);
	MCAL_write_PIN(GPIOA, PIN_4, LOGIC_HIGH);

	MAX7219_SendData(0x09,0xFF); //Decode-Mode Register Examples (Address (Hex) = 0xX9) Code B decode for digits 7–0 =0XFF
	MAX7219_SendData(0x0A,0x0F); //Intensity Register Format (Address (Hex) = 0xXA) 15/16 31/32 (max on) =0x0F
	MAX7219_SendData(0x0B,0x07); //Scan-Limit Register Format (Address (Hex) = 0xXB) Display digits 0 1 2 3 4 5 6 7 =0x07
	MAX7219_SendData(0x0C,0x01); //Shutdown Register Format (Address (Hex) = 0xXC) Normal Operation ==1

    /* Loop forever */
	for(;;){
		for(uint8_t i=1;i<9;i++){
			MAX7219_SendData(i,i-1);
			_delay_ms(1000);
		}
		MAX7219_SendData(1,0b1100);		_delay_ms(1000);
		MAX7219_SendData(2,0b1011);		_delay_ms(1000);
		MAX7219_SendData(3,0b1101);		_delay_ms(1000);
		MAX7219_SendData(4,0b1110);		_delay_ms(1000);
		MAX7219_SendData(5,0b1111);		_delay_ms(1000);





	}
}


