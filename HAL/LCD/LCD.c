/********************************************************************
 * @Title       : Liquid Crystal Display (LCD)
 * @Filename    : LCD.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 12, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#include <Std_Types.h>
#include <util/delay.h>

#include <DIO.h>
#include <LCD.h>
#include <LCD_private.h>
#include <LCD_config.h>

/* Register Select (RS ) --> 0: Command register / 1: Data register */

/**
 * @addtogroup Board_Support_Package
 * @{
 */

/********************************************************************
 * Function: void LCD_vInit(void)
 */
/**
 * \b Description:
 *
 * Initiaizes the LCD Driver.
 *
 * @param      void 
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vInit();
 * @endcode
 *
 * @see LCD_vSendCmd()
 * @see LCD_vSendChar()
 */
void LCD_vInit(void)
{
	_delay_ms(30);
    #if LCD_MODE_SELECT == MODE_4_BIT
        DIO_setPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_7, DIO_OUTPUT);
        DIO_setPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_6, DIO_OUTPUT);
        DIO_setPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_5, DIO_OUTPUT);
        DIO_setPinDirection(LCD_DATA_PORT, LCD_DATA_PIN_4, DIO_OUTPUT);

        DIO_setPinDirection(LCD_CTRL_PORT, LCD_CTRL_RS   , DIO_OUTPUT);
        DIO_setPinDirection(LCD_CTRL_PORT, LCD_CTRL_EN   , DIO_OUTPUT);

		LCD_vSendCmd(0x02);
		LCD_vSendCmd(0x28);
		_delay_ms(1);
		LCD_vSendCmd(0x0c);
		_delay_ms(1);
		LCD_vSendCmd(0x06);
		_delay_ms(1);
		LCD_vSendCmd(0x80);
		_delay_ms(1);
		LCD_vSendCmd(0x01);	/*LCD clear*/
		_delay_ms(1);
    #elif LCD_MODE_SELECT == MODE_8_BIT
        DIO_setPortDirection(LCD_DATA_PORT, 0XFF); /* Set Port Output. */
        DIO_setPinDirection(LCD_CTRL_PORT, LCD_CTRL_RS, DIO_OUTPUT);
        DIO_setPinDirection(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_OUTPUT);
        /* Function set: 2-Lines, 5*8 font size */
        LCD_vSendCmd(0X38);

        /* Display on/off control: Display enable, disable cursor, no-blink cursor */
        LCD_vSendCmd(0X0C);

        /* Display clear */
        LCD_vSendCmd(0X01);

        /* Entry Mode Set */
        //LCD_vSendCmd(0X06);
    #else
        #error  "LCD_MODE_SELECT is not configured properly"
    #endif
}

/********************************************************************
 * Function: void LCD_vSendCmd(u8 u8Cmd)
 */
/**
 * \b Description:
 *
 * Sends a command to The LCD.
 *
 * @param [in] u8Cmd The command to be sent to the LCD.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vSendCmd(LCD_CLEAR_DISPLAY);
 * @endcode
 *
 * @see LCD_vSendChar()
 */
void LCD_vSendCmd(u8 u8Cmd)
{
    #if LCD_MODE_SELECT == MODE_4_BIT
        /* select RS -> 0: Command register */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_RS, DIO_LOW);

        /* put data on LCD pins(High nibble). */
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_7, (u8Cmd>>7)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_6, (u8Cmd>>6)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_5, (u8Cmd>>5)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_4, (u8Cmd>>4)&1);
        
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_HIGH);/* set EN */
        _delay_ms(2);
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_LOW);/* clear EN */

        /* put data on LCD pins(low nibble). */
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_7, (u8Cmd>>3)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_6, (u8Cmd>>2)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_5, (u8Cmd>>1)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_4, (u8Cmd>>0)&1);
        
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_HIGH);/* set EN */
        _delay_ms(2);
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_LOW);/* clear EN */
    #elif LCD_MODE_SELECT == MODE_8_BIT
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_RS, DIO_LOW);/* select RS -> 0: Command register */

        DIO_setPortValue(LCD_DATA_PORT, u8Cmd);/* put data on LCD pins. */
        
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_HIGH);/* set EN */
        _delay_ms(2);
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_LOW);/* clear EN */
    #else
        #error  "LCD_MODE_SELECT is not configured properly"
    #endif
}

/********************************************************************
 * Function: void LCD_vSendChar(u8 u8Character)
 */
/**
 * \b Description:
 *
 * Sends a character to the LCD.
 *
 * @param [in]  u8Character The character to be sent to the LCD.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vSendChar('M');
 * @endcode
 *
 * @see LCD_vSendCmd()
 */
void LCD_vSendChar(u8 u8Character)
{
    #if LCD_MODE_SELECT == MODE_4_BIT
        /* select RS -> 1: Data register */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_RS, DIO_HIGH);

        /* put data on LCD pins. */
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_7, (u8Character>>7)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_6, (u8Character>>6)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_5, (u8Character>>5)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_4, (u8Character>>4)&1);
        
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_HIGH);/* set EN */
        _delay_ms(2);
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_LOW);/* clear EN */

        /* put data on LCD pins. */
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_7, (u8Character>>3)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_6, (u8Character>>2)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_5, (u8Character>>1)&1);
        DIO_setPinValue(LCD_DATA_PORT, LCD_DATA_PIN_4, (u8Character>>0)&1);

        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_HIGH);/* set EN */
        _delay_ms(2);
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_LOW);/* clear EN */

    #elif LCD_MODE_SELECT == MODE_8_BIT
        /* select RS -> 1: Data register */
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_RS, DIO_HIGH);

        DIO_setPortValue(LCD_DATA_PORT, u8Character);/* put data on LCD pins. */

        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_HIGH);/* set EN */
        _delay_ms(2);
        DIO_setPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_LOW);/* clear EN */
    #else
        #error  "LCD_MODE_SELECT is not configured properly"
    #endif
}

/********************************************************************
 * Function: void LCD_vSendString(const char *pcString)
 */
/**
 * \b Description:
 *
 * Sends a string to the LCD.
 *
 * @param [in]  pcString Pointer to the string to be sent.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vSendString("Mohamed is cool");
 * @endcode
 *
 * @see LCD_vSendChar()
 * @see LCD_vWriteNumber
 */
void LCD_vSendString(const char *pcString)
{
    while (*pcString) {
        LCD_vSendChar(*pcString);
        pcString++;
    }
}

/********************************************************************
 * Function: void LCD_vGotoXY(u8 u8XPos, u8 u8YPos)
 */
/**
 * \b Description:
 *
 * Goes to specific position in the LCd.
 *
 * @param [in]  u8XPos The xPos to set the cursor.
 * @param [in]  u8YPos The yPos to set the cursor.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vGotoXY(1, 0);
 * @endcode
 *
 * @see LCD_vReturnHome()
 */
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

/********************************************************************
 * Function: void LCD_vClearDisplay(void)
 */
/**
 * \b Description:
 *
 * Clears the contents of the display.
 *
 * @param [in]  void
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vClearDisplay();
 * @endcode
 *
 * @see LCD_vReturnHome()
 */
void LCD_vClearDisplay(void)
{
    LCD_vSendCmd(0x01); /* Clear Display. */
}

/********************************************************************
 * Function: void LCD_vReturnHome(void)
 */
/**
 * \b Description:
 *
 * Returns the cursor to the home position.
 *
 * @param [in]  void
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vReturnHome();
 * @endcode
 *
 * @see LCD_CLEAR_DISPLAY()
 */
void LCD_vReturnHome(void)
{
    LCD_vSendCmd(0x02); /* Return Home. */
}

/********************************************************************
 * Function: void LCD_vSaveCustomCharacter(u8 *pu8Arr, u8 u8BlockNumber)
 */
/**
 * \b Description:
 *
 * 
 *
 * @param [in] pu8Arr An array contains a custom character. 
 * @param [in] u8BlockNumber The position in LCD RAM to store the character.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * u8 meem_first[] = {
 *     0x00,
 *     0x00,
 *     0x00,
 *     0x07,
 *     0x05,
 *     0x07,
 *     0x18,
 *     0x00
 * };
 * 
 * u8 haa[] = {
 *     0x00,
 *     0x00,
 *     0x00,
 *     0x00,
 *     0x0C,
 *     0x02,
 *     0x1F,
 *     0x00
 * };
 * LCD_vSaveCustomCharacter(meem_first, 0);
 * LCD_vSaveCustomCharacter(haa, 1);
 * @endcode
 *
 * @see LCD_vWriteCustomeCharacter()
 */
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

/********************************************************************
 * Function: void LCD_vWriteCustomeCharacter(u8 u8CharID)
 */
/**
 * \b Description:
 *
 * Writes a custom character on the LCD.
 *
 * @param [in]  u8CharID Is the character ID.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * u8 meem_first[] = {
 *     0x00,
 *     0x00,
 *     0x00,
 *     0x07,
 *     0x05,
 *     0x07,
 *     0x18,
 *     0x00
 * };
 * 
 * u8 haa[] = {
 *     0x00,
 *     0x00,
 *     0x00,
 *     0x00,
 *     0x0C,
 *     0x02,
 *     0x1F,
 *     0x00
 * };
 * LCD_vSaveCustomCharacter(meem_first, 0);
 * LCD_vSaveCustomCharacter(haa, 1);
 * LCD_vWriteCustomeCharacter(0);
 * @endcode
 *
 * @see LCD_vSaveCustomCharacter()
 */
void LCD_vWriteCustomeCharacter(u8 u8CharID)
{
	LCD_vSendChar(u8CharID); /* Display the pattern written in the CGRAM */
}

/********************************************************************
 * Function: void LCD_vWriteNumber(s32 s32Number)
 */
/**
 * \b Description:
 *
 * Writes a number on the LCD.
 *
 * @param [in]  s32Number The number to be written on the LCD.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * LCD_vWriteNumber(-120);
 * @endcode
 *
 * @see  LCD_vSendString()
 */
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

/**
 * @}
 */

