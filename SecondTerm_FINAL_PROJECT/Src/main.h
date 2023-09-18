/*
 * main.h
 *
 *  Created on: Sep 15, 2023
 *      Author: medoo
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "LCD.h"
#include "KEYPAD.h"
void ALL_PREPHRAL_Init(void);
void ADMIN_OLD_PASSWORD_CHECK();
void ADMIN_ENTER_PASSWORD();
void ADMIN_CREATE_PASSWORD();
uint8_t ADMIN_PASSWORD_CHECK(uint8_t *data);
uint8_t ADMIN_mian_menu();
void USER_RFID_ENTER();
void USART1_call_Back(void);
void USART2_call_Back(void);
void EXTI_ENTRY_GATE();
void EXTI_EXIT_GATE();
void USER_RFID_EXIT();
#endif /* MAIN_H_ */
