/********************************************************************
 * @Title       : Serial Peripheral Interface (SPI)
 * @Filename    : SPI.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 8, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef SPI_H_
#define SPI_H_


void SPI_vInit(void);
u8 SPI_u8Transceive(u8 data);



#endif /* SPI_H_ */
