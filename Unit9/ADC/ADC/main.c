
#include "adc.h"
#include "lcd.h"
uint8_t arr[16]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,};
void main(void){
	uint8_t adc,pos,LM35;
	ADC_Config_t ADC_CONFIG ={ADC0,AREF,F_64,DISABLE,NULL};
	LCD_init();
	ADC_init(&ADC_CONFIG);
	LCD_sendString("LM35 TEMP:    C");
	while(1){
//		adc=ADC_read(ADC0);
//		LM35=((adc)/2);

		// Another way     150 C ---------> 1.5 V
//							x-------------> Vin=Vout*Delta(vref/1024)
		LM35 =((ADC_read(ADC0)*150*5)/(1024*1.5));
		LCD_moveCURSER(0,10);
		LCD_intgerToString(LM35);
		if(LM35<10){
			LCD_moveCURSER(0,11);
			LCD_sendString("  ");
		}		else if(LM35<100){
					LCD_moveCURSER(0,12);
					LCD_sendString("  ");
	}
		for(int i=0;i<16;i++){
			LCD_moveCURSER(1,i);
			pos=((((LM35*100)/150)*16)/100);
			if(i<pos){
				LCD_sendCharcter(arr[i]);
			}else{
				LCD_sendCharcter(' ');

			}


		}
//			else if(adc<100){
//			LCD_moveCURSER(0,10);
//			LCD_sendString("  ");
//		}else if(adc<1000){
//			LCD_moveCURSER(0,11);
//			LCD_sendString(" ");
//		}

	}
}
