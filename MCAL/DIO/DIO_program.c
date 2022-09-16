/*
 * DIO_program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Mohamed
 */


#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"



void DIO_setPinDirection(u8 portID, u8 pinNo, u8 direction)
{
    if (direction == INPUT) {
        switch (portID) {
            case 0:
                CLEAR_BIT(DDRA, pinNo);
                break;
            case 1:
                CLEAR_BIT(DDRB, pinNo);
                break;
            case 2:
                CLEAR_BIT(DDRC, pinNo);
                break;
            case 3:
                CLEAR_BIT(DDRD, pinNo);
                break;
        }
    } else if (direction == OUTPUT) {
        switch (portID) {
            case 0:
                SET_BIT(DDRA, pinNo);
                break;
            case 1:
                SET_BIT(DDRB, pinNo);
                break;
            case 2:
                SET_BIT(DDRC, pinNo);
                break;
            case 3:
                SET_BIT(DDRD, pinNo);
                break;
        }
    }
}

void DIO_setPinValue(u8 portID, u8 pinNo, u8 value)
{
    switch (portID) {
        case 0:
            SET_BIT(PORTA, value);
            break;
        case 1:
            SET_BIT(PORTB, value);
            break;
        case 2:
            SET_BIT(PORTC, value);
            break;
        case 3:
            SET_BIT(PORTD, value);
            break;
    }
}

u8 DIO_getPinValue(u8 portID, u8 pinNo)
{
    u8 value = 0;
    switch (portID) {
        case 0:
            value = GET_BIT(PINA, pinNo);
            break;
        case 1:
            value = GET_BIT(PINB, pinNo);
            break;
        case 2:
            value = GET_BIT(PINC, pinNo);
            break;
        case 3:
            value = GET_BIT(PIND, pinNo);
            break;
    }
    return value;
}

void DIO_togglePinValue(u8 portID, u8 pinNo)
{
    switch (portID) {
        case 0:
            TOGGLE_BIT(PORTA, pinNo);
            break;
        case 1:
            TOGGLE_BIT(PORTB, pinNo);
            break;
        case 2:
            TOGGLE_BIT(PORTC, pinNo);
            break;
        case 3:
            TOGGLE_BIT(PORTD, pinNo);
            break;
    }
}


void DIO_setPortDirection(u8 portID, u8 direction)
{
    switch (portID) {
        case 0:
            DDRA = direction;
            break;
        case 1:
            DDRB =  direction;
            break;
        case 2:
            DDRC = direction;
            break;
        case 3:
            DDRD = direction;
            break;
    }
}

void DIO_setPortValue(u8 portID, u8 value)
{
    switch (portID) {
        case 0:
            PORTA = value;
            break;
        case 1:
            PORTB =  value;
            break;
        case 2:
            PORTC = value;
            break;
        case 3:
            PORTD = value;
            break;
    }
}

u8 DIO_getPortValue(u8 portID)
{
    u8 value = 0;
    switch (portID) {
        case 0:
            value = PINA;
            break;
        case 1:
            value = PINB;
            break;
        case 2:
            value = PINC;
            break;
        case 3:
            value = PIND;
            break;
    }
    return value;
}

