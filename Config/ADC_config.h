/********************************************************************
 * @Title       : Analog to Digital Converter (ADC)
 * @Filename    : ADC_config.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 23, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/**
 * Select one of the following:
 *      VREF_AREF
 *      VREF_AVCC
 *      VREF_INTERNAL_VREF
 */
#define ADC_VREF           VREF_AVCC

/**
 * Select one of the following:
 *      ADC_Prescaler_2
 *      ADC_Prescaler_4
 *      ADC_Prescaler_8
 *      ADC_Prescaler_16
 *      ADC_Prescaler_32
 *      ADC_Prescaler_64
 *      ADC_Prescaler_128
 */
#define ADC_PRESCALER      ADC_Prescaler_128


/*
 * Select one of the following:
 *      ENABLED
 *      DISABLED
 */
#define ADC_INTERRUPT_ENABLE   ENABLED



/**
 * Select one of the following:
 *      AUTO_TRIGGER
 *      SINGLE_CONVERSION
 */
#define ADC_TRIGGER_MODE   AUTO_TRIGGER


/**
 * Select one of the following:
 *      FREE_RUNNING_MODE
 *      ANALOG_COMPARATOR
 *      EXTERNAL_INTERRUPT_REQUEST_0
 *      TIMER_COUNTER0_COMPARE_MATCH
 *      TIMER_COUNTER0_OVERFLOW
 *      TIMER_COUNTER1_COMPARE_MATCH_B
 *      TIMER_COUNTER1_OVERFLOW
 *      TIMER_COUNTER1_CAPTURE_EVEN
 */
#define ADC_AUTO_TRIGGER_SOURCE   FREE_RUNNING_MODE


#endif /* ADC_CONFIG_H_ */
