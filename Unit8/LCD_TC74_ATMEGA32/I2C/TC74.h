/*
 * TC74.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed
 */

#ifndef TC74_H_
#define TC74_H_
#include "i2c.h"



void TC74_WRITE_ON_REG(uint8_t reg_add,uint8_t data);
void TC74_Read_TEMP(uint8_t *data);


#endif /* TC74_H_ */
