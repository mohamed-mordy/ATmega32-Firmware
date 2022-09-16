/*
 * LCD.h
 *
 *  Created on: Sep 4, 2022
 *      Author: Mohamed
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_vInit(void);
void LCD_vSendCmd(u8 u8Cmd);
void LCD_vSendChar(u8 u8Character);
void LCD_vSendString(const char *pcString);

void LCD_vGotoXY(u8 u8XPos, u8 u8YPos);
void LCD_vClearDisplay(void);
void LCD_vReturnHome(void);
void LCD_vSaveCustomCharacter(u8 *pu8Arr, u8 u8BlockNumber);
void LCD_vWriteCustomeCharacter(u8 u8CharID);
void LCD_vWriteNumber(s32 s32Number);

#endif /* LCD_INTERFACE_H_ */
