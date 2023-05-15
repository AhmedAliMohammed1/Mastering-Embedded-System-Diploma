/*
 * FIFO.h
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "Platform_Types.h"
#include <stdlib.h>
#include <stdio.h>

#define element_type usint8_t
#define NULL (void *)0
/*************User Data Type*************/
typedef struct {
	element_type length;
	element_type* head;
	element_type* base;
	element_type* tail;
	element_type count;

}FIFO_t;
typedef enum{

	FIFO_no_error,FIFO_FULL,FIFO_empty,FIFO_null
}FIFO_status;

/*************APIs*************/
FIFO_status FIFO_init(FIFO_t *FIFO,element_type *buff,element_type length);
FIFO_status FIFO_PUSH(FIFO_t *FIFO,element_type item);
FIFO_status FIFO_POP(FIFO_t *FIFO,element_type *item);
void FIFO_print(FIFO_t *FIFO);
#endif /* FIFO_H_ */
