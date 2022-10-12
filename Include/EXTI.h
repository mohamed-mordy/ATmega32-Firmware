/********************************************************************
 * @Title       : External Interrupts (EXTI)
 * @Filename    : EXTI.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 21, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL         0
#define BOTH_EDGES        1
#define FALLING_EDGE      2
#define RISING_EDGE       3

typedef enum {
    EXTI_0,
    EXTI_1,
    EXTI_2,
} EXTI_t;

void EXTI_vInit            (void);
void EXTI_vSetSenseCtrl    (EXTI_t exti, u8 u8_SensoCtrl);
void EXTI_vEnableInterrupt (EXTI_t exti);
void EXTI_vDisableInterrupt(EXTI_t exti);
void EXTI_vRegisterCallback(EXTI_t exti, void (*fptr)(void));

#endif /* EXTI_INTERFACE_H_ */

