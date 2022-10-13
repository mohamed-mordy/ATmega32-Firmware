/********************************************************************
 * @Title       : UART
 * @Filename    : UART.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 7, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef UART_H_
#define UART_H_

typedef enum {
    UART_RX_COMPLETE,
    UART_DR_EMPTY,
    UART_TX_COMPLETE,
} CallBack_t;



void UART_vInit(void);
void UART_vSend_sync(u8 data);
u8 UART_u8Recieve_sync(void);
void UART_vSend_async(u8 data);
u8 UART_u8Recieve_async(void);
void UART_vPrintString(char str[]);
void UART_vReadString(char str[], u32 size);


void UART_VRegisterCallback(CallBack_t cbk, void (*fptr)(u8));


#endif /* UART_H_ */
