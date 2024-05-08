/*
 * main.h
 *
 *  Created on: Jan 31, 2024
 *      Author: medoo
 */

#ifndef MAIN_H_
#define MAIN_H_
//////////***********includes***********//////////
#include <stdint.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"
#include "ADC.h"
#include "GP_Timers.h"
#include "GPIO_Driver.h"
#include "EXTI_Driver.h"
#include "Timer1_8.h"
#include "LCD.h"
//////////***********defines***********//////////
#define A1 PIN_1
#define A2 PIN_2
#define B1 PIN_3
#define B2 PIN_4

#define Stepper_GPIO GPIOA
/////////////////////////////
#define THROTTEL_CHx 0
uint16_t THROTTEL_DATA=0x00;
uint16_t speed=1000;
typedef enum{CCW,CW}STEPPER_DIR;
STEPPER_DIR DIR=CCW;
#define DIR_PIN PIN_13
#define DIR_PORT GPIOB
////////////////////HALL EFFECT EDIT //////////////////////
#define HALL_EFFECT_TIMx_instant TIM4
#define HALL_EFFECT_EXTI_PIN PIN_12
#define HALL_EFFECT_EXTI_PORT GPIOB
#define HALL_EFFECT_EXTI_LINE EXT12PB12
#define MOTOR_SHAFT_RADIUS 4 //mM
#define  HALL_EFFECT_REV_PER_PULSES 1
#define PI 314  //PI=3.14159 *1000
#define  HALL_EFFECT_TIME_CONVERSION 1 // TAKE TIME EVERY 1 s
uint8_t HALL_TIMER_EN=0;
uint32_t HALL_EFFECT_COUNTER=0;
uint32_t HALL_EFFECT_N_PULSES=0; //NOTE IN THIS CASE HALL_EFFECT_N_PULSES = HALL_EFFECT_RPS
uint32_t HALL_EFFECT_RPS=0;
uint32_t HALL_EFFECT_RPM=0;
uint32_t HALL_EFFECT_mM_s=0;



TaskHandle_t STEPPER_Handller_;
TaskHandle_t READ_Handller_;
TaskHandle_t LCD_Handller_;
TaskHandle_t Welcome_TASK_Handller_;




#endif /* MAIN_H_ */
