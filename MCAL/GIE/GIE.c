/********************************************************************
 * @Title       : Global Interrupt Enable (GIE)
 * @Filename    : DIO.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 23, 2022
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
#include <Bit_Math.h>
#include <GIE.h>
#include <GIE_private.h>
#include <GIE_config.h>


/********************************************************************
 * Function: void GIE_vEnable(void)
 */
/**
 * \b Description:
 *
 * Enables Global Interrups.
 *
 * @param [in] void
 * @return     void
 *
 * \b Example:
 *
 * @code
 * GIE_vEnable();
 * @endcode
 *
 * @see GIE_vDisable()
 */
void GIE_vEnable(void)
{
	SET_BIT(SREG, 7);
}

/********************************************************************
 * Function: 
 */
/**
 * \b Description:
 *
 * Disables Global Interrups.
 *
 * @param [in] void
 * @return     void
 *
 * \b Example:
 * 
 * @code
 * GIE_vDisable();
 * @endcode
 *
 * @see GIE_vEnable()
 */
void GIE_vDisable(void)
{
	CLEAR_BIT(SREG, 7);
}

/**
 * @}
 */

