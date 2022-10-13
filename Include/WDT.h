/********************************************************************
 * @Title       : Watchdog Timer (WDT)
 * @Filename    : WDT.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 1, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef WDT_H_
#define WDT_H_

typedef enum {
    TIMEOUT_17_1ms,
    TIMEOUT_34_3ms,
    TIMEOUT_68_5ms,
    TIMEOUT_0_14s ,
    TIMEOUT_0_27s ,
    TIMEOUT_0_55s ,
    TIMEOUT_1_1s  ,
    TIMEOUT_2_2s  ,
} TimeOut_t;


void WDT_vEnable(TimeOut_t timeout);
void WDT_vDisable(void);

#endif /* WDT_H_ */
