/*
 * FIFO.c
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */
#include "MY_RTOS_fifo.h"
FIFO_status FIFO_init(FIFO_t *FIFO,element_type *buff,uint32_t length)
{
	if(buff==NULL)
		return FIFO_null;
	FIFO->base=buff;
	FIFO->head=buff;
	FIFO->tail=buff;
	FIFO->length=length;
	FIFO->count=0;
	return FIFO_no_error;

	}
FIFO_status FIFO_PUSH(FIFO_t *FIFO,element_type item)
{
	uint32_t size1= sizeof(element_type);
	uint32_t size2= (FIFO->length);
	uint32_t size =((uint32_t)(FIFO->base) + (size1*size2));
	//check if fifo has been init befor or not
	if(!FIFO->base || !FIFO->head || !FIFO->tail)
		return FIFO_null;
	//check if FIFO is full or not
	 if((FIFO->count==FIFO->length))
		 return FIFO_FULL;
	 if((FIFO->head < (element_type*)size)&(FIFO->count<=FIFO->length)){
	 *(FIFO->head)=item;
	 FIFO->head++;
	 FIFO->count++;
	 }else{
		 FIFO->head=FIFO->base;
		 *(FIFO->head)=item;
		 FIFO->head++;
		 FIFO->count++;
	 }
	 return FIFO_no_error;
	}
FIFO_status FIFO_POP(FIFO_t *FIFO,element_type *item)
{
	uint32_t size1= sizeof(element_type);
	uint32_t size2= (FIFO->length);
	uint32_t size =((uint32_t)(FIFO->base) + (size1*size2));
	//check if fifo has been init befor or not
	if(!FIFO->base || !FIFO->head || !FIFO->tail)
		return FIFO_null;
	//check if FIFO emty of not
	if(FIFO->count==0){
		 FIFO->head=FIFO->base;
		FIFO->tail=FIFO->base;
		return FIFO_empty;

	}
	if((FIFO->tail < (element_type*)size )&& (FIFO->count!=0)){
	*item=*(FIFO->tail);
	*(FIFO->tail)=0;
	FIFO->tail++;
	FIFO->count--;
	}else{
		FIFO->tail=FIFO->base;
		*item=*(FIFO->tail);
		*(FIFO->tail)=0;
		FIFO->tail++;
		FIFO->count--;
	}
	return FIFO_no_error;
	}

void FIFO_print(FIFO_t *FIFO)
{
	int i;
	element_type* temp= FIFO->tail;
	if(FIFO->count==0){
		printf("FIFO is EMPTY");
	}else{
	for(i=0;i<FIFO->count;i++){
		printf("FIFO elemnt is : %d\n",*temp);
	temp++;

	}
	}


}
