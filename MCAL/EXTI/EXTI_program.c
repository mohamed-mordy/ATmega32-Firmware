/*
 * EXTI_program.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed
 */

#include <Bit_Math.h>
#include <Std_Types.h>
#include <DIO_interface.h>
#include <EXTI_interface.h>
#include "EXTI_private.h"
#include <EXTI_config.h>


static void (*G_EXTI0_Callback)(void);
static void (*G_EXTI1_Callback)(void);
static void (*G_EXTI2_Callback)(void);

void EXTI_vInit(void)
{
	/* 1. make pins input */
    #if EXTI_ENABLE_INT0 == EXTI_ENABLE
        DIO_setPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);  // should be input
        DIO_setPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH); // set pull-up
    #endif

    #if EXTI_ENABLE_INT1 == EXTI_ENABLE
        DIO_setPinDirection(DIO_PORTD, DIO_PIN3, DIO_INPUT);
        DIO_setPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH); // set pull-up
    #endif

    #if EXTI_ENABLE_INT2 == EXTI_ENABLE
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
    #if EXTI_ENABLE_INT0 == EXTI_ENABLE
        SET_BIT(GICR, GICR_INT0);
    #elif EXTI_ENABLE_INT0 == EXTI_DISABLE
        CLEAR_BIT(GICR, GICR_INT0);
    #else
        #error "EXTI_ENABLE_INT0 is not configured properly"
    #endif

    /* INT1 */
    #if EXTI_ENABLE_INT1 == EXTI_ENABLE
        SET_BIT(GICR, GICR_INT1);
    #elif EXTI_ENABLE_INT1 == EXTI_DISABLE
        CLEAR_BIT(GICR, GICR_INT1);
    #else
        #error "EXTI_ENABLE_INT1 is not configured properly"
    #endif

    /* INT2 */
    #if EXTI_ENABLE_INT2 == EXTI_ENABLE
        SET_BIT(GICR, GICR_INT2);
    #elif EXTI_ENABLE_INT2 == EXTI_DISABLE
        CLEAR_BIT(GICR, GICR_INT2);
    #else
        #error "EXTI_ENABLE_INT2 is not configured properly"
    #endif
}

void EXTI_vSetSenseCtrl(u8 u8_ExtiPin, u8 u8_SenseCtrl)
{
	switch (u8_ExtiPin) {
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

void EXTI_vEnableInterrupt(u8 u8_ExtiPin, u8 u8_SenseCtrl)
{
	switch (u8_ExtiPin) {
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

void EXTI_vDisableInterrupt(u8 u8_ExtiPin)
{
	switch (u8_ExtiPin) {
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

void EXTI_vRegisterCallback(u8 u8_ExtiPin, void (*fptr)(void))
{
	switch (u8_ExtiPin) {
		case EXTI_0:
			G_EXTI0_Callback = fptr;
			break;
		case EXTI_1:
			G_EXTI1_Callback = fptr;
			break;
		case EXTI_2:
			G_EXTI2_Callback = fptr;
			break;
		default:
			/*Error*/
			break;
	}
}

#if EXTI_ENABLE_INT0 == EXTI_ENABLE
    void __vector_1(void)__attribute__((signal));
    void __vector_1(void)
    {
        if (G_EXTI0_Callback) {
            G_EXTI0_Callback();
        }
    }
#endif

#if EXTI_ENABLE_INT1 == EXTI_ENABLE
    void __vector_2(void)__attribute__((signal));
    void __vector_2(void)
    {
        if (G_EXTI1_Callback) {
            G_EXTI1_Callback();
        }
    }
#endif

#if EXTI_ENABLE_INT2 == EXTI_ENABLE
    void __vector_3(void)__attribute__((signal));
    void __vector_3(void)
    {
        if (G_EXTI2_Callback) {
            G_EXTI2_Callback();
        }
    }
#endif


