/*
 * Keypad.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamed
 */


#include "Std_Types.h"

#include "DIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_private.h"
#include "Keypad_config.h"


/* Array to store the return value foreach pressed key. */
const static u8 Keypad_Arr[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS] = KEYPAD_ARR_VAL;

const static u8 Keypad_Column_Pin_Arr[NUMBER_OF_COLUMNS] = { KEYPAD_COLUMN_1_PIN, KEYPAD_COLUMN_2_PIN,
                                                             KEYPAD_COLUMN_3_PIN, KEYPAD_COLUMN_4_PIN };
const static u8 Keypad_Column_Port_Arr[NUMBER_OF_COLUMNS] = { KEYPAD_COLUMN_1_PORT, KEYPAD_COLUMN_2_PORT,
                                                              KEYPAD_COLUMN_3_PORT, KEYPAD_COLUMN_4_PORT };

const static u8 Keypad_Row_Pin_Arr[NUMBER_OF_ROWS] = { KEYPAD_ROW_1_PIN, KEYPAD_ROW_2_PIN,
                                                       KEYPAD_ROW_3_PIN, KEYPAD_ROW_4_PIN };
const static u8 Keypad_Row_Port_Arr[NUMBER_OF_ROWS] = { KEYPAD_ROW_1_PORT, KEYPAD_ROW_2_PORT,
                                                        KEYPAD_ROW_3_PORT, KEYPAD_ROW_4_PORT };

u8 Keypad_getPressedKey(void)
{
    u8 i, j;
    u8 pressed_key = KEYPAD_NO_PRESSED_KEY;

    for (i = 0; i < NUMBER_OF_COLUMNS; i++) {

        /* Activate Current Column. */
        DIO_setPinValue(Keypad_Column_Port_Arr[i], Keypad_Column_Pin_Arr[i], DIO_PIN_LOW);

        /* Check every row for a low pin. If found return corresponding key immediately. */
        for (j = 0; j < NUMBER_OF_ROWS; j++) {
            /* Check state of input row pin. */
            if (DIO_getPinValue(Keypad_Row_Port_Arr[j], Keypad_Row_Port_Arr[j]) == DIO_PIN_LOW) {
                pressed_key = Keypad_Arr[i][j];
                /* Polling until key is released. */
                while (DIO_getPinValue(Keypad_Row_Port_Arr[j], Keypad_Row_Port_Arr[j]) == DIO_PIN_LOW) {
                    /* Do Nothing. */
                }

                break;
            }
        }

        /* Deactivate Current Column. */
        DIO_setPinValue(Keypad_Column_Port_Arr[i], Keypad_Column_Pin_Arr[i], DIO_PIN_HIGH);

        if (pressed_key != KEYPAD_NO_PRESSED_KEY) {
            break;
        }
    }
	return pressed_key;
}

