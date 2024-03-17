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
/*#############################################################################################################################


#     ____ ____      _    ____  _   _   _  _____ ___ ___  _   _      ____  ____   ___      _ _____ ____ _____
#    / ___|  _ \    / \  |  _ \| | | | / \|_   _|_ _/ _ \| \ | |    |  _ \|  _ \ / _ \    | | ____/ ___|_   _|
#   | |  _| |_) |  / _ \ | | | | | | |/ _ \ | |  | | | | |  \| |    | |_) | |_) | | | |_  | |  _|| |     | |
#   | |_| |  _ <  / ___ \| |_| | |_| / ___ \| |  | | |_| | |\  |    |  __/|  _ <| |_| | |_| | |__| |___  | |
#    \____|_| \_\/_/   \_\____/ \___/_/   \_\_| |___\___/|_| \_|    |_|   |_| \_\\___/ \___/|_____\____| |_|

#    _____ ____ ___ _____ ____   ___  _   _ ___ ____ ____             ____ ____      _    _____ _____ _____ ____  ____
#   | ____/ ___/ _ \_   _|  _ \ / _ \| \ | |_ _/ ___/ ___|           / ___|  _ \    / \  |  ___|_   _| ____|  _ \/ ___|
#   |  _|| |  | | | || | | |_) | | | |  \| || | |   \___ \          | |   | |_) |  / _ \ | |_    | | |  _| | |_) \___ \
#   | |__| |__| |_| || | |  _ <| |_| | |\  || | |___ ___) |         | |___|  _ <  / ___ \|  _|   | | | |___|  _ < ___) |
#   |_____\____\___/ |_| |_| \_\\___/|_| \_|___\____|____/           \____|_| \_\/_/   \_\_|     |_| |_____|_| \_\____/


 */
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


void Sys_Clk_init(){
	// system speed 28Mhz
	RCC->CFGR |=(0b0101 <<18); //1111: PLL input clock x 16
	//	RCC->CFGR |=(0b100<<8); //100: HCLK divided by 2
	//	RCC->CFGR |=(1 <<16); //PLL entry clock source
	//	RCC->CR|=(1<<16); //HSE clock enable

	RCC->CR|=(1<<24); //PLL ON
	RCC->CFGR |=(0b10 <<0); //10: PLL selected as system clock

}







/************DMS TASK*************/
/************DMS TASK*************/
/************DMS TASK*************/
/************DMS TASK*************/
/************DMS TASK*************/


void DMS_Handller_TASK(){
	while(1){
		if(xSemaphoreTake(DMS_Semaphore,5) ==pdTRUE){
			// here the action would take
			MCAL_USART_SendData(TSR_UART_INSTANT, DMS_TAKE_ACTION);
		}else{
			MCAL_USART_SendData(TSR_UART_INSTANT, DMS_Release_ACTION);
		}

	}
}
void DMS_read_TASK(){
	while(1){
		if(DMS_read() ==0){
			xSemaphoreGive(DMS_Semaphore);
		}

	}
}


/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/














/************ACC TASK*************/
/************ACC TASK*************/
/************ACC TASK*************/
/************ACC TASK*************/
/************ACC TASK*************/








uint16_t ACC_THROTTEL_DATA=0x00;
uint8_t  ACC_DICIMAL_VAL=0;
void ACC_ADC_CallBack(){
	ADC_read(ADC1,ACC_THROTTEL_CHx,&ACC_THROTTEL_DATA);

}

void ACC_throtel_init(){
	ADC_Analog_WDG AWDG={0,0,0,0};
	ADC_CONFIG config={ACC_THROTTEL_CHx,ADC_Continuous_conversion,ADC_1_5_cycles,ADC_Polling,&AWDG,ACC_ADC_CallBack};
	ADC_init(ADC1,&config);
	//	ADC_interrupt_Enable(ADC1);
	PIN_config PINx={ACC_BOTTON_PIN,INPUT_PD,0};
	MCAL_GPIO_init(ACC_BOTTON_PORT, &PINx);

}
void ACC_DAC_init(){
	PIN_config PINx={ACC_DAC_0,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOA, &PINx);
	PINx=(PIN_config){ACC_DAC_1,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOB, &PINx);
	PINx=(PIN_config){ACC_DAC_2,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOB, &PINx);
	PINx=(PIN_config){ACC_DAC_3,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOB, &PINx);
	PINx=(PIN_config){ACC_DAC_4,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOB, &PINx);
	PINx=(PIN_config){ACC_DAC_5,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOB, &PINx);
	PINx=(PIN_config){ACC_DAC_6,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOB, &PINx);
	PINx=(PIN_config){ACC_DAC_7,OUTPUT_PP,SPEED_10};
	MCAL_GPIO_init(GPIOB, &PINx);

}


/**================================================================
 * @Fn- TSR_START
 * @brief - this fun shall to start the frame of TSR
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */



void ACC_FROM_ADC_TO_DAC(uint16_t decimal_val){

	//	uint16_t PWM_V=(uint16_t)(((ADC_VAL-ACC_TROTTEL_MIN_ADC_VAL)*100)/(ACC_TROTTEL_Max_ADC_VAL_shifted));
	/*MY CLOCK IS 28Mhz so i the prescaler will be 27
	 * and i need to proudce and it will make tick every 1us and i need 3KHZ PWM so the ARR= will be 333.33
	 * */
	//	PWM_V=((PWM_V*35)/100);
	MCAL_write_PIN(GPIOA, ACC_DAC_0, ((decimal_val >>0) &1));
	MCAL_write_PIN(GPIOB, ACC_DAC_1, ((decimal_val >>1) &1));
	MCAL_write_PIN(GPIOB, ACC_DAC_2, ((decimal_val >>2) &1));
	MCAL_write_PIN(GPIOB, ACC_DAC_3, ((decimal_val >>3) &1));
	MCAL_write_PIN(GPIOB, ACC_DAC_4, ((decimal_val >>4) &1));
	MCAL_write_PIN(GPIOB, ACC_DAC_5, ((decimal_val >>5) &1));
	MCAL_write_PIN(GPIOB, ACC_DAC_6, ((decimal_val >>6) &1));
	MCAL_write_PIN(GPIOB, ACC_DAC_7, ((decimal_val >>7) &1));

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
	while(1){

//			ACC_AMP=500;
			if((LUNA_AMP>=100) && (LUNA_AMP<=65535) ){
					if(LUNA_dis <= Distance_SET){
						// here should send CAN fram to atmega to stop the motor
						ACC_ACTION=ACC_CAR_STOP;

					}else if((LUNA_dis > Distance_SET) &&(LUNA_dis <MAX_Distance_SET)){
						ACC_ACTION=ACC_CAR_SLOW_DOWN;


					}else{
						ACC_ACTION=ACC_CAR_GO;

					}


			}
			// if the Signal strength indicator not strong dequeue its disance value
			else{
			}
		}
	}




/**================================================================
 * @Fn- ACC_throttel_Handller_TASK
 * @brief - this task shall to SEND the volt to the motor drive
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */

void ACC_throttel_Handller_TASK(){
	uint8_t ACC_counter=0;
	uint16_t ADC_to_send=0,ADC_SAVED=0;
	while(1){

		if(ACC_ST==ACC_ON){
			if(ACC_counter ==0){
				ADC_SAVED=ACC_THROTTEL_DATA;
				ACC_counter++;
			}
			if(ADC_SAVED<ACC_THROTTEL_DATA){
				ACC_FROM_ADC_TO_DAC(ACC_DICIMAL_VAL);

			}else{
				if(ACC_ACTION ==ACC_CAR_STOP){
					ACC_FROM_ADC_TO_DAC(ACC_DAC_MIN_DECIMAL);
				}else if(ACC_ACTION ==ACC_CAR_SLOW_DOWN){

					ACC_FROM_ADC_TO_DAC((ACC_DICIMAL_VAL/2));
				}else if(ACC_ACTION ==ACC_CAR_GO){
					ACC_FROM_ADC_TO_DAC(ACC_DICIMAL_VAL);

				}
			}


		}else if(ACC_ST==ACC_OFF){
			ACC_counter=0;
			if(ACC_ACTION ==ACC_CAR_STOP){
				ACC_FROM_ADC_TO_DAC(ACC_DAC_MIN_DECIMAL);
			}else if(ACC_ACTION ==ACC_CAR_SLOW_DOWN){
				ACC_FROM_ADC_TO_DAC((ACC_DICIMAL_VAL/2));
			}else if(ACC_ACTION ==ACC_CAR_GO){
				ACC_FROM_ADC_TO_DAC(ACC_DICIMAL_VAL);
			}
		}

	}
}
/**================================================================
 * @Fn- ACC_throttel_Handller_TASK
 * @brief - this task shall to get if the ACC is on or not
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */

void ACC_STATE_READ_TASK(){
	while(1){

		ACC_ST=MCAL_Read_PIN(ACC_BOTTON_PORT, ACC_BOTTON_PIN);
		ADC_read(ADC1,ACC_THROTTEL_CHx,&ACC_THROTTEL_DATA);
		if(ACC_THROTTEL_DATA<ACC_TROTTEL_MIN_ADC_VAL){
			ACC_DICIMAL_VAL=64;
		}else if(ACC_THROTTEL_DATA>ACC_TROTTEL_Max_ADC_VAL){
			ACC_DICIMAL_VAL=255;
		}

		else{
//		uint32_t step1=((uint32_t)(ACC_THROTTEL_DATA-ACC_TROTTEL_MIN_ADC_VAL)*(ACC_DAC_MAX_DECIMAL-ACC_DAC_MIN_DECIMAL)); //884.3
//		uint32_t step2=(ACC_TROTTEL_Max_ADC_VAL-ACC_TROTTEL_MIN_ADC_VAL);//1539
//		uint32_t step3=(step1/step2);
//		ACC_DICIMAL_VAL=step3+ACC_DAC_MIN_DECIMAL;
		ACC_DICIMAL_VAL=((((ACC_THROTTEL_DATA-ACC_TROTTEL_MIN_ADC_VAL)*(ACC_DAC_MAX_DECIMAL-ACC_DAC_MIN_DECIMAL))/(ACC_TROTTEL_Max_ADC_VAL-ACC_TROTTEL_MIN_ADC_VAL))+ACC_DAC_MIN_DECIMAL);
		}
	}
}
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/












/************TSR TASK*************/
/************TSR TASK*************/
/************TSR TASK*************/
/************TSR TASK*************/






/**================================================================
 * @Fn- TSR_Handller_TASK
 * @brief - this task shall to get the flags from the TSR and decide what sign should printed
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void TSR_Handller_TASK(){
  while(1){
//	  if(GR_TSR_FLAG_OLED_send !=0x99){
	  vTaskPrioritySet(TSR_Handller_TASK_Handle,4);
      TFT_send_image(GR_TSR_FLAG_OLED_send);
	  vTaskPrioritySet(TSR_Handller_TASK_Handle,2);
//	  }
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
	if(  USART1->SR &(1<<5)){
		PC_Uart_Flag=  MCAL_USART_ReciveData(USART1);


	}


//	MCAL_USART_SendData(USART1, PC_Uart_Flag);
	/*
	  0x38 0x2A
	  0x0038
	  0x0008

	  0x0000 | 0x0008
	  0x0008
	 */
	switch(PC_Uart_Flag){
	case '#':
		TSR_START_Flag=1;
		TSR_END_Flag=0;
		break;
	case '*':
		TSR_END_Flag=1;
		break;
	case 0x2F:
		FACE_START_Flag=1;
		FACE_END_Flag=0;
		break;
	case 0x2B:
		FACE_END_Flag=1;
		break;
	}



	if (FACE_START_Flag){
		if(PC_Counter ==0)
			PC_Uart_Flag=0;

		if(FACE_END_Flag ==0){
			GR_FACE_FLAG_ = (GR_FACE_FLAG_<<8)| PC_Uart_Flag;
			PC_Counter++;
			/*
			 * 0x0000 | 0x2F =0x
			 *
			 * */

		}else{
			GR_FACE_FLAG_ &=0x0F0F;
			GR_FACE_FLAG_send = ((GR_FACE_FLAG_ &0x0F00)>>4) |((GR_FACE_FLAG_&0x000F));
			GR_FACE_FLAG_=0;

			///////////////
			FACE_START_Flag=0;
			FACE_END_Flag=0;
			PC_Counter=0;
		}
	}
	if(TSR_START_Flag){
		if(PC_Counter ==0)
			PC_Uart_Flag=0;

		if(TSR_END_Flag ==0){
			GR_TSR_FLAG_OLED = (GR_TSR_FLAG_OLED<<8)| PC_Uart_Flag;
			PC_Counter++;


		}else{
			GR_TSR_FLAG_OLED &=0x0F0F;
			GR_TSR_FLAG_OLED_send = ((GR_TSR_FLAG_OLED &0x0F00)>>4) |((GR_TSR_FLAG_OLED&0x000F));
			GR_TSR_FLAG_OLED=0;
			///////////////
			TSR_END_Flag=0;
			TSR_START_Flag=0;
			PC_Counter=0;


		}
	}










	//  if(PC_Uart_Flag != '*'){
	//    GR_TSR_FLAG_OLED = (GR_TSR_FLAG_OLED<<8)| PC_Uart_Flag;
	//  }else{
	//    GR_TSR_FLAG_OLED &=0x0F0F;
	//    GR_TSR_FLAG_OLED_send = ((GR_TSR_FLAG_OLED &0x0F00)>>4) |((GR_TSR_FLAG_OLED&0x000F));
	//    GR_TSR_FLAG_OLED=0;
	//
	//  }


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

/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/









/************FACE ID TASK*************/
/************FACE ID TASK*************/
/************FACE ID TASK*************/

void CAR_ON_Handler(){
	if((MCAL_Read_PIN(GPIOB, PIN_1)==0) ){
		_TIM1_delay_ms(30);
		if((MCAL_Read_PIN(GPIOB, PIN_1)==0) ){

			if(CAR_ON_counter ==1 &&GR_FACE_FLAG_send !=0x99&&GR_FACE_FLAG_send !=0x00){
//				MCAL_USART_Deinit(LUNA_UART_INSTANT);
//				NVIC_ISER1 |=(1<<(USART1_IRQ-32));
				CAR_ON_counter=0;
				GR_FACE_FLAG_send=0;
				CAR_login_counter=0;
				//UART SEND
				ACC_FROM_ADC_TO_DAC(ACC_DAC_MIN_DECIMAL);
				MCAL_USART_SendData(TSR_UART_INSTANT,CAR_OFF_FLAG);
				vTaskResume(FACE_ID_TASK_Handle);

			}
		}

	}


}
void CAR_ON_init(){
	EXTI_config_t CAR_BOTTON_SITTING={EXT1PB1,FALLING,ENABLE,CAR_ON_Handler};
	MCAL_EXTI_init(&CAR_BOTTON_SITTING);
	PIN_config pin={PIN_1,INPUT_PD};
	MCAL_GPIO_init(GPIOB, &pin);
}
void FACE_ID_TASK(){
	while(1){

		if((MCAL_Read_PIN(GPIOB, PIN_1)==1) ){
			_TIM1_delay_ms(30);
			if((MCAL_Read_PIN(GPIOB, PIN_1)==1) ){
			//UART SEND

//				MCAL_USART_Deinit(LUNA_UART_INSTANT);
				if(CAR_login_counter==0){
					MCAL_USART_SendData(TSR_UART_INSTANT,CAR_ON_FLAG);
					CAR_login_counter++;
				}
//				if(GR_FACE_FLAG_send ==0x99){
//					MCAL_USART_SendData(TSR_UART_INSTANT,CAR_OFF_FLAG);
//
//				}
			if(GR_FACE_FLAG_send !=0x99 && GR_FACE_FLAG_send !=0x00){
				CAR_ON_counter=1;
				CAR_login_counter=0;
//				////////////*********LUNA_INIT***************//////////////////
//				LUNA_INIT(CONTIOUS_RANGING_MODE,BYTE_9_CM);
//				LUNA_ENABLE();
				vTaskSuspend(FACE_ID_TASK_Handle);


			}
		}
		}else{
			//			MCAL_write_PIN(GPIOB, PIN_13, 0);
						CAR_login_counter=0;
					}
	}
}


/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/
/***********************************/










void HW_init(){
	Sys_Clk_init();
	////////////*********TFT_init***************//////////////////
	TFT_init(RGB_5_6_5);
	////////////*********TSR init***************//////////////////
	TSR_init();

	////////////*********ACC_throtel_init*********//////////////////
	ACC_throtel_init();
	////////////*********DAC init***************//////////////////
	ACC_DAC_init();
	////////////*********DMS_init***************//////////////////
	DMS_init();
	////////////*********CAR_ON_init***************//////////////////
	CAR_ON_init();
	////////////*********LUNA_INIT***************//////////////////
	LUNA_INIT(CONTIOUS_RANGING_MODE,BYTE_9_CM);


//	PIN_config PINx={PIN_13,OUTPUT_PP,SPEED_10};
//	MCAL_GPIO_init(GPIOB, &PINx);



}
int main(void)
{
	HW_init();
	///////////////////////////
	if(xTaskCreate(ACC_throttel_Handller_TASK,"ACC_throttel_Handller_TASK",256,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}

	if(xTaskCreate(ACC_Handller_TASK,"ACC_Handller_TASK",256,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}


	if(xTaskCreate(ACC_STATE_READ_TASK,"BOTTON_READ",256,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}
	///////////////////////

	if(xTaskCreate(TSR_Handller_TASK,"TSR_Handller_TASK",256,NULL,2,&TSR_Handller_TASK_Handle)!=pdPASS ){
		Error_Handller();
	}

	///////////////////////

	if(xTaskCreate(DMS_Handller_TASK,"DMS_Handller_TASK",256,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}

	if(xTaskCreate(DMS_read_TASK,"DMS_read_TASK",256,NULL,2,NULL)!=pdPASS ){
		Error_Handller();
	}
	///////////////////////
	if(xTaskCreate(FACE_ID_TASK,"FACE_ID_TASK",256,NULL,5,&FACE_ID_TASK_Handle)!=pdPASS ){
		Error_Handller();
	}


	DMS_Semaphore = xSemaphoreCreateBinary();
	TSR__Flags_Queue=xQueueCreate(10,sizeof(char));

	vTaskStartScheduler();

	for(;;);
}
