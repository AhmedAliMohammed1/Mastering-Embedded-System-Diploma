/*
 * STM32F103x6.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Ahmed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//-----------------------------
//Includes
//-----------------------------
#include <Platform_Types.h>
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE 	0x08000000UL
#define SYS_MEMORY_BASE 	0x1FFFF000UL
#define SRAM_MEMORY_BASE 	0x20000000UL


//-----------------------------
//Base addresses for  AHB BUS Peripherals
//-----------------------------
#define RCC_BASE 0x40021000
//-----------------------------
//Base addresses for  AHB BUS Peripherals
//-----------------------------
//-----------------------------
//Base addresses for  APB2 BUS Peripherals
//-----------------------------
#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
#define GPIOC_BASE 0x40011000
#define GPIOD_BASE 0x40011400
#define GPIOE_BASE 0x40011800
#define GPIOF_BASE 0x40011C00
#define GPIOG_BASE 0x40012000
#define EXTI_BASE  0x40010400
#define AFIO_BASE  0x40010000

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	vusint32_t CRL;
	vusint32_t CRH;
	vusint32_t IDR;
	vusint32_t ODR;
	vusint32_t BSRR;
	vusint32_t BRR;
	vusint32_t LCKR;
}GPIOx_REG;
typedef struct {
	vusint32_t EVCR;
	vusint32_t MAPR;
	vusint32_t EXTICR1;
	vusint32_t EXTICR2;
	vusint32_t EXTICR3;
	vusint32_t EXTICR4;
	usint32_t RESERVED;
	vusint32_t MAPR2;
}AFIOx_REG;
typedef struct {
	vusint32_t IMR;
	vusint32_t EMR;
	vusint32_t RTSR;
	vusint32_t FTSR;
	vusint32_t SWIER;
	vusint32_t PR;
}EXTI_REG;
typedef struct{
	vusint32_t CR;
	vusint32_t CFGR;
	vusint32_t CIR;
	vusint32_t APB2RSTR;
	vusint32_t APB1RSTR;
	vusint32_t AHBENR;
	vusint32_t APB2ENR;
	vusint32_t APB1ENR;
	vusint32_t BDCR;
	vusint32_t CSR;
	vusint32_t AHBSTR;
	vusint32_t CFGR2;
}RCC_REG;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA		((GPIOx_REG *) GPIOA_BASE)
#define GPIOB		((GPIOx_REG *) GPIOB_BASE)
#define GPIOC		((GPIOx_REG *) GPIOC_BASE)
#define GPIOD		((GPIOx_REG *) GPIOD_BASE)
#define GPIOE		((GPIOx_REG *) GPIOE_BASE)
#define GPIOF		((GPIOx_REG *) GPIOF_BASE)
#define GPIOG		((GPIOx_REG *) GPIOG_BASE)
#define RCC   		((RCC_REG   *)  RCC_BASE )
#define EXTI_REG	((EXTI_REG  *)  EXTI_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103X6_H_ */
