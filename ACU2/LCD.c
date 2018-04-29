/*
 * LCD.c
 *
 *  Created on: Apr 17, 2018
 *      Author: leenovoz510
 */

#include "MicroConfig.h"

void LCD_Init(){
	DDRC |= 0xFF;
	DDRD |=  (1<<EN) | (1<<RS) | (1<<RW);
	LCD_SendComand(0x38); //8-bit mode
	LCD_SendComand(0x0C); // Display On
	LCD_SendComand(0x06); //cursor right
	LCD_SendComand(0x80); // 1st Line
}
void LCD_SendComand(char Command){
	PORTC = Command;
	PORTD &= ~(1<<RS);
	PORTD &= ~(1<<RW);

	PORTD |=  (1<<EN);
	_delay_ms(10);
	PORTD &= ~(1<<EN);
}
void LCD_SendData(char Data){
	PORTC = Data;
	PORTD |=  (1<<RS);
	PORTD &= ~(1<<RW);

	PORTD |=  (1<<EN);
	_delay_ms(10);
	PORTD &= ~(1<<EN);

}
void LCD_Clear(){
	LCD_SendComand(0X01);
	_delay_ms(10);
}
void Go_to(char x ,char y){
	char firstAddress[] = {0x80,0xC0,0x94,0xD4};
	LCD_SendComand(firstAddress[y-1] + x-1);
		_delay_ms(10);
}
void LCD_Print(char* Data){
	int i = 0 ;
	while(Data[i] != '\0'){
		LCD_SendData(Data[i]);
		i++;
	}
}
void LCD_Numbers(int num){
	char Buffer[16];
	itoa(num , Buffer , 10);
	LCD_Print(Buffer);
}

