/********************************************************************
 * @Title       : External Interrupts (EXTI)
 * @Filename    : EXTI_private.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 21, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define   MCUCR              (*(volatile u8*) 0x55)
#define   MCUCSR             (*(volatile u8*) 0x54)
#define   GICR               (*(volatile u8*) 0x5B)
#define   GIFR               (*(volatile u8*) 0x5A)

/* MCUCR BITS */
#define   MCUCR_ISC00       0
#define   MCUCR_ISC01       1
#define   MCUCR_ISC10       2
#define   MCUCR_ISC11       3

#define   MCUCSR_ISC2       6

/* GICR BITS */
#define   GICR_INT0         6
#define   GICR_INT1         7
#define   GICR_INT2         5

#define   ENABLED           1
#define   DISABLED          0

#endif /* EXTI_PRIVATE_H_ */
