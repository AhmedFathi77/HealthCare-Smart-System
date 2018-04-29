/*
 * SPI.c
 *
 *  Created on: Apr 17, 2018
 *      Author: leenovoz510
 */

#include "MicroConfig.h"

void Master_init(){
	DDRB |= (1<<SS)| (1<<MOSI) | (1<<SCK);
	DDRB &=~(1<<MISO);

	SPCR |= (1<<MSTR);  	// Set it 1 To EnaBle Master
	SPCR |= (1<<SPE);		// SET IT 1 TO Enable SPI
}
void Slave_init(){
	DDRB |= (1<<MISO);
	DDRB &=~(1<<SS);
	DDRB &=~(1<<MOSI);
	DDRB &=~(1<<SCK);
	SPCR |= (1<<SPE);		// SET IT 1 TO Enable SPI
}
void SPI_Send_Byte(const unsigned char Data){
	SPDR = Data ;
	while(!(SPSR & (1<<SPIF))){}
}
unsigned char SPI_Receive_Byte(){
	while(!(SPSR & (1<<SPIF))){}
	return SPDR;
}
void SPI_SendString(const unsigned char *Str)
{
	int i = 0;
	while(Str[i] != '\0')
	{
		SPI_Send_Byte(Str[i]);
		i++;
	}
}
void SPI_ReceiveString(char *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_Receive_Byte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_Receive_Byte();
	}
	Str[i] = '\0';
}
