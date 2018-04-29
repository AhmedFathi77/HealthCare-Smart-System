/*
 * LCD.h
 *
 *  Created on: Apr 17, 2018
 *      Author: leenovoz510
 */

#ifndef LCD_H_
#define LCD_H_
#include "MicroConfig.h"

void LCD_Init();
void LCD_SendComand(char Command);
void LCD_SendData(char Data);
void LCD_Clear();
void Go_to(char x ,char y);
void LCD_Print(char* Data);
void LCD_Numbers(int num);



#endif /* LCD_H_ */
