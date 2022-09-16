/*
 * LCD_config.h
 *
 *  Created on: Sep 4, 2022
 *      Author: Mohamed
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/**
 * LCD Mode configurations
 */
#define lcd_MODE_4_BIT       0
#define lcd_MODE_8_BIT       1


/**
 * LCD CTRL and DATA PORT configurations
 */
#define LCD_CTRL_PORT    DIO_PORTA
#define LCD_DATA_PORT    DIO_PORTB


/**
 * LCD CTRL and DATA configurations
 */
#define LCD_CTRL_DDR     DIO_DDRA
#define LCD_DATA_DDR     DIO_DDRB


/**
 * LCD CTRL pins configurations
 */
#define LCD_RS_PIN           0
#define LCD_RW_PIN           1
#define LCD_E_PIN            2


#endif /* LCD_CONFIG_H_ */

