/*
 * DIO_program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Mohamed
 */


#include "../DIO_config.h"
#include "../DIO_interface.h"
#include "../DIO_private.h"
#include "../Lib/Bit_Math.h"
#include "../Lib/Std_Types.h"



void DIO_setPinDirection(u8 u8_portID, u8 u8_pinNo, u8 u8_direction)
{
    if (u8_direction == DIO_INPUT) {
        switch (u8_portID) {
            case DIO_PORTA:
                CLEAR_BIT(DDRA, u8_pinNo);
                break;
            case DIO_PORTB:
                CLEAR_BIT(DDRB, u8_pinNo);
                break;
            case DIO_PORTC:
                CLEAR_BIT(DDRC, u8_pinNo);
                break;
            case DIO_PORTD:
                CLEAR_BIT(DDRD, u8_pinNo);
                break;
        }
    } else if (u8_direction == DIO_OUTPUT) {
        switch (u8_portID) {
            case DIO_PORTA:
                SET_BIT(DDRA, u8_pinNo);
                break;
            case DIO_PORTB:
                SET_BIT(DDRB, u8_pinNo);
                break;
            case DIO_PORTC:
                SET_BIT(DDRC, u8_pinNo);
                break;
            case DIO_PORTD:
                SET_BIT(DDRD, u8_pinNo);
                break;
        }
    }
}

void DIO_setPinValue(u8 u8_portID, u8 u8_pinNo, u8 u8_value)
{
    if (u8_value == DIO_HIGH) {
        switch (u8_portID) {
            case DIO_PORTA:
                SET_BIT(PORTA, u8_pinNo);
                break;
            case DIO_PORTB:
                SET_BIT(PORTB, u8_pinNo);
                break;
            case DIO_PORTC:
                SET_BIT(PORTC, u8_pinNo);
                break;
            case DIO_PORTD:
                SET_BIT(PORTD, u8_pinNo);
                break;
        }
    } else if (u8_value == DIO_HIGH) {
        switch (u8_portID) {
            case DIO_PORTA:
                CLEAR_BIT(PORTA, u8_pinNo);
                break;
            case DIO_PORTB:
                CLEAR_BIT(PORTB, u8_pinNo);
                break;
            case DIO_PORTC:
                CLEAR_BIT(PORTC, u8_pinNo);
                break;
            case DIO_PORTD:
                CLEAR_BIT(PORTD, u8_pinNo);
                break;
        }
    } else {
        /* Error */
    }
}

u8 DIO_getPinValue(u8 u8_portID, u8 u8_pinNo)
{
    u8 value = 0;
    switch (u8_portID) {
        case DIO_PORTA:
            value = GET_BIT(PORTA, u8_pinNo);
            break;
        case DIO_PORTB:
            value = GET_BIT(PORTB, u8_pinNo);
            break;
        case DIO_PORTC:
            value = GET_BIT(PORTC, u8_pinNo);
            break;
        case DIO_PORTD:
            value = GET_BIT(PORTD, u8_pinNo);
            break;
        default:
            /* Error*/
            break;
    }
    return value;
}

void DIO_togglePinValue(u8 u8_portID, u8 u8_pinNo)
{
    switch (u8_portID) {
        case DIO_PORTA:
            TOGGLE_BIT(PORTA, u8_pinNo);
            break;
        case DIO_PORTB:
            TOGGLE_BIT(PORTB, u8_pinNo);
            break;
        case DIO_PORTC:
            TOGGLE_BIT(PORTC, u8_pinNo);
            break;
        case DIO_PORTD:
            TOGGLE_BIT(PORTD, u8_pinNo);
            break;
        default:
            /* Error */
            break;
    }
}


void DIO_setPortDirection(u8 u8_portID, u8 u8_direction)
{
    switch (u8_portID) {
        case DIO_PORTA:
            DDRA = u8_direction;
            break;
        case DIO_PORTB:
            DDRB =  u8_direction;
            break;
        case DIO_PORTC:
            DDRC = u8_direction;
            break;
        case DIO_PORTD:
            DDRD = u8_direction;
            break;
        default:
            /* Error */
            break;
    }
}

void DIO_setPortValue(u8 u8_portID, u8 u8_value)
{
    switch (u8_portID) {
        case DIO_PORTA:
            PORTA = u8_value;
            break;
        case DIO_PORTB:
            PORTB =  u8_value;
            break;
        case DIO_PORTC:
            PORTC = u8_value;
            break;
        case DIO_PORTD:
            PORTD = u8_value;
            break;
        default:
            /* Error */
            break;
    }
}

u8 DIO_getPortValue(u8 u8_portID)
{
    u8 value = 0;
    switch (u8_portID) {
        case DIO_PORTA:
            value = PINA;
            break;
        case DIO_PORTB:
            value = PINB;
            break;
        case DIO_PORTC:
            value = PINC;
            break;
        case DIO_PORTD:
            value = PIND;
            break;
        default:
            /* Error */
            break;
    }
    return value;
}

