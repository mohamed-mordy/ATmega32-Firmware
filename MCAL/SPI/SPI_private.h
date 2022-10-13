/********************************************************************
 * @Title       : Serial Peripheral Interface (SPI)
 * @Filename    : SPI_private.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 8, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPDR (*(volatile u8*)0x2f)
#define SPSR (*(volatile u8*)0x2e)
#define SPCR (*(volatile u8*)0x2d)

#define SPCR_SPIE
#define SPCR_SPE
#define SPCR_DORD
#define SPCR_MSTR
#define SPCR_CPOL
#define SPCR_CPHA
#define SPCR_SPR1
#define SPCR_SPR0


#define SPSR_SPIF        7
#define SPSR_WCOL        6
#define SPSR_SPI2X       0


#endif /* SPI_PRIVATE_H_ */
