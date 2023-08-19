/*
 * i2c.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Ahmed
 */

#ifndef I2C_H_
#define I2C_H_
#include <stdint.h>
#include <avr/io.h>
#include <math.h>
#define START_condition_DONE 0x08
#define repeated_START_condition_DONE 0x10
#define SLA_W_DONE 0x18
#define SLA_W_NOT_DONE 0x20
#define SLA_R_DONE 0x40
#define Data_transmitted_DONE 0x28
#define Data_received_DONE 0x50
#define Data_transmitted_NOT_DONE 0x30
#define ERROR 0
#define Send_DONE 1
typedef enum{
	Prescaler_1,Prescaler_4,Prescaler_16,Prescaler_64
}Prescaler_rate;
typedef enum{
	Bit_100KH,Bit_200KH,Bit_300KH,Bit_400KH
}Bit_rate;
typedef struct {
	Prescaler_rate PR;
	Bit_rate BR;
}I2C_config_t;

void I2C_init(void);
uint8_t I2C_PACKET_TRANSSEMET(uint8_t slave_address,uint8_t data);
uint8_t I2C_PACKET_Recive(uint8_t slave_address,uint8_t *data);

uint8_t Slave_Send_Data(uint8_t slave_address,uint8_t data);
uint8_t Master_Recive_Data(uint8_t slave_address,uint8_t *data);

#endif /* I2C_H_ */
