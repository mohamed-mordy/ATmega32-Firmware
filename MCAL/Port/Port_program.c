/*
 * Port.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Mohamed
 */

#include <Std_Types.h>
#include <Port_interface.h>
#include <Port_config.h> /* Include order is mandatory here */
#include "Port_private.h"
#include "Port_register.h"


void Port_Init(void)
{
    DDRA = PORTA_DIR;
    DDRB = PORTB_DIR;
    DDRC = PORTC_DIR;
    DDRD = PORTD_DIR;

    PORTA = PORTA_INIT_VAL;
    PORTB = PORTB_INIT_VAL;
    PORTC = PORTC_INIT_VAL;
    PORTD = PORTD_INIT_VAL;
}

