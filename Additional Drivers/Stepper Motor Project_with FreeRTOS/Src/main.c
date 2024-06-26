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
void Stepper_SET_DIR(uint8_t dir){
	switch(dir){
	case '+':
		MCAL_write_PIN(Stepper_GPIO, A1, 0);
		_TIM1_delay_ms(1);
		MCAL_write_PIN(Stepper_GPIO, A2, 0);		_TIM1_delay_ms(1);

		MCAL_write_PIN(Stepper_GPIO, B1, 1);		_TIM1_delay_ms(1);

		MCAL_write_PIN(Stepper_GPIO, B2, 0);		_TIM1_delay_ms(1);

		break;
	case '-':
		MCAL_write_PIN(Stepper_GPIO, A1, 1);		_TIM1_delay_ms(1);

		MCAL_write_PIN(Stepper_GPIO, A2, 0);		_TIM1_delay_ms(1);

		MCAL_write_PIN(Stepper_GPIO, B1, 0);		_TIM1_delay_ms(1);

		MCAL_write_PIN(Stepper_GPIO, B2, 0);		_TIM1_delay_ms(1);

		break;

	}
}
void Stepper_Pulses(uint16_t speed,uint32_t n_pulses){

	for(uint32_t i=0;i<n_pulses;i++){
	MCAL_TOGGLE_PIN(GPIOA, B1);
	//		_TIM1_delay_ms(1);

	MCAL_TOGGLE_PIN(GPIOA, B2);
	_TIM1_delay_us(speed);

	MCAL_TOGGLE_PIN(GPIOA, A1);
	//				_TIM1_delay_ms(1);

	MCAL_TOGGLE_PIN(GPIOA, A2);
	_TIM1_delay_us(speed);

	}
}
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
 * @Fn- Sys_Clk_init
 * @brief - this fun shall to select the system clock accourding to datasheet
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void Sys_Clk_init(){
	// system speed 36Mhz
	RCC->CFGR |=(0b0101 <<18); //1111: PLL input clock x 16
	//	RCC->CFGR |=(0b100<<8); //100: HCLK divided by 2
	//	RCC->CFGR |=(1 <<16); //PLL entry clock source
	//	RCC->CR|=(1<<16); //HSE clock enable

	RCC->CR|=(1<<24); //PLL ON
	RCC->CFGR |=(0b10 <<0); //10: PLL selected as system clock


}





/********************* HALL EFFECT *****************/
/**================================================================
 * @Fn- HALL_EFFECT_TIMER_ENABLE
 * @brief - this fun shall to enable and disable global variable every 1 sec to control other handler
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void HALL_EFFECT_TIMER_ENABLE(){
	HALL_TIMER_EN ^=1;

}
/**================================================================
 * @Fn- HALL_EFFECT_HANDLLER
 * @brief - this fun shall to get final speed of vichle using hall effect sensor and HALL_EFFECT_TIMER_ENABLE to calulate the time
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note- this fun called every rissing edege from hall effect sensor
 * and update the HALL_EFFECT_KM_H every 1sec and caluclate it from HALL_EFFECT_N_PULSES
 */
void HALL_EFFECT_HANDLLER(){
//	HALL_EFFECT_COUNTER++;

	if(HALL_TIMER_EN){
		HALL_EFFECT_COUNTER++;
	}else{
		if(HALL_EFFECT_COUNTER){
			HALL_EFFECT_N_PULSES=HALL_EFFECT_COUNTER;
			HALL_EFFECT_RPS=((HALL_EFFECT_N_PULSES*HALL_EFFECT_TIME_CONVERSION*1000)/HALL_EFFECT_REV_PER_PULSES*2);
			HALL_EFFECT_RPM=(HALL_EFFECT_RPS *60)/1000;
			//		_TIM1_delay_ms(1);
			HALL_EFFECT_mM_s=(2*PI*HALL_EFFECT_RPM*MOTOR_SHAFT_RADIUS)/(60*100);
			_TIM1_delay_ms(1);
			HALL_EFFECT_COUNTER=0;
		}
	}

}
/**================================================================
 * @Fn- HALL_EFECT_Init
 * @brief - this fun shall to init the hall effect EXTI and the timer that calulate the time
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */
void HALL_EFECT_Init(){
	{
		EXTI_config_t HALL_EFFECT_SITTING={HALL_EFFECT_EXTI_LINE,RISEING,ENABLE,HALL_EFFECT_HANDLLER};
		MCAL_EXTI_init(&HALL_EFFECT_SITTING);

	}
	_TIM1_delay_ms(10);
	{
		GP_TIMERx_config GP_sitting={(MCAL_GET_H_CLCK()/1000) // to get tick every 1ms
				,2000 //to get interrupt every 1SEC
				,0,0,INT_EN,NORMAL,HALL_EFFECT_TIMER_ENABLE};
		GP_TIMERx_NORMAL_config GP_sitting_NORMA={Up};
		GP_TIMx_start(HALL_EFFECT_TIMx_instant,&GP_sitting,&GP_sitting_NORMA);
	}

	_TIM1_delay_ms(10);


}


/**================================================================
 * @Fn- ACC_ADC_CallBack
 * @brief - this fun shall to read the ADC value if the ADC work with interrupt
 * @param [in] - void
 * @param [out] - void
 * @retval -
 * Note- the ADC must work as interrupt otherwise this fun will not work
 */
void ADC_Read(){
	ADC_read(ADC1,THROTTEL_CHx,&THROTTEL_DATA);

}
/**================================================================
 * @Fn- ACC_throtel_init
 * @brief - this fun shall to init the ACC( INIT ADC,ACC GPIO PIN)
 * @param [in] - void
 * @param [out] - void
 * @retval -
 * Note-
 */
void throtel_init(){
	ADC_Analog_WDG AWDG={0,0,0,0};
	ADC_CONFIG config={THROTTEL_CHx,ADC_Continuous_conversion,ADC_1_5_cycles,ADC_Polling,&AWDG,ADC_Read};
	ADC_init(ADC1,&config);
	//	ADC_interrupt_Enable(ADC1);
	PIN_config PINx={DIR_PIN,INPUT_PD,0};
	MCAL_GPIO_init(DIR_PORT, &PINx);

}







/**================================================================
 * @Fn- HW_init
 * @brief - this fun shall to all hardware and software periphrals
 * @param [in] - void
 * @param [out] - Void
 * @retval -
 * Note-
 */


void HW_init(){
	Sys_Clk_init();
	_TIM1_delay_ms(100);
	HALL_EFFECT_N_PULSES=0;
	HALL_EFFECT_RPS=0;
	HALL_EFFECT_RPM=0;
	//		_TIM1_delay_ms(1);
	HALL_EFFECT_mM_s=0;
	HALL_EFECT_Init();
	_TIM1_delay_ms(100);

	////////////*********LUNA_INIT***************//////////////////

	LCD_init();
	_TIM1_delay_ms(100);


	////////////*********ACC_throtel_init*********//////////////////
	throtel_init();
	_TIM1_delay_ms(100);
	////////////*********HALL_EFECT_Init***************//////////////////
	PIN_config pin={A1,OUTPUT_PP,SPEED_2};
	MCAL_GPIO_init(Stepper_GPIO, &pin);	_TIM1_delay_ms(10);

	pin=(PIN_config){A2,OUTPUT_PP,SPEED_2};
	MCAL_GPIO_init(Stepper_GPIO, &pin);	_TIM1_delay_ms(10);

	pin=(PIN_config){B1,OUTPUT_PP,SPEED_2};
	MCAL_GPIO_init(Stepper_GPIO, &pin);	_TIM1_delay_ms(10);

	pin=(PIN_config){B2,OUTPUT_PP,SPEED_2};
	MCAL_GPIO_init(Stepper_GPIO, &pin);	_TIM1_delay_ms(10);

	_TIM1_delay_ms(100);




}


void READ_TASK(){
	uint8_t ccw_counter=0,cw_counter=0;

	while(1){
		ADC_Read();
		if(MCAL_Read_PIN(DIR_PORT, DIR_PIN)){
			_TIM1_delay_ms(30);
			if(MCAL_Read_PIN(DIR_PORT, DIR_PIN)){
				DIR=CW;
			}
		}else{
			DIR=CCW;

		}
		speed=5000-((4000*THROTTEL_DATA)/4096);
		if(DIR==CW){
			ccw_counter=0;
		if(cw_counter==0){
			Stepper_SET_DIR('+');
			cw_counter++;
		}
		}else if(DIR==CCW){
			cw_counter=0;
			if(ccw_counter==0){
				Stepper_SET_DIR('-');
				ccw_counter++;
			}
		}
		    vTaskSuspend( READ_Handller_ );
	}
}
void STEPPER_Handller_TASK(){
	while(1){

//		vTaskPrioritySet(STEPPER_Handller_, 3);
		Stepper_Pulses(speed,300);
		  vTaskResume( READ_Handller_ );
		    vTaskSuspend( STEPPER_Handller_ );

//		vTaskPrioritySet(STEPPER_Handller_, 2);

	}
}
void LCD_SEND_DATA(){
	while(1){
		LCD_moveCURSER(0,4);
		if(HALL_EFFECT_RPM>=1000){
			LCD_intgerToString(HALL_EFFECT_RPM);

		}else{
			LCD_intgerToString(HALL_EFFECT_RPM);
			LCD_sendString("    ");

		}
		LCD_moveCURSER(1,2);
		if(HALL_EFFECT_mM_s>=100){
			LCD_intgerToString(HALL_EFFECT_mM_s);

		}else{
			LCD_intgerToString(HALL_EFFECT_mM_s);
			LCD_sendString("    ");

		}
		LCD_moveCURSER(0,10);
		if(DIR ==CCW){
			LCD_sendString("CCW");

		}else{
			LCD_sendString("CW ");
		}
//		LCD_intgerToString(HALL_EFFECT_mM_s);
//		vTaskSuspend(LCD_Handller_);
//		vTaskPrioritySet(STEPPER_Handller_, 2);
		  vTaskResume( STEPPER_Handller_ );
	}
}
void Welcome_TASK(){
	while(1){
		LCD_clearScreen();
		LCD_moveCURSER(0,0);
		LCD_sendString("Motion Control Proj.");
		LCD_sendString("Welcome");

		LCD_moveCURSER(1,0);
		LCD_sendString("DR/Soliman Elnagar");
		_TIM1_delay_s(5);
		LCD_clearScreen();
		LCD_moveCURSER(0,0);

		LCD_sendString("RPM=   ");
		LCD_moveCURSER(1,0);
		LCD_sendString("V=         mm/s");
		_TIM1_delay_ms(100);
		vTaskSuspend(Welcome_TASK_Handller_);

	}
}
int main(void)
{
//		_TIM1_delay_s(2);
	HW_init();

	///////////////////////////
	if(xTaskCreate(LCD_SEND_DATA,"LCD_SEND_DATA",256,NULL,1,&LCD_Handller_)!=pdPASS ){
		Error_Handller();
	}



	if(xTaskCreate(READ_TASK,"READ_TASK",256,NULL,2,&READ_Handller_)!=pdPASS ){
		Error_Handller();
	}

	if(xTaskCreate(Welcome_TASK,"READ_TASK",256,NULL,5,&Welcome_TASK_Handller_)!=pdPASS ){
		Error_Handller();
	}

	if(xTaskCreate(STEPPER_Handller_TASK,"STEPPER_Handller_TASK",256,NULL,3,&STEPPER_Handller_)!=pdPASS ){
		Error_Handller();
	}



	//    MCAL_USART_SendData(TSR_UART_INSTANT, 'D');

	vTaskStartScheduler();

	for(;;);
}
