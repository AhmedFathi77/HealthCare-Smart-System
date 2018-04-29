/*
 * main.c
 *
 *  Created on: Apr 17, 2018
 *      Author: leenovoz510
 */

#include "avr/io.h"
#include "avr/delay.h"
#include "SPI.h"
#include "LCD.h"

	unsigned int beatms ;
	float bpm ;
float HeartBeat(){
	while(!(PINA&(1<<PA0)));
			_delay_ms(10);	// 10ms delay to avoid noise
			beatms = 10; 	// start counting beatms from 10ms since we have delay after pulse
			while((PINA&(1<<PA0))){   // wait until signal is high
				_delay_ms(1);
				beatms++;
			}
			while(!(PINA&(1<<PA0))){ // wait until signal is high again
				_delay_ms(1);
				beatms++;
			}
			bpm = (float)6000/beatms;
			return bpm;
}
int main(void){
	DDRA &= ~(1<<PA0);
	beatms = 0 ;

	LCD_Init();
	_delay_ms(10);
	LCD_Clear();
	//Master_init();
	while(1){
		bpm = HeartBeat();
		if(bpm > 200)
		{	Go_to(1,2);
			LCD_Print("Processing..");
			Go_to(13,2);
			LCD_Numbers(bpm);
			_delay_ms(1000);
		}else{
			Go_to(1,2);
			LCD_Print("BPM is ");
			Go_to(9,2);
			LCD_Numbers(bpm);
			_delay_ms(1000);
		}

		beatms = 0 ;

		//SPI_Send_Byte('N');
		//Go_to(1,1);
		//LCD_Print("Controller1 Done");
	}
	return 0;
}
