/*
 * EXTI_config.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed
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
#define EXTI_TRIGGER_MODE_INT0       LOW_LEVEL
#define EXTI_TRIGGER_MODE_INT1       RISING_EDGE
#define EXTI_TRIGGER_MODE_INT2       RISING_EDGE


/**
 * Select one of the following:
 *      EXTI_ENABLE
 *      EXTI_DISABLE
 */
#define EXTI_ENABLE_INT0            EXTI_ENABLE
#define EXTI_ENABLE_INT1            EXTI_DISABLE
#define EXTI_ENABLE_INT2            EXTI_DISABLE

#endif /* EXTI_CONFIG_H_ */
