/********************************************************************
 * @Title       : Analog to Digital Converter (ADC)
 * @Filename    : ADC_private.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 23, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define   ADMUX       (*(volatile u8*)  0x27)
#define   ADCSRA      (*(volatile u8*)  0x26)
#define   ADCL        (*(volatile u8*)  0x24)
#define   ADCH        (*(volatile u8*)  0x25)
#define   SFIOR       (*(volatile u8*)  0x50)
#define   ADC_DATA    (*(volatile u16*) 0x24) // Reads Digital Reading

/* ADMUX bits. */
#define ADMUX_REFS1    7 
#define ADMUX_REFS0    6 
#define ADMUX_ADLAR    5 
#define ADMUX_MUX4     4
#define ADMUX_MUX3     3
#define ADMUX_MUX2     2
#define ADMUX_MUX1     1
#define ADMUX_MUX0     0

/* ADCSRA bits. */
#define ADCSRA_ADEN    7
#define ADCSRA_ADSC    6
#define ADCSRA_ADATE   5 
#define ADCSRA_ADIF    4
#define ADCSRA_ADIE    3
#define ADCSRA_ADPS2   2 
#define ADCSRA_ADPS1   1 
#define ADCSRA_ASPS0   0 


/* Voltage Reference Selections. */
#define VREF_AREF			1
#define VREF_AVCC			2
#define VREF_INTERNAL_VREF  3

/* ADC Prescaler Mask. */
#define ADC_PRESCALER_MASK   0b111

/* ADC Channel Mask */
#define ADC_CHANNEL_MASK    0b11111

#define AUTO_TRIGGER        1
#define SINGLE_CONVERSION   0

#define ENABLED             1
#define DISABLED            0

#endif /* ADC_PRIVATE_H_ */
