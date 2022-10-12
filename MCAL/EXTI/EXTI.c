/********************************************************************
 * @Title       : External Interrupts (EXTI)
 * @Filename    : EXTI.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 21, 2022
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
#include <DIO.h>
#include <EXTI.h>
#include <EXTI_private.h>
#include <EXTI_config.h>

typedef void (*VID_VID_FPTR_TYPE)(void);
static VID_VID_FPTR_TYPE G_EXTI_Callback[3]; /* Only three External Interrupts. */

/********************************************************************
 * Function: void EXTI_vInit(void)
 */
/**
 * \b Description:
 *
 * Initializes the EXTI Driver.
 *
 * @param [in] void
 * @return     void
 *
 * \b Example:
 *
 * @code
 * EXTI_vInit();
 * @endcode
 *
 * @see EXTI_vSetSenseCtrl()
 * @see EXTI_vEnableInterrupt()
 * @see EXTI_vDisableInterrupt()
 * @see EXTI_vRegisterCallback()
 */
void EXTI_vInit(void)
{
	/* 1. make pins input */
    #if EXTI_ENABLE_INT0 == ENABLED
        DIO_setPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);  // should be input
        DIO_setPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH); // set pull-up
    #endif

    #if EXTI_ENABLE_INT1 == ENABLED
        DIO_setPinDirection(DIO_PORTD, DIO_PIN3, DIO_INPUT);
        DIO_setPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH); // set pull-up
    #endif

    #if EXTI_ENABLE_INT2 == ENABLED
        DIO_setPinDirection(DIO_PORTB, DIO_PIN2, DIO_INPUT);
        DIO_setPinValue(DIO_PORTB, DIO_PIN2, DIO_HIGH); // set pull-up
    #endif


	/* 2. sense control */
    /* INT0 */
    #if EXTI_TRIGGER_MODE_INT0 == LOW_LEVEL
        CLEAR_BIT(MCUCR, MCUCR_ISC00);
        CLEAR_BIT(MCUCR, MCUCR_ISC01);
    #elif EXTI_TRIGGER_MODE_INT0 == BOTH_EDGES
        SET_BIT(MCUCR, MCUCR_ISC00);
        CLEAR_BIT(MCUCR, MCUCR_ISC01);
    #elif EXTI_TRIGGER_MODE_INT0 == FALLING_EDGE
        CLEAR_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
    #elif EXTI_TRIGGER_MODE_INT0 == RISING_EDGE
        SET_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
    #else
    #error "EXTI_TRIGGER_MODE_INT0 is not configured properly"
    #endif

    /* INT1 */
    #if EXTI_TRIGGER_MODE_INT1 == LOW_LEVEL
        CLEAR_BIT(MCUCR, MCUCR_ISC10);
        CLEAR_BIT(MCUCR, MCUCR_ISC11);
    #elif EXTI_TRIGGER_MODE_INT1 == BOTH_EDGES
        SET_BIT(MCUCR, MCUCR_ISC10);
        CLEAR_BIT(MCUCR, MCUCR_ISC11);
    #elif EXTI_TRIGGER_MODE_INT1 == FALLING_EDGE
        CLEAR_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
    #elif EXTI_TRIGGER_MODE_INT1 == RISING_EDGE
        SET_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
    #else
        #error "EXTI_TRIGGER_MODE_INT1 is not configured properly"
    #endif

    /* INT2 */
    #if   EXTI_TRIGGER_MODE_INT2 == FALLING_EDGE
        CLEAR_BIT(MCUCSR, MCUCSR_ISC2);
    #elif EXTI_TRIGGER_MODE_INT2 == RISING_EDGE
        SET_BIT(MCUCSR, MCUCSR_ISC2);
    #else
        #error "EXTI_TRIGGER_MODE_INT2 is not configured properly"
    #endif

	/* 3. enable interrupt */
    /* INT0 */
    #if EXTI_ENABLE_INT0 == ENABLED
        SET_BIT(GICR, GICR_INT0);
    #endif

    /* INT1 */
    #if EXTI_ENABLE_INT1 == ENABLED
        SET_BIT(GICR, GICR_INT1);
    #endif

    /* INT2 */
    #if EXTI_ENABLE_INT2 == ENABLED
        SET_BIT(GICR, GICR_INT2);
    #endif
}

/********************************************************************
 * Function: void EXTI_vSetSenseCtrl(EXTI_t exti, u8 u8_SenseCtrl)
 */
/**
 * \b Description:
 *
 * Sets the sense Control of the EXTI.
 *
 * @param [in] exti The type of External Interrupt to set its sense control.
 * @param [in] u8_SenseCtrl The Sense Control to be set.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * EXTI_vSetSenseCtrl(EXTI_0, RISING_EDGE);
 * @endcode
 *
 * @see EXTI_vEnableInterrupt()
 * @see EXTI_vDisableInterrupt()
 */
void EXTI_vSetSenseCtrl(EXTI_t exti, u8 u8_SenseCtrl)
{
	switch (exti) {
		case EXTI_0:
			switch (u8_SenseCtrl) {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR, MCUCR_ISC00);
                    CLEAR_BIT(MCUCR, MCUCR_ISC01);
                    break;
                case BOTH_EDGES:
                    SET_BIT(MCUCR, MCUCR_ISC00);
                    CLEAR_BIT(MCUCR, MCUCR_ISC01);
                    break;
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, MCUCR_ISC00);
                    SET_BIT(MCUCR, MCUCR_ISC01);
                    break;
                case RISING_EDGE:
                    SET_BIT(MCUCR, MCUCR_ISC00);
                    SET_BIT(MCUCR, MCUCR_ISC01);
                    break;
                default:
                    /*Error*/
                    break;
			}
			break;
		case EXTI_1:
			switch (u8_SenseCtrl) {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR, MCUCR_ISC10);
                    CLEAR_BIT(MCUCR, MCUCR_ISC11);
                    break;
                case BOTH_EDGES:
                    SET_BIT(MCUCR, MCUCR_ISC10);
                    CLEAR_BIT(MCUCR, MCUCR_ISC11);
                    break;
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, MCUCR_ISC10);
                    SET_BIT(MCUCR, MCUCR_ISC11);
                    break;
                case RISING_EDGE:
                    SET_BIT(MCUCR, MCUCR_ISC10);
                    SET_BIT(MCUCR, MCUCR_ISC11);
                    break;
                default:
                    /*Error*/
                    break;
			}
			break;
		case EXTI_2:
			switch (u8_SenseCtrl) {
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCSR, MCUCSR_ISC2);
                    break;
                case RISING_EDGE:
                    SET_BIT(MCUCSR, MCUCSR_ISC2);
                    break;
                default:
                    /*Error*/
                    break;
			}
			break;
		default:
			/*Error*/
            break;
	}
}

/********************************************************************
 * Function: void EXTI_vEnableInterrupt(EXTI_t exti)
 */
/**
 * \b Description:
 *
 * Enables the interrupt for the provided External Interrupt.
 *
 * @param [in] exti The External Interrupt to be enabled.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * EXTI_vEnableInterrupt(EXTI_0);
 * @endcode
 *
 * @see EXTI_vDisableInterrupt()
 */
void EXTI_vEnableInterrupt(EXTI_t exti)
{
	switch (exti) {
        case EXTI_0:
            SET_BIT(GICR, GICR_INT0);
            break;
        case EXTI_1:
            SET_BIT(GICR, GICR_INT1);
            break;
        case EXTI_2:
            SET_BIT(GICR, GICR_INT2);
            break;
        default:
            /*Error*/
            break;
	}
}

/********************************************************************
 * Function: void EXTI_vDisableInterrupt(EXTI_t exti)
 */
/**
 * \b Description:
 *
 * Disables The External Interrupts for the provided Interrupt type.
 *
 * @param [in] exti The External Interrupt to be disabled.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * EXTI_vDisableInterrupt(EXTI_1);
 * @endcode
 *
 * @see EXTI_vEnableInterrupt();
 */
void EXTI_vDisableInterrupt(EXTI_t exti)
{
	switch (exti) {
        case EXTI_0:
            CLEAR_BIT(GICR, GICR_INT0);
            break;
        case EXTI_1:
            CLEAR_BIT(GICR, GICR_INT1);
            break;
        case EXTI_2:
            CLEAR_BIT(GICR, GICR_INT2);
            break;
        default:
            /*Error*/
            break;
	}
}

/********************************************************************
 * Function: void EXTI_vRegisterCallback(EXTI_t exti, void (*fptr)(void))
 */
/**
 * \b Description:
 *
 * Registers a callback function for each External Interrupt.
 *
 * @param [in] exti The External Interrupt to register a callback for it.
 * @param [in] fptr The callback function.
 * @return     void
 *
 * \b Example:
 *
 * @code
 * void do_action(void);
 * void do_action(void)
 * {
 *     // Do some actions here based on External Interrupt.
 * }
 * EXTI_vRegisterCallback(EXTI_1, do_action);
 * @endcode
 *
 * @see EXTI_vSetSenseCtrl()
 * @see EXTI_vEnableInterrupt()
 * @see EXTI_vDisableInterrupt()
 */
void EXTI_vRegisterCallback(EXTI_t exti, void (*fptr)(void))
{
    G_EXTI_Callback[exti] = fptr;
}

/********************************************************************
 * Function: void __vector_1(void)
 */
/**
 * \b Description:
 *
 * The ISR corresponding to External Interrups 0
 *
 * @param [in] void
 * @return     void
 *
 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (G_EXTI_Callback[EXTI_0]) {
        G_EXTI_Callback[EXTI_0]();
    }
}

/********************************************************************
 * Function: void __vector_2(void)
 */
/**
 * \b Description:
 *
 * The ISR corresponding to External Interrups 1
 *
 * @param [in] void
 * @return     void
 *
 */
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
    if (G_EXTI_Callback[EXTI_1]) {
        G_EXTI_Callback[EXTI_1]();
    }
}

/********************************************************************
 * Function: void __vector_3(void)
 */
/**
 * \b Description:
 *
 * The ISR corresponding to External Interrups 2
 *
 * @param [in] void
 * @return     void
 *
 */
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
    if (G_EXTI_Callback[EXTI_2]) {
        G_EXTI_Callback[EXTI_2]();
    }
}

/**
 * @}
 */

