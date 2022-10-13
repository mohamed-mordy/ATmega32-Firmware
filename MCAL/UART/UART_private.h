/********************************************************************
 * @Title       : UART
 * @Filename    : UART_private.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 7, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_



#define UDR         (*(u8 volatile *) 0x2c)
#define UCSRA       (*(u8 volatile *) 0x2b)

#define UCSRA_RXC    7
#define UCSRA_TXC    6
#define UCSRA_UDRE   5 
#define UCSRA_FE     4
#define UCSRA_DOR    3
#define UCSRA_PE     2
#define UCSRA_U2X    1
#define UCSRA_MPCM   0 

#define UCSRB       (*(u8 volatile *) 0x2a)
#define UCSRC       (*(u8 volatile *) 0x40)
#define UBRRL       (*(u8 volatile *) 0x29)
#define UBBRH       (*(u8 volatile *) 0x40)



#endif /* UART_PRIVATE_H_ */
