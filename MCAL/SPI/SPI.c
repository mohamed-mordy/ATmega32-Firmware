/********************************************************************
 * @Title       : Serial Peripheral Interface (SPI)
 * @Filename    : SPI.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 8, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#include "Std_Types.h"
#include "SPI.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_vInit(void)
{
	SPCR = 0b01011100;


	/* 1. SPI Enable */
	/* 2. SPI Interrupt Enable */
	/* 3. Data Order */
	/* 4. SPI Master/Slave*/
	/* 5.a. CPOL */
	/* 5.b. CPHA */
}


u8 SPI_u8Transceive(u8 data)
{
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
	return SPDR;
}

