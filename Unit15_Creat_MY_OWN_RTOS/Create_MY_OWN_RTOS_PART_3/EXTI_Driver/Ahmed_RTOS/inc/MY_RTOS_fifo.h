/*
 * MY_RTOS_fifo.h
 *
 *  Created on: Nov 8, 2023
 *      Author: medoo
 */

#ifndef INC_MY_RTOS_FIFO_H_
#define INC_MY_RTOS_FIFO_H_


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
#include "scheduler.h"
#define element_type Task_sitting_t*
#define element_size Task_sitting_t
#define NULL (void *)0
/*************User Data Type*************/
typedef struct {
	uint32_t length;
	element_type* head;
	element_type* base;
	element_type* tail;
	uint32_t count;

}FIFO_t;
typedef enum{

	FIFO_no_error,FIFO_FULL,FIFO_empty,FIFO_null
}FIFO_status;

/*************APIs*************/
FIFO_status FIFO_init(FIFO_t *FIFO,element_type *buff,uint32_t length);
FIFO_status FIFO_PUSH(FIFO_t *FIFO,element_type item);
FIFO_status FIFO_POP(FIFO_t *FIFO,element_type *item);
void FIFO_print(FIFO_t *FIFO);
#endif /* FIFO_H_ */

#endif /* INC_MY_RTOS_FIFO_H_ */
