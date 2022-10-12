/********************************************************************
 * @Title       : Global Interrupt Enable (GIE)
 * @Filename    : DIO.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 23, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_


void GIE_vEnable(void);
void GIE_vDisable(void);


#endif /* GIE_INTERFACE_H_ */
