/*
 * spi.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Ahmed
 */

#ifndef SPI_H_
#define SPI_H_
/*INC*/
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

/*USER DEFINED DATA TYPES*/
typedef enum{
	Interrupt_Disable,Interrupt_Enable
}SPI_Interrupt_Enable;
typedef enum{
	Disable,Enable
}SPI_Enable;

typedef enum{
	Slave,Master
}SPI_Master_Slave_Select;
typedef enum{
	Rising,Falling
}SPI_Clock_Polarity;

typedef enum{
	F_CPU_4,F_CPU_16,F_CPU_64,F_CPU_128,F_CPU_2,F_CPU_8,F_CPU_32,F_CPU_64_2,
}SPI_SCK_rate;

typedef struct{
	SPI_Enable EN;
	SPI_Interrupt_Enable IN_EN;
	SPI_Master_Slave_Select M_S; // select master or slave
	SPI_Clock_Polarity R_F; // select falling or
	SPI_SCK_rate clock;
	void (* callback_fun)(void);
}SPI_config_t;
#define NULL (void *)0
/***************APIs***************/
void MCAL_SPI_init(SPI_config_t * SPI);
void MCAL_SPI_SendData(uint8_t data);
uint8_t MCAL_SPI_ReciveData(uint8_t data);


#endif /* SPI_H_ */
