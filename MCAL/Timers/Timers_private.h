/********************************************************************
 * @Title       : Timers
 * @Filename    : Timers_private.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 24, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

#define TIMER1_NORMAL     0b1101


#define TCCR0		(*(volatile u8*)0x53)
#define TCNT0		(*(volatile u8*)0x52)
#define OCR0        (*(volatile u8*)0x5c)
#define TIMSK       (*(volatile u8*)0x59)
#define TIFR        (*(volatile u8*)0x58)

/* TCCR0 Bits. */
#define TCCR0_FOC0    7
#define TCCR0_WGM00   6
#define TCCR0_COM01   5
#define TCCR0_COM00   4
#define TCCR0_WGM01   3
#define TCCR0_CS02    2
#define TCCR0_CS01    1
#define TCCR0_CS00    0

#define TCCR0_CS_MASK  0b111
#define TCCR0_COM_MASK 0b110000

/* TIMSK Bits. */
#define TIMSK_0CIE2    7  
#define TIMSK_TOIE2    6  
#define TIMSK_TICIE1   5   
#define TIMSK_OCIE1A   4   
#define TIMSK_OCIE1B   3   
#define TIMSK_TOIE1    2  
#define TIMSK_OCIE0    1  
#define TIMSK_TOIE0    0  

/* TIFR Bits. */
#define TIFR_OCF2       7
#define TIFR_TOV2       6
#define TIFR_ICF1       5
#define TIFR_OCF1A      4 
#define TIFR_OCF1B      3 
#define TIFR_TOV1       2
#define TIFR_OCF0       1
#define TIFR_TOV0       0


#define TCCR1A  (*(volatile u8  *) 0X4F)
#define TCCR1B  (*(volatile u8  *) 0X4E)
#define TCNT1   (*(volatile u16 *) 0X4C)
#define OCR1A   (*(volatile u16 *) 0X4A)
#define OCR1B   (*(volatile u16 *) 0X48)
#define ICR1    (*(volatile u16 *) 0X46)

#define TCCR1A_COM1A1    7
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1B1    5
#define TCCR1A_COM1B0    4
#define TCCR1A_FOC1A     3
#define TCCR1A_FOC1B     2
#define TCCR1A_WGM11     1
#define TCCR1A_WGM10     0


#define TCCR1B_ICNC1     7
#define TCCR1B_ICES1     6
#define TCCR1B_WGM13     4
#define TCCR1B_WGM12     3
#define TCCR1B_CS12      2
#define TCCR1B_CS11      1
#define TCCR1B_CS10      0

#define TCCR1_CS_MASK   0b00000111
#define TCCR1A_COM_MASK 0b11110000


#define TCCR2		(*(volatile u8*)0x45)
#define TCNT2		(*(volatile u8*)0x44)

#endif /* TIMERS_PRIVATE_H_ */

