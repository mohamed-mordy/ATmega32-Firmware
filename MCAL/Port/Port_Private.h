/********************************************************************
 * @Title       : Port Driver
 * @Filename    : Port_private.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 5, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

#define DDRA     (*(volatile u8*) 0x3A)
#define DDRB     (*(volatile u8*) 0x37)
#define DDRC     (*(volatile u8*) 0x34)
#define DDRD     (*(volatile u8*) 0x31)

#define PORTA    (*(volatile u8*) 0x3B)
#define PORTB    (*(volatile u8*) 0x38)
#define PORTC    (*(volatile u8*) 0x35)
#define PORTD    (*(volatile u8*) 0x32)

/*____________________________________________________________________________________________________*/
#define PORT_DIR(pin7, pin6, pin5, pin4, pin3, pin2, pin1, pin0)          0b##pin7##pin6##pin5##pin4##pin3##pin2##pin1##pin0

#define PORT_DIR_FIRST(pin7, pin6, pin5, pin4, pin3, pin2, pin1, pin0)    PORT_DIR(pin7, pin6, pin5, pin4, pin3, pin2, pin1, pin0) 

#define PORTA_DIR          PORT_DIR_FIRST(PORTA_PIN7_DIR, PORTA_PIN6_DIR, PORTA_PIN5_DIR, PORTA_PIN4_DIR,\
                                          PORTA_PIN3_DIR, PORTA_PIN2_DIR, PORTA_PIN1_DIR, PORTA_PIN0_DIR)

#define PORTB_DIR          PORT_DIR_FIRST(PORTB_PIN7_DIR, PORTB_PIN6_DIR, PORTB_PIN5_DIR, PORTB_PIN4_DIR,\
                                          PORTB_PIN3_DIR, PORTB_PIN2_DIR, PORTB_PIN1_DIR, PORTB_PIN0_DIR)

#define PORTC_DIR          PORT_DIR_FIRST(PORTC_PIN7_DIR, PORTC_PIN6_DIR, PORTC_PIN5_DIR, PORTC_PIN4_DIR,\
                                          PORTC_PIN3_DIR, PORTC_PIN2_DIR, PORTC_PIN1_DIR, PORTC_PIN0_DIR)

#define PORTD_DIR          PORT_DIR_FIRST(PORTD_PIN7_DIR, PORTD_PIN6_DIR, PORTD_PIN5_DIR, PORTD_PIN4_DIR,\
                                          PORTD_PIN3_DIR, PORTD_PIN2_DIR, PORTD_PIN1_DIR, PORTD_PIN0_DIR)
/*____________________________________________________________________________________________________*/


/*____________________________________________________________________________________________________*/
#define PORT_INIT_VAL(pin7, pin6, pin5, pin4, pin3, pin2, pin1, pin0)          0b##pin7##pin6##pin5##pin4##pin3##pin2##pin1##pin0

#define PORT_INIT_VAL_FIRST(pin7, pin6, pin5, pin4, pin3, pin2, pin1, pin0)    PORT_INIT_VAL(pin7, pin6, pin5, pin4, pin3, pin2, pin1, pin0) 

#define PORTA_INIT_VAL    PORT_INIT_VAL_FIRST(PORTA_PIN7_INIT_VAL, PORTA_PIN6_INIT_VAL, PORTA_PIN5_INIT_VAL, PORTA_PIN4_INIT_VAL,\
                                              PORTA_PIN3_INIT_VAL, PORTA_PIN2_INIT_VAL, PORTA_PIN1_INIT_VAL, PORTA_PIN0_INIT_VAL)

#define PORTB_INIT_VAL    PORT_INIT_VAL_FIRST(PORTB_PIN7_INIT_VAL, PORTB_PIN6_INIT_VAL, PORTB_PIN5_INIT_VAL, PORTB_PIN4_INIT_VAL,\
                                              PORTB_PIN3_INIT_VAL, PORTB_PIN2_INIT_VAL, PORTB_PIN1_INIT_VAL, PORTB_PIN0_INIT_VAL)

#define PORTC_INIT_VAL    PORT_INIT_VAL_FIRST(PORTC_PIN7_INIT_VAL, PORTC_PIN6_INIT_VAL, PORTC_PIN5_INIT_VAL, PORTC_PIN4_INIT_VAL,\
                                              PORTC_PIN3_INIT_VAL, PORTC_PIN2_INIT_VAL, PORTC_PIN1_INIT_VAL, PORTC_PIN0_INIT_VAL)

#define PORTD_INIT_VAL    PORT_INIT_VAL_FIRST(PORTD_PIN7_INIT_VAL, PORTD_PIN6_INIT_VAL, PORTD_PIN5_INIT_VAL, PORTD_PIN4_INIT_VAL,\
                                                  PORTD_PIN3_INIT_VAL, PORTD_PIN2_INIT_VAL, PORTD_PIN1_INIT_VAL, PORTD_PIN0_INIT_VAL)
/*____________________________________________________________________________________________________*/

#endif /* PORT_PRIVATE_H_ */

