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
#define NULL ((void *) 0)

//-----------------------------
//Base addresses for  AHB BUS Peripherals
//-----------------------------
#define RCC_BASE 0x40021000
//-----------------------------
//Base addresses for  APB1 BUS Peripherals

//-----------------------------
#define SPI2_BASE	0x40003800
#define SPI3_BASE	0x40003C00

//-----------------------------
//Base addresses for  APB2 BUS Peripherals
//-----------------------------
#define GPIOA_BASE 	0x40010800
#define GPIOB_BASE 	0x40010C00
#define GPIOC_BASE 	0x40011000
#define GPIOD_BASE 	0x40011400
#define GPIOE_BASE 	0x40011800
#define GPIOF_BASE 	0x40011C00
#define GPIOG_BASE 	0x40012000
#define EXTI_BASE  	0x40010400
#define AFIO_BASE  	0x40010000
#define USART1_BASE	0x40013800
#define USART2_BASE 0x40004400
#define USART3_BASE 0x40004800
#define SPI1_BASE	0x40013000

#define SysTick_BASE  0xE000E010
#define NVIC_BASE 	0xE000E100
#define NVIC_ISER0 *((vusint32_t *) (NVIC_BASE+0x00))
#define NVIC_ISER1 *((vusint32_t *) (NVIC_BASE+0x04))
#define NVIC_ISER2 *((vusint32_t *) (NVIC_BASE+0x08))
#define NVIC_ICER0 *((vusint32_t *) (NVIC_BASE+0x080))
#define NVIC_ICER1 *((vusint32_t *) (NVIC_BASE+0x084))
#define NVIC_ICER2 *((vusint32_t *) (NVIC_BASE+0x088))

#define STK_LOAD *((vusint32_t *) (SysTick_BASE+0x04))
#define STK_VALUE *((vusint32_t *) (SysTick_BASE+0x04))
#define STK_CTRL *((vusint32_t * )(SysTick_BASE+0x00))

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
	vusint32_t EXTICR[4];
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
typedef struct{
	vusint32_t SR;
	vusint32_t DR;
	vusint32_t BRR;
	vusint32_t CR1;
	vusint32_t CR2;
	vusint32_t CR3;
	vusint32_t GTPR;

}USART_REG;
typedef union{
	vusint32_t ALL_REG;
	 struct 	CR1_BITS{
		vusint32_t CPHA:1;
		vusint32_t CPOL:1;
		vusint32_t MSTR:1;
		vusint32_t BR:3;
		vusint32_t SPE:1;
		vusint32_t LSBFIRST:1;
		vusint32_t SSI:1;
		vusint32_t SSM:1;
		vusint32_t RXONLY:1;
		vusint32_t DFF:1;
		vusint32_t CRCNEXT:1;
		vusint32_t CRCEN:1;
		vusint32_t BIDIOE:1;
		vusint32_t BIDIMODE:1;
//		vusint32_t Reserved:16;
	}Bit_Name;
}CR1;
typedef union{
	vusint32_t ALL_REG;
	 struct 	CR2_BITS{
		vusint32_t RXDMAEN:1;
		vusint32_t TXDMAEN:1;
		vusint32_t SSOE:1;
		vusint32_t Reserved:2;
		vusint32_t ERRIE:1;
		vusint32_t RXNEIE:1;
		vusint32_t TXEIE:1;
//		vusint32_t Reserved1:24;

	}Bit_Name;
}CR2;
typedef union{
	vusint32_t ALL_REG;
	 struct 	SR_BITS{
		vusint32_t RXNE:1;
		vusint32_t TXE:1;
		vusint32_t CHSIDE:1;
		vusint32_t UDR:1;
		vusint32_t CRCERR:1;
		vusint32_t MODF:1;
		vusint32_t OVR:1;
		vusint32_t BSY:1;
//		vusint32_t Reserved:24;

	}Bit_Name;
}SR;
typedef union{
	vusint32_t ALL_REG;
	 struct 	DR_BITS{
		vusint32_t DR0:1;
		vusint32_t DR1:1;
		vusint32_t DR2:1;
		vusint32_t DR3:1;
		vusint32_t DR4:1;
		vusint32_t DR5:1;
		vusint32_t DR6:1;
		vusint32_t DR7:1;
		vusint32_t DR8:1;
		vusint32_t DR9:1;
		vusint32_t DR10:1;
		vusint32_t DR11:1;
		vusint32_t DR12:1;
		vusint32_t DR13:1;
		vusint32_t DR14:1;
		vusint32_t DR15:1;
//		vusint32_t Reserved:16;
	}Bit_Name;
}DR;
typedef struct {
	volatile CR1  SPI_CR1;
	volatile CR2  SPI_CR2;
	volatile SR  SPI_SR;
	volatile DR DR_reg;
	vusint32_t CRCPR;
	vusint32_t RXCRCR;
	vusint32_t TXCRCR;
	vusint32_t I2SCFGR;
	vusint32_t I2SPR;

}SPI_Reg;


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
#define AFIO		((AFIOx_REG *) AFIO_BASE )
#define USART1		((USART_REG *) USART1_BASE)
#define USART2		((USART_REG *) USART2_BASE)
#define USART3		((USART_REG *) USART3_BASE)
#define SPI1		((SPI_Reg *) SPI1_BASE)
#define SPI2		((SPI_Reg *) SPI2_BASE)
#define SPI3		((SPI_Reg *) SPI3_BASE)
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103X6_H_ */
