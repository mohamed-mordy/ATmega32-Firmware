/********************************************************************
 * @Title       : Watchdog Timer (WDT)
 * @Filename    : WDT.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Oct 1, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */


/**
 * @addtogroup MCU_Drivers
 * @{
 */

#include "Std_Types.h"
#include "Bit_Math.h"
#include "WDT.h"
#include "WDT_private.h"
#include "WDT_config.h"


/********************************************************************
 * Function: 
 */
/**
 * \b Description:
 *
 * Enables the Watchdog Timer with a specific period.
 *
 * @param [in] timeout The Watchdog Timer timeout.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * WDT_vEnable(TIMEOUT_17_1ms);
 * @endcode
 *
 * @see WDT_vDisable()
 */
void WDT_vEnable(TimeOut_t timeout)
{
    u8 wdt_prescaler_mask = 1<<WDTCR_WDP2 | 1<<WDTCR_WDP1 | 1<<WDTCR_WDP0;
	WDTCR = (WDTCR & ~(wdt_prescaler_mask)) | (timeout & wdt_prescaler_mask) ;
	SET_BIT(WDTCR, WDTCR_WDE); // WDE
}

/********************************************************************
 * Function: 
 */
/**
 * \b Description:
 *
 * Disables Watchdog Timer.
 *
 * @param [in] void
 * @return     void
 *
 * \b Example:
 *
 * @code
 * WDT_vDisable();
 * @endcode
 *
 * @see WDT_vEnable()
 */
void WDT_vDisable(void)
{
    WDTCR = (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE);
	WDTCR = 0;
}

/**
 * @}
 */

