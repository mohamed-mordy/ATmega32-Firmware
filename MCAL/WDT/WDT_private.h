/********************************************************************
 * @Title       : Watchdog Timer (WDT)
 * @Filename    : WDT_private.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 1, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define MCUCR (*(volatile u8*) 0x55)
#define WDTCR (*(volatile u8*) 0x41)

#define WDTCR_WDTOE     4
#define WDTCR_WDE       3
#define WDTCR_WDP2      2
#define WDTCR_WDP1      1
#define WDTCR_WDP0      0


#endif /* WDT_PRIVATE_H_ */

