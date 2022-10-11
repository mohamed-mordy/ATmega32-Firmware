/********************************************************************
 * @Title       : Digital Input / Output (DIO)
 * @Filename    : DIO.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 16, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#include <Std_Types.h>
#include <Bit_Math.h>

#include <DIO.h>

#include <DIO_private.h>
#include <DIO_config.h>

/**
 * @addtogroup MCU_Drivers
 * @{
 */

typedef volatile u8* RegType;
static const RegType DDR_Array [DIO_NUMBER_OF_PORTS]  = {DDRA ,  DDRB,  DDRC,  DDRD};
static const RegType PORT_Array[DIO_NUMBER_OF_PORTS]  = {PORTA, PORTB, PORTC, PORTD};
static const RegType PIN_Array [DIO_NUMBER_OF_PORTS]  = {PINA ,  PINB,  PINC,  PIND};

/********************************************************************
 * Function: void DIO_setPinDirection(DIO_Port_t port, DIO_Pin_t pin, DIO_Dir_t direction)
 */
/**
 * \b Description:
 *
 * This function is used to set the DIO Pin Direction
 *
 * @param [in] port is the ID of the port to chnage the direction of one of its pins.
 * @param [in] pin is the Pin Number in the specified port.
 * @param [in] direction is the direction to which the Pin will be set.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * DIO_setPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
 * @endcode
 * @see DIO_setPortDirection()
 */
void DIO_setPinDirection(DIO_Port_t port, DIO_Pin_t pin, DIO_Dir_t direction)
{
    if (direction == DIO_INPUT) {
        CLEAR_BIT(*DDR_Array[port], pin);
    } else if (direction == DIO_OUTPUT) {
        SET_BIT(*DDR_Array[port], pin);
    } else {
        /* Error. */
    }
}

/********************************************************************
 * Function: void DIO_setPinValue(DIO_Port_t port, DIO_Pin_t pin, DIO_Level_t value)
 */
/**
 * \b Description:
 *
 * This function is used to set the DIO Pin Value
 *
 * @param [in] port is the ID of the port to chnage the value of one of its pins.
 * @param [in] pin is the Pin Number in the specified port.
 * @param [in] value is the new value to which the Pin will be set.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * DIO_setPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
 * @endcode
 * @see DIO_setPortValue()
 */
void DIO_setPinValue(DIO_Port_t port, DIO_Pin_t pin, DIO_Level_t value)
{
    if (value == DIO_HIGH) {
        SET_BIT(*PORT_Array[port], pin);
    } else if (value == DIO_LOW) {
        CLEAR_BIT(*PORT_Array[port], pin);
    } else {
        /* Error */
    }
}

/********************************************************************
 * Function: DIO_Level_t DIO_getPinValue(DIO_Port_t port, DIO_Pin_t pin)
 */
/**
 * \b Description:
 *
 * This function is used to get the DIO Pin value
 *
 * @param [in] port is the ID of the port to get the value of one of its pins.
 * @param [in] pin is the Pin Number in the specified port.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * DIO_getPinValue(DIO_PORTA, DIO_PIN0);
 * @endcode
 * @see DIO_setPinValue()
 */
DIO_Level_t DIO_getPinValue(DIO_Port_t port, DIO_Pin_t pin)
{
    return (DIO_Level_t)GET_BIT(*PIN_Array[port], pin);
}

/********************************************************************
 * Function: void DIO_togglePinValue(DIO_Port_t port, DIO_Pin_t pin)
 */
/**
 * \b Description:
 *
 * This function is used to toggle the DIO Pin value
 *
 * @param [in] port is the ID of the port to toggle the value of one of its pins.
 * @param [in] pin is the Pin Number in the specified port.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * DIO_togglePinValue(DIO_PORTA, DIO_PIN0);
 * @endcode
 *
 * @see DIO_togglePortValue()
 */
void DIO_togglePinValue(DIO_Port_t port, DIO_Pin_t pin)
{
    TOGGLE_BIT(*PORT_Array[port], pin);
}

/********************************************************************
 * Function: void DIO_setPortDirection(DIO_Port_t port, DIO_PortDir_t portDir)
 */
/**
 * \b Description:
 *
 * This function is used to set the DIO Port Direction
 *
 * @param [in] port is the ID of the port to chnage its direction.
 * @param [in] portDir is the new direction of the specified port.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * DIO_PortDir_t direction = (DIO_INPUT << DIO_PIN4) |
 *                           (DIO_OUTPUT << DIO_PIN5);
 * DIO_setPinDirection(DIO_PORTA, direction);
 * @endcode
 *
 * @see DIO_setPinDirection()
 */
void DIO_setPortDirection(DIO_Port_t port, DIO_PortDir_t portDir)
{
    *DDR_Array[port] = portDir;
}

/********************************************************************
 * Function: void DIO_setPortValue(DIO_Port_t port, DIO_PortLevel_t PortLevel)
 */
/**
 * \b Description:
 *
 * This function is used to set the DIO Port value
 *
 * @param [in] port is the ID of the port to set its value.
 * @param [in] PortLevel is the new Port Level
 * @return     void
 *
 * \b Example:
 *
 * @code
 * DIO_PortLevel_t led_array = (DIO_HIGH << DIO_PIN0) |
 *                             (DIO_LOW  << DIO_PIN1) |
 *                             (DIO_HIGH << DIO_PIN2) |
 *                             (DIO_LOW  << DIO_PIN3) |
 *                             (DIO_LOW  << DIO_PIN4) |
 *                             (DIO_LOW  << DIO_PIN5) |
 *                             (DIO_LOW  << DIO_PIN6) |
 *                             (DIO_LOW  << DIO_PIN7);
 * DIO_setPortValue(DIO_PORTA, led_array);
 * @endcode
 *
 * @see DIO_setPinValue()
 */
void DIO_setPortValue(DIO_Port_t port, DIO_PortLevel_t PortLevel)
{
    *PORT_Array[port] = PortLevel;
}

/********************************************************************
 * Function: DIO_PortLevel_t DIO_getPortValue(DIO_Port_t port)
 */
/**
 * \b Description:
 *
 * This function is used to get the DIO Port Value.
 *
 * @param [in] port is the ID of the port to get its value.
 * @return     DIO_PortLevel_t The value of the specified port.
 *
 * \b Example:
 *
 * @code
 * DIO_PortLevel_t port_a;
 * port_A = DIO_getPortValue(DIO_PORTA);
 * @endcode
 *
 * @see DIO_getPinValue()
 */
DIO_PortLevel_t DIO_getPortValue(DIO_Port_t port)
{
    return *PIN_Array[port];
}

/********************************************************************
 * Function: void DIO_togglePortValue(DIO_Port_t port)
 */
/**
 * \b Description:
 *
 * This function is used to toggle the port value.
 *
 * @param [in] port is the ID of the port to toggle its value.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * DIO_togglePortValue(DIO_PORTA);
 * @endcode
 *
 * @see DIO_togglePinValue()
 */
void DIO_togglePortValue(DIO_Port_t port)
{
    *PORT_Array[port] ^= DIO_PORT_MASK;
}

/**
 * @}
 */

