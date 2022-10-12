/********************************************************************
 * @Title       : Port Driver
 * @Filename    : Port.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 5, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */


/**
 * @addtogroup MCU_Drivers
 * @{
 */

#include <Std_Types.h>
#include <Port.h>
#include <Port_config.h> /* Include order is mandatory here */
#include <Port_private.h>
#include <Port_register.h>

/********************************************************************
 * Function: 
 */
/**
 * \b Description:
 *
 * Initializes the directions and levels of all the port pins of the MCU.
 *
 * @param [in] void
 * @return     void
 *
 * \b Example:
 *
 * @code
 * Port_vInit();
 * @endcode
 *
 */
void Port_vInit(void)
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

/**
 * @}
 */

