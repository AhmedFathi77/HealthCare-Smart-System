/*
 * SPI.h
 *
 *  Created on: Apr 17, 2018
 *      Author: leenovoz510
 */

#ifndef SPI_H_
#define SPI_H_

#include "MicroConfig.h"

void Master_init();
void Slave_init();
void SPI_Send_Byte(unsigned char Data);
unsigned char SPI_Receive_Byte();
void SPI_SendString(const unsigned char *Str);
void SPI_ReceiveString(char *Str);

#endif /* SPI_H_ */
