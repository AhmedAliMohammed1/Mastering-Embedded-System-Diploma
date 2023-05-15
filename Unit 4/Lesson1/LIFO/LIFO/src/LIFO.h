/*
 * LIFO.h
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "Platform_Types.h"
#include <stdlib.h>

#define element_type usint8_t
#define NULL (void *)0
/*************User Data Type*************/
typedef struct {
	element_type length;
	element_type* head;
	element_type* base;
	element_type count;

}LIFO_t;

typedef enum{

	LIFO_no_error,LIFO_FULL,LIFO_empty,LIFO_null
}LIFO_status;

/*************APIs*************/
LIFO_status LIFO_init(LIFO_t* LIFO,element_type* buff,element_type length);
LIFO_status LIFO_PUSH(LIFO_t* LIFO,element_type item);
LIFO_status LIFO_POP(LIFO_t* LIFO,element_type* item);



#endif /* LIFO_H_ */
