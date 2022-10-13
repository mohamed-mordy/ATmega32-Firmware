/********************************************************************
 * @Title       : Keypad
 * @Filename    : Keypad_config.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 5, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_NO_PRESSED_KEY         0xff

#define KEYPAD_ARR_VAL  { {1 , 2 , 3 , 4}, {5 , 6 , 7 , 8}, {9 , 10, 11, 12}, {13, 14, 15, 16} }

#define KEYPAD_COLUMN_1_PIN     DIO_PIN7
#define KEYPAD_COLUMN_2_PIN     DIO_PIN6
#define KEYPAD_COLUMN_3_PIN     DIO_PIN5
#define KEYPAD_COLUMN_4_PIN     DIO_PIN3

#define KEYPAD_ROW_1_PIN        DIO_PIN5
#define KEYPAD_ROW_2_PIN        DIO_PIN4
#define KEYPAD_ROW_3_PIN        DIO_PIN3
#define KEYPAD_ROW_4_PIN        DIO_PIN2

#define KEYPAD_COLUMN_1_PORT    DIO_PORTD
#define KEYPAD_COLUMN_2_PORT    DIO_PORTD
#define KEYPAD_COLUMN_3_PORT    DIO_PORTD
#define KEYPAD_COLUMN_4_PORT    DIO_PORTD

#define KEYPAD_ROW_1_PORT       DIO_PORTC
#define KEYPAD_ROW_2_PORT       DIO_PORTC
#define KEYPAD_ROW_3_PORT       DIO_PORTC
#define KEYPAD_ROW_4_PORT       DIO_PORTC

#endif /* KEYPAD_CONFIG_H_ */

