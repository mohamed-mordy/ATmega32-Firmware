/*
 * EXTI_private.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed
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

#define   EXTI_ENABLE       1
#define   EXTI_DISABLE      0

#endif /* EXTI_PRIVATE_H_ */
