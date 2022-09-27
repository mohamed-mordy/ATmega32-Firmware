/*
 * EXTI_interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL         1
#define BOTH_EDGES        2
#define FALLING_EDGE      3
#define RISING_EDGE       4


#define EXTI_0     0
#define EXTI_1     1
#define EXTI_2     2

void EXTI_vInit(void);
void EXTI_vSetSenseCtrl(u8 u8_ExtiPin, u8 u8_SensoCtrl);
void EXTI_vEnableInterrupt(u8 u8_ExtiPin, u8 u8_SenseCtrl);
void EXTI_vDisableInterrupt(u8 u8_ExtiPin);
void EXTI_vRegisterCallback(u8 u8_ExtiPin, void (*fptr)(void));

#endif /* EXTI_INTERFACE_H_ */

