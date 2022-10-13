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

#include "Std_Types.h"
#include "UART.h"
#include "UART_private.h"
#include "UART_config.h"

static void (*UART_RX_COMPLETE_callback) (u8 data);
static void (*UART_DR_EMPTY_callback)    (void);
static void (*UART_TX_COMPLETE_callback) (void);

void UART_vInit(void)
{
	UCSRB = 0b10011000;
	UCSRC = 0b10000110;
	UBRRL = 51; // 9600
	/* 1. Transmitter Enable / Receiver Enable */

	/* 2. Interrupt Enable */
	/* 2.a. RX interrupt enable */
	/* 2.b. TX interrupt enable */
	/* 2.c. UDRE interrupt enable */

	/* 3. Character size */
	/* 4. Select Mode (Synch/ASynch) */
	/* 5. Parity Mode (odd/even) */
	/* 6.  */
}

void UART_vSend_sync(u8 data)
{
	while ( !(UCSRA & (1 << UDRE)))
		;
	UDR = data;
}

u8 UART_u8Recieve_sync(void)
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

void UART_vSend_async(u8 data)
{
	// TODO
}

u8 UART_u8Recieve_async(void)
{
	return UDR;
}

void UART_vPrintString(char str[])
{
	while (*str) {
		UART_vSend_sync(*str);
		str++;
	}
}

void UART_vReadString(char str[], u32 size)
{
	for (u32 i = 0; i < size - 1; i++) {
		str[i] = UART_u8Recieve_sync();
		if (str[i] == '\n' || str[i] == '\r') {  // some systems use '\r' instead of '\n'
			str[i] = '\0';
			break;
		}
	}
	str[size - 1] = '\0';
}

void UART_VRegisterCallback(CallBack_t cbk, void (*fptr)(u8))
{
	switch (cbk) {
        case UART_RX_COMPLETE:
            UART_RX_COMPLETE_callback = fptr;
            break;
        case UART_DR_EMPTY:
            UART_DR_EMPTY_callback = fptr;
            break;
        case UART_TX_COMPLETE:
            UART_TX_COMPLETE_callback = fptr;
            break;
        default:
            /* Error. */
            break;
	}
}

void __vector_13(void) __attribute((signal));
void __vector_13(void)
{
    if (UART_RX_COMPLETE_callback != NULL) {
        UART_RX_COMPLETE_callback(UDR);
    }
}

void __vector_14(void) __attribute((signal));
void __vector_14(void)
{
    if (UART_DR_EMPTY_callback != NULL) {
        UART_DR_EMPTY_callback();
    }
}

void __vector_15(void) __attribute((signal));
void __vector_15(void)
{
    if (UART_TX_COMPLETE_callback != NULL) {
        UART_TX_COMPLETE_callback();
    }
}
