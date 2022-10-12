/********************************************************************
 * @Title       : External Interrupts (EXTI)
 * @Filename    : EXTI_config.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 21, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/**
 * Select one of the following:
 *      LOW_LEVEL
 *      BOTH_EDGES
 *      FALLING_EDGE
 *      RISING_EDGE
 * Note:
 * INT2 is only edge triggered interrupt
 */
#define EXTI_TRIGGER_MODE_INT0       FALLING_EDGE
#define EXTI_TRIGGER_MODE_INT1       RISING_EDGE
#define EXTI_TRIGGER_MODE_INT2       RISING_EDGE


/**
 * Select one of the following:
 *      ENABLED
 *      DISABLED
 */
#define EXTI_ENABLE_INT0            ENABLED
#define EXTI_ENABLE_INT1            DISABLED
#define EXTI_ENABLE_INT2            DISABLED

#endif /* EXTI_CONFIG_H_ */

