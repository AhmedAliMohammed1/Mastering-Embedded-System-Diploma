/*
 * LIFO.c
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */


#include "LIFO.h"


LIFO_status LIFO_init(LIFO_t* LIFO,element_type* buff,element_type length)
{
	// check if buff exits or not
	if(buff == NULL)
		return LIFO_null;
	LIFO->base=buff;
	LIFO->head=buff;
	LIFO->length=length;
	LIFO->count=0;
	return LIFO_no_error;

}
LIFO_status LIFO_PUSH(LIFO_t* LIFO,element_type item)
{
	// check if lifo init befor or not
	if(!LIFO->base||!LIFO->head)
		return LIFO_null;
	// check if lifo is full or not
	if(LIFO->count == LIFO->length)
	return LIFO_FULL;
	*(LIFO->head)=item;
	LIFO->head++;
	LIFO->count++;
	return LIFO_no_error;
}
LIFO_status LIFO_POP(LIFO_t* LIFO,element_type* item){
	// check if lifo init befor or not
	if(!LIFO->base||!LIFO->head)
		return LIFO_null;
	if(LIFO->count == 0)
	return LIFO_empty;
	LIFO->head--;
	*item=*(LIFO->head);
	LIFO->count--;
	return LIFO_no_error;

}
