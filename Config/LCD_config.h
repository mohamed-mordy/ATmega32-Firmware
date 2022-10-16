/********************************************************************
 * @Title       : Liquid Crystal Display (LCD)
 * @Filename    : LCD_config.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 12, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/**
 * LCD Mode configurations
 *  MODE_4_BIT
 *  MODE_8_BIT
 */
#define LCD_MODE_SELECT  MODE_8_BIT


/**
 * LCD DATA Pins configurations
 * The Data Port is written in an atomic operation in 8-bit mode.
 * Data pins are considered only in 4-bit mode.
 */
#define LCD_DATA_PORT    DIO_PORTB

#define LCD_DATA_PIN_7   DIO_PIN4
#define LCD_DATA_PIN_6   DIO_PIN2
#define LCD_DATA_PIN_5   DIO_PIN1
#define LCD_DATA_PIN_4   DIO_PIN0

/**
 * LCD CTRL pins configurations
 */
#define LCD_CTRL_PORT        DIO_PORTA

#define LCD_CTRL_RS          DIO_PIN0
#define LCD_CTRL_RW          DIO_PIN1
#define LCD_CTRL_EN          DIO_PIN2

#endif /* LCD_CONFIG_H_ */

