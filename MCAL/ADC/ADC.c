/********************************************************************
 * @Title       : Analog to Digital Converter (ADC)
 * @Filename    : ADC.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 23, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */


#include <Std_Types.h>
#include <Bit_Math.h>

#include <ADC_interface.h>
#include <ADC_private.h>
#include <ADC_config.h>

static void (*G_ADC_Callback)(void);

void ADC_vInit(void)
{
    /* 1. select reference bits */
    #if ADC_VREF == VREF_AREF
        CLEAR_BIT(ADMUX, ADMUX_REFS1);
        CLEAR_BIT(ADMUX, ADMUX_REFS0);
    #elif ADC_VREF == VREF_AVCC
        CLEAR_BIT(ADMUX, ADMUX_REFS1);
        SET_BIT(ADMUX, ADMUX_REFS0);
    #elif ADC_VREF == VREF_INTERNAL_VREF
        SET_BIT(ADMUX, ADMUX_REFS1);
        SET_BIT(ADMUX, ADMUX_REFS0);
    #else
        #error "ADC_VREF is not configured properly"
    #endif

	/* 2. select data adjustment. */
	CLEAR_BIT(ADMUX, ADMUX_ADLAR);  //right
                                    
	/* 3. ADC enable */
	SET_BIT(ADCSRA, ADCSRA_ADEN);

	/* 4. Auto trigger enable */
    #if ADC_TRIGGER_MODE  == AUTO_TRIGGER
        SET_BIT(ADCSRA, ADCSRA_ADATE); // Auto trigger on
        /* 4.a. Select Auto trigger source */
        SFIOR &= ~(0b11100000);
        SFIOR |= ADC_AUTO_TRIGGER_SOURCE << 5;

    #elif ADC_TRIGGER_MODE == SINGLE_CONVERSION
        CLEAR_BIT(ADCSRA, ADCSRA_ADATE); // Auto trigger off
    #else
        #error " ADC_TRIGGER_MODE is not configured properly"
    #endif

	/* 5. Interrupt Enable/Disable */
    #if ADC_INTERRUPT_ENABLE == ENABLED
        SET_BIT(ADCSRA, ADCSRA_ADIE);
    #elif ADC_INTERRUPT_ENABLE == DISABLED
        CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
    #else
        #error "ADC_INTERRUPT_ENABLE is not configured properly"
    #endif

	/* 6. conv. clock Prescaler */
	ADCSRA &= ~(ADC_PRESCALER_MASK);
	ADCSRA |= ADC_PRESCALER;
}

/**
 * @brief: Returns Digital value synchronously.
 * @note: Don't call with interrupt enabled.
 */
u16 ADC_u16ReadDigitalValue_sync(u8 channelID)
{
	 /*  1. select channel */
	ADMUX &= ~(0b11111); // clear 
	ADMUX |= (channelID & 0x07);  // Anding for validating the input (layman way)
                                  
	 /*  2. start conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);

	 /*  3. wait for conv. complete */
	while (GET_BIT(ADCSRA, ADCSRA_ADSC)) {
		/* Polling. */
	}

	/*  4. clear flag */
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/*  5. return ADC value */
    /*
     * return ADCL | ((u16)ADCH << 8);
     * or equivalently and cleaner
     */
	return ADC_DATA;
}

void ADC_vEnable(void)
{
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

void ADC_vDisable(void)
{
    CLEAR_BIT(ADCSRA, ADCSRA_ADEN);
}

void ADC_vInterruptEnable(void)
{
    SET_BIT(ADCSRA, ADCSRA_ADIE);
}

void ADC_vInterruptDisable(void)
{
    CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
}

void ADC_vSelectChannel(u8 channelID)
{
    ADMUX &= ~(ADC_CHANNEL_MASK);
    channelID &= ADC_CHANNEL_MASK;
    ADMUX |= channelID;
}

/**
 * @note Used with Interrupt enabled.
 */
void ADC_vStartConversion(void)
{
    SET_BIT(ADCSRA, ADCSRA_ADSC);
}

u16 ADC_u16ReadDigitalValue_async(void)
{
    return ADC_DATA;
}

void ADC_vSetCallback(void (*fptr)(void))
{
	G_ADC_Callback = fptr;
}

void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	if (G_ADC_Callback) {
		G_ADC_Callback();
	}
}
