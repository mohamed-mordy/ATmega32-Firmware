/*
 * LCD.c
 *
 *  Created on: Sep 4, 2022
 *      Author: Mohamed
 */

#include <Std_Types.h>
#include <util/delay.h>


#include <DIO_interface.h>
#include <LCD_interface.h>

#include "LCD_private.h"
#include <LCD_config.h>


/* Preprocessor Directives. */

/* Register Select (RS ) --> 0: Command register / 1: Data register */
/* select Read / Write (R/W) --> 0: Write to LCD / 1: Read from LCD */

void LCD_vInit(void)
{
	_delay_ms(30);

    #if (lcd_MODE_8_BIT == 1  && lcd_MODE_4_BIT == 1)
        #error "(lcd_MODE_8_BIT == 1  && lcd_MODE_4_BIT == 1), where only one should be 1"
    #endif
    #if (lcd_MODE_4_BIT == 1)
    {
		LCD_vSendCmd(0x02);
		LCD_vSendCmd(0x28);
		_delay_ms(1);
		LCD_vSendCmd(0x0c);
		_delay_ms(1);
		LCD_vSendCmd(0x01);	/*LCD clear*/
		_delay_ms(1);
    }
    #elif (lcd_MODE_8_BIT == 1)
    {
    	//LCD_DATA_DDR = 0xff;
    	//LCD_CTRL_DDR = 0xff;


        /* Function set: 2-Lines, 5*8 font size */
        LCD_vSendCmd(0X38);

        /* Display on/off control: Display enable, disable cursor, no-blink cursor */
        LCD_vSendCmd(0X0C);

        /* Display clear */
        LCD_vSendCmd(0X01);

        /* Entry Mode Set */
        //LCD_vSendCmd(0X06);
    }
    #else
        #error  "undefined LCD mode"
    #endif
}

void LCD_vSendCmd(u8 u8Cmd)
{
    #if (lcd_MODE_8_BIT == 1  && lcd_MODE_4_BIT == 1)
        #error "(lcd_MODE_8_BIT == 1  && lcd_MODE_4_BIT == 1), where only one should be 1"
    #endif
    #if (lcd_MODE_8_BIT == 1)
    {
        /* select RS -> 0: Command register */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_LOW);

        /* select RW -> 0 */
        // CLEAR_BIT(LCD_CTRL_PORT, PIN1);

        /* put data on LCD pins. */
        DIO_setPortValue(LCD_DATA_PORT, u8Cmd);

        /* set E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);

        _delay_ms(2);

        /* clear E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_LOW);
    }
    #elif (lcd_MODE_4_BIT == 1)
    {
        /* select RS -> 0: Command register */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_LOW);

        /* select RW -> 0 */
        // CLEAR_BIT(LCD_CTRL_PORT, PIN1);

        /* put data on LCD pins. */
        LCD_DATA_PORT |= (u8Cmd & 0XF0);

        /* set E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);

        _delay_ms(2);

        /* clear E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_LOW);

        /* put data on LCD pins. */
        LCD_DATA_PORT |= (u8Cmd << 4);

        /* set E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);

        _delay_ms(2);

        /* clear E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_LOW);
    }
    #else
        #error  "undefined LCD mode"
    #endif
}

void LCD_vSendChar(u8 u8Character)
{
    #if (lcd_MODE_8_BIT == 1  && lcd_MODE_4_BIT == 1)
        #error "(lcd_MODE_8_BIT == 1  && lcd_MODE_4_BIT == 1), where only one should be 1"
    #endif /* (lcd_MODE_8_BIT == 1  && lcd_MODE_4_BIT == 1) */
    #if (lcd_MODE_8_BIT == 1)
    {
        /* select RS -> 1: Data register */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_HIGH);

        /* select RW -> 0 */
        // DIO_setPinValue(PORTA, LCD_RW_PIN, DIO_PIN_LOW);

        /* put data on LCD pins. */
        DIO_setPortValue(LCD_DATA_PORT, u8Character);

        /* set E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);

        _delay_ms(2);

        /* clear E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_LOW);
    }
    #elif (lcd_MODE_4_BIT == 1) /*  (lcd_MODE_8_BIT == 1) */
    {
        /* select RS -> 1: Data register */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_HIGH);

        /* select RW -> 0 */
        // DIO_setPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_PIN_LOW);

        /* put data on LCD pins. */
        LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ( (u8Character & 0XF0) >> 4);
        /* set E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);
        _delay_ms(2);
        /* clear E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_LOW);

        /* put data on LCD pins. */
        LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (u8Character & 0X0F);
        /* set E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);
        _delay_ms(2);
        /* clear E */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_LOW);
    }
    #else /* (lcd_MODE_8_BIT == 1) */
    {
        #error  "undefined LCD mode"
    }
    #endif /* (lcd_MODE_8_BIT == 1) */
}

void LCD_vSendString(const char *pcString)
{
    while (*pcString) {
        LCD_vSendChar(*pcString);
        pcString++;
    }
}

void LCD_vGotoXY(u8 u8XPos, u8 u8YPos)
{
    u8 address;
    if (u8XPos == 0 && u8YPos >= 0 && u8YPos <= 0x28) {
        address = (u8YPos) | (0x80);
        LCD_vSendCmd(address); /* set DDRAM address command. */
    } else if (u8XPos == 1 && u8YPos >= 0 && u8YPos <= 0x68) {
        address = (u8YPos + 0X40) | (0x80);
        LCD_vSendCmd(address); /* set DDRAM address command. */
    } else {
        /* Error */ 
    }
}

void LCD_vClearDisplay(void)
{
    LCD_vSendCmd(0x01); /* Clear Display. */
}

void LCD_vReturnHome(void)
{
    LCD_vSendCmd(0x02); /* Return Home. */
}

void LCD_vSaveCustomCharacter(u8 *pu8Arr, u8 u8BlockNumber)
{
    u8 i = 0;
    u8 CGRAM_Address = (u8BlockNumber * 8) + 64 ; //| 0x40;

    LCD_vSendCmd(CGRAM_Address); /* Set CGRAM Address Command */

    for (i = 0; i < 8; i++) {
        LCD_vSendChar(pu8Arr[i]);
    }

    LCD_vSendCmd(128);
}

void LCD_vWriteCustomeCharacter(u8 u8CharID)
{
	LCD_vSendChar(u8CharID); /* Display the pattern written in the CGRAM */
}

void LCD_vWriteNumber(s32 s32Number)
{
	s32 reversed = 0;
	s32 zero_right_flag = 0;
	if (s32Number < 0) {
		LCD_vSendChar('-');
		s32Number *= -1;
	}
	if (s32Number == 0) {
		LCD_vSendChar('0');
	} else {
		if (s32Number % 10 == 0) {
			s32Number += 1;
			zero_right_flag = 1;
		}
		while (s32Number > 0) {
			reversed = reversed * 10 + s32Number % 10;
			s32Number /= 10;
		}
		while (reversed > 0) {
			if (reversed == 1 && zero_right_flag == 1) {
				reversed = 0;
				//continue;
			}
			LCD_vSendChar(reversed % 10 + 48);
			reversed /= 10;
		}
	}
}

