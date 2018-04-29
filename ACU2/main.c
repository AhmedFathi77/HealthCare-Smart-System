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

int main(void){
	LCD_Init();
	_delay_ms(10);
	LCD_Clear();

	Slave_init();
	char Receive = 'K';
	while(1){
		Receive = SPI_Receive_Byte();
		if(Receive != 'K'){
			Go_to(1,1);
			LCD_Print("Controller2 Done");
		}else{
			Go_to(1,1);
			LCD_Print("Controller2 Fail");
		}

	}
}
