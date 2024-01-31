/*
 * main.h
 *
 *  Created on: Jan 31, 2024
 *      Author: medoo
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>
#include "FreeRTOS.h"
#include "USART_Driver.h"
#include "LUNA_LIDAR.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"
#define TSR_UART_INSTANT USART1

//////////***********extern***********//////////
extern uint16_t LUNA_dis;
extern uint16_t LUNA_AMP;
extern uint16_t LUNA_TEMP;
extern uint8_t LUNA_CheckSum;
//////////***********Semaphore***********//////////
SemaphoreHandle_t xSemaphore;
//////////***********Queue***********//////////
QueueHandle_t TSR__Flags_Queue;
QueueHandle_t ACC__dis_Queue;
QueueHandle_t ACC__AMP_Queue;

//////////***********Var***********//////////
uint8_t GR_TSR_FLAG_rec=0;
uint8_t GR_TSR_FLAG_OLED=0;
uint8_t GR_TSR_FLAG_OLED_send=0;
uint8_t GR_TSR_FLAG_OLED_FINAL=0;
uint8_t temp=0;
uint8_t GR_TSR_FLAG_START=0xFF;
		/*****************************************/
uint16_t ACC_dis=0;
uint16_t ACC_AMP=0;


#endif /* MAIN_H_ */
