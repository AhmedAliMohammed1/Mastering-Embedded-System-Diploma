/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "main.h"
/**================================================================
 * @Fn- Error_Handller
 * @brief - this fun shall to go in infinte loop if there is any thing wrong
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void Error_Handller(){
	while(1);
}

/**================================================================
 * @Fn- TSR_START
 * @brief - this fun shall to start the frame of TSR
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void TSR_START(void){
	MCAL_USART_SendData(TSR_UART_INSTANT, GR_TSR_FLAG_START);

}
/**================================================================
 * @Fn- TSR_Handller_TASK
 * @brief - this task shall to get the flags from the TSR and decide what sign should printed
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void TSR_Handller_TASK(){
	TSR_START();
	if(xQueueReceive(TSR__Flags_Queue,&GR_TSR_FLAG_OLED_FINAL,1)==pdTRUE){

		switch(GR_TSR_FLAG_OLED_FINAL){
		case 0x99:
			break;
		case 0x1:
			break;
		}
	}else{

	}

}
/**================================================================
 * @Fn- TSR_Flag_Read_TASK
 * @brief - this task shall to send the flags using queue to the handler
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void TSR_Flag_Read_TASK(){
	if(xQueueSend(TSR__Flags_Queue,&GR_TSR_FLAG_OLED_send,1)==pdTRUE){

	}else{

	}
}
/**================================================================
 * @Fn- TSR_call_Back
 * @brief - this task shall to get the flags PC using TSR_UART_INSTANT
 * to send the action through can bus to atmega
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void TSR_call_Back(void){
	static uint8_t i=0;
	if(	TSR_UART_INSTANT->SR &(1<<5)){
		GR_TSR_FLAG_rec=	MCAL_USART_ReciveData(TSR_UART_INSTANT);
		GR_TSR_FLAG_rec &=0x0F;

	}
	if(i<2)
	{
		//		MCAL_USART_SendData(TSR_UART_INSTANT,GR_TSR_FLAG_rec);
		GR_TSR_FLAG_OLED= (GR_TSR_FLAG_OLED<<4) | (GR_TSR_FLAG_rec);
		temp = ((GR_TSR_FLAG_OLED >>4) |((GR_TSR_FLAG_OLED <<4)));
		i++;

	}

	if(i>=2){
		i=0;
		GR_TSR_FLAG_OLED_send=(temp);
		GR_TSR_FLAG_OLED=0;
	}

}
/**================================================================
 * @Fn- TSR_init
 * @brief - this fun shall to init TSR
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void TSR_init(void){
	USART_Config_t UART1_CON={115200,EGHIT_BITS,Parity_DISABLE,Interrupt,ONE_STOP_BIT,Disabled,Asynchronous,TSR_call_Back};
	MCAL_USART_init(TSR_UART_INSTANT, &UART1_CON);
}
/**================================================================
 * @Fn- ACC_Handller_TASK
 * @brief - this task shall to get the distance form luna lidar and start
 * to send the action through can bus to atmega
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void ACC_Handller_TASK(){
	if(xQueueReceive(ACC__AMP_Queue,&ACC_AMP,1)==pdTRUE){
		if((ACC_AMP>=100) && (ACC_AMP<=65535) ){
			if(xQueueReceive(ACC__dis_Queue,&ACC_dis,1)==pdTRUE){
				if(ACC_dis <=200){
					// here should send CAN fram to atmega to stop the motor
					MCAL_write_PIN(GPIOA, PIN_0, 1);
				}else{
					MCAL_write_PIN(GPIOA, PIN_0, 0);

				}
			}
		}
		// if the Signal strength indicator not strong dequeue its disance value
		else{
			xQueueReceive(ACC__dis_Queue,&ACC_dis,1);
		}
	}else{

	}


}
/**================================================================
 * @Fn- ACC_LUNA_READ_TASK
 * @brief - this task shall to get distance from LIDAR using UART2
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void ACC_LUNA_READ_TASK(){
	if(xQueueSend(ACC__dis_Queue,&LUNA_dis,1)==pdTRUE){
		MCAL_USART_SendData(LUNA_UART_INSTANT, LUNA_dis);
		}else{

		}
	if(xQueueSend(ACC__AMP_Queue,&LUNA_AMP,1)==pdTRUE){
		MCAL_USART_SendData(LUNA_UART_INSTANT, LUNA_AMP);
		}else{

		}

}



void HW_init(){

	////////////*********TSR init***************//////////////////
	TSR_init();
	////////////*********LUNA_INIT***************//////////////////
	LUNA_INIT(CONTIOUS_RANGING_MODE,BYTE_9_CM);
	PIN_config PINx={PIN_0,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOA, &PINx);



}
int main(void)
{
	HW_init();
	if(xTaskCreate(TSR_Handller_TASK,"TSR_Handller_TASK",128,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}

	if(xTaskCreate(TSR_Flag_Read_TASK,"Read From UART1",128,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}
	if(xTaskCreate(ACC_Handller_TASK,"ACC_Handller_TASK",128,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}

	if(xTaskCreate(ACC_LUNA_READ_TASK,"LUNA READ",128,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}
	xSemaphore = xSemaphoreCreateBinary();
	TSR__Flags_Queue=xQueueCreate(10,sizeof(char));
	ACC__dis_Queue=xQueueCreate(10,sizeof(char));
	ACC__AMP_Queue=xQueueCreate(10,sizeof(char));

	vTaskStartScheduler();

	for(;;);
}
