/********************************************************************
 * @Title       : Timers
 * @Filename    : Timers.c
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 24, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#include <Std_Types.h>
#include <Bit_Math.h>
#include <DIO.h>
#include <Timers.h>
#include <Timers_private.h>
#include <Timers_config.h>


static void (*TIMER2_COMP_callbck) (void);  // vector 4
static void (*TIMER2_OVF_callbck) (void);
static void (*TIMER1_CAPT_callback) (void);
static void (*TIMER1_COMPA_callback) (void);
static void (*TIMER1_COMPB_callback) (void);
static void (*TIMER1_OVF_callback) (void);
static void (*TIMER0_COMP_callback) (void);
static void (*TIMER0_OVF_callback) (void);  // vector 11

void Timers_vInit(void)
{
    #if TIMER0_ENABLED == ENABLED
        /* 1. Select wave generation mode. */
        #if   TIMER0_WAVE_GENERATION == TIMER0_NORMAL_MODE            
            CLEAR_BIT(TCCR0, TCCR0_WGM00);
            CLEAR_BIT(TCCR0, TCCR0_WGM01);
        #elif TIMER0_WAVE_GENERATION == TIMER0_PWM_PHASE_CORRECT      
            SET_BIT(TCCR0, TCCR0_WGM00);
            CLEAR_BIT(TCCR0, TCCR0_WGM01);
        #elif TIMER0_WAVE_GENERATION == TIMER0_CLEAR_TIMER_ON_COMPARE 
            CLEAR_BIT(TCCR0, TCCR0_WGM00);
            SET_BIT(TCCR0, TCCR0_WGM01);
        #elif TIMER0_WAVE_GENERATION == TIMER0_PWM_FAST               
            SET_BIT(TCCR0, TCCR0_WGM00);
            SET_BIT(TCCR0, TCCR0_WGM01);
        #else
            #error " TIMER0_WAVE_GENERATION is not configured properly"
        #endif

        /* 2. Output compare mode. */
        #if   TIMER0_WAVE_GENERATION == TIMER0_NORMAL_MODE || TIMER0_WAVE_GENERATION == TIMER0_CLEAR_TIMER_ON_COMPARE
            TCCR0 &= ~(TCCR0_COM_MASK);
            TCCR0 |= TCCR0_COM_MASK & (TIMER0_COMPARE_OUTPUT_NON_PWM << TCCR0_COM00);
        #elif TIMER0_WAVE_GENERATION == TIMER0_PWM_FAST               
            TCCR0 &= ~(TCCR0_COM_MASK);
            TCCR0 |= TCCR0_COM_MASK & (TIMER0_COMPARE_OUTPUT_FAST_PWM << TCCR0_COM00);
        #elif TIMER0_WAVE_GENERATION == TIMER0_PWM_PHASE_CORRECT      
            TCCR0 &= ~(TCCR0_COM_MASK);
            TCCR0 |= TCCR0_COM_MASK & (TIMER0_COMPARE_OUTPUT_PHASE_CORRECT << TCCR0_COM00);
        #else
            #error
        #endif

        /* 3. Preload. */
        OCR0 = OCR0_OUTPUT_COMAPRE_VALUE;

        /* 4. Interrupt Enable/Disable */
        #if TIMER0_OVF_INTERRUPT_ENABLE == ENABLED
            SET_BIT(TIMSK, TIMSK_TOIE0);
        #else
            CLEAR_BIT(TIMSK, TIMSK_TOIE0);
        #endif
        #if TIMER0_CTC_INTERRUPT_ENABLE == ENABLED
            SET_BIT(TIMSK, TIMSK_OCIE0);
        #else
            CLEAR_BIT(TIMSK, TIMSK_OCIE0);
        #endif

        /* 5. Clock Select. */
        TCCR0 |= TCCR0_CS_MASK & TIMER0_CLK_SRC;
    #endif


    #if TIMER1_ENABLED == ENABLED
        /* 1. Select wave generation mode. */
        #if   TIMER1_WAVE_GENERATION == TIMER1_NORMAL__0XFFFF__IMMEDIATE__MAX                 
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_PWM_PHASE_CORRECT_8_BIT__0X00FF__TOP__BOTTOM   
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_PWM_PHASE_CORRECT_9_BIT__0X01FF__TOP__BOTTOM   
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_PWM_PHASE_CORRECT_10_BIT__0X03FF__TOP__BOTTOM  
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_CTC__OCR1A_IMMEDIATE_MAX                       
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_FAST_PWM_8_BIT__0X00FF__BOTTOM__TOP            
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_FAST_PWM_9_BIT__0X01FF__BOTTOM__TOP            
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_FAST_PWM_10_BIT__0X03FF__BOTTOM__TOP           
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_PWM_PHASE_FREQ_CORRECT__ICR1__BOTTOM__BOTTOM   
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_PWM_PHASE_FREQ_CORRECT__OCR1A__BOTTOM__BOTTOM  
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_PWM_PHASE_CORRECT__ICR1__TOP__BOTTOM           
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_PWM_PHASE_CORRECT__OCR1A__TOP__BOTTOM          
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_CTC_ICR1__ICR1__IMMEDIATE__MAX                 
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_FAST_PWM_ICR1__ICR1__BOTTOM__TOP               
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
        #elif TIMER1_WAVE_GENERATION == TIMER1_FAST_PWM_OCR1A__OCR1A__BOTTOM__TOP             
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
        #else
            #error "TIMER1_WAVE_GENERATION is not configured properly"
        #endif

        /* 2. Output compare mode. */
        TCCR1A &= ~TCCR1A_COM_MASK;
        TCCR1A |= TIMER1_UNIT_A_COMPARE_OUTPUT_NON_PWM << TCCR1A_COM1A0 | TIMER1_UNIT_B_COMPARE_OUTPUT_NON_PWM << TCCR1A_COM1B0;

        TCCR1A &= ~TCCR1A_COM_MASK;
        TCCR1A |= TIMER1_UNIT_A_COMPARE_OUTPUT_FAST_PWM  << TCCR1A_COM1A0 | TIMER1_UNIT_B_COMPARE_OUTPUT_FAST_PWM << TCCR1A_COM1B0;

        TCCR1A &= ~TCCR1A_COM_MASK;
        TCCR1A |= TIMER1_UNIT_A_COMPARE_OUTPUT_PHASE_CORRECT  << TCCR1A_COM1A0 | TIMER1_UNIT_B_COMPARE_OUTPUT_PHASE_CORRECT << TCCR1A_COM1B0;

        /* 3. Preload. */

        /* 4. Interrupt Enable/Disable */
        #if   TIMER1_INPUT_CAPTURE_INTERRUPT_ENABLE     == ENABLED
            SET_BIT(TIMSK, TIMSK_TICIE1);
        #elif TIMER1_INPUT_CAPTURE_INTERRUPT_ENABLE     == DISABLED
            CLEAR_BIT(TIMSK, TIMSK_TICIE1);
        #else
            #error " TIMER1_INPUT_CAPTURE_INTERRUPT_ENABLE is not configured properly"
        #endif

        #if   TIMER1_OUTPUT_COMPARE_A_INTERRUPT_ENABLE  == ENABLED
            SET_BIT(TIMSK, TIMSK_OCIE1A);
        #elif TIMER1_OUTPUT_COMPARE_A_INTERRUPT_ENABLE  == DISABLED
            CLEAR_BIT(TIMSK, TIMSK_OCIE1A);
        #else
            #error " TIMER1_OUTPUT_COMPARE_A_INTERRUPT_ENABLE is not configured properly"
        #endif

        #if   TIMER1_OUTPUT_COMPARE_B_INTERRUPT_ENABLE  == ENABLED
            SET_BIT(TIMSK, TIMSK_OCIE1B);
        #elif TIMER1_OUTPUT_COMPARE_B_INTERRUPT_ENABLE  == DISABLED
            CLEAR_BIT(TIMSK, TIMSK_OCIE1B);
        #else
            #error " TIMER1_OUTPUT_COMPARE_B_INTERRUPT_ENABLE is not configured properly"
        #endif

        #if   TIMER1_OVERFLOW_INTERRUPT_ENABLE          == ENABLED
            SET_BIT(TIMSK, TIMSK_TOIE1);
        #elif TIMER1_OVERFLOW_INTERRUPT_ENABLE          == DISABLED
            CLEAR_BIT(TIMSK, TIMSK_TOIE1);
        #else
            #error " TIMER1_OVERFLOW_INTERRUPT_ENABLE is not configured properly"
        #endif

        /* 5. Clock Select. */
        TCCR1B |= TCCR1_CS_MASK & TIMER1_CLK_SRC;
    #endif


    #if TIMER2_ENABLED == ENABLED

    #endif
}

void Timers_vSetClk(u8 u8_TimerID, u8 clk)
{
}

void Timers_vSetBusyWait_synch(u32 u32_Tick, u8 u8_TimerID)
{

}

u16 Timers1_u16GetICR1(void)
{
	return ICR1;
}

void Timers1_vSetSenseCtrl(u8 u8_SenseCtrl)
{
    switch (u8_SenseCtrl) {
        case ICU_RISING:
            SET_BIT(TCCR1B, TCCR1B_ICES1); 
            break;
        case ICU_FALLING:
            CLEAR_BIT(TCCR1B, TCCR1B_ICES1);
            break;
    }    
}

void Timers_vStartTimer(Timer_t tmr)
{
	switch (tmr) {
	case TIMER_0:
		TCNT0 = 0;
		break;
	case TIMER_1:
		TCNT1 = 0;
		break;
	case TIMER_2:
		break;
	}
}

void Timers_vStopTimer(u8 u8_TimerID)
{

}

u16 Timers_u16GetElapsedTime(Timer_t tmr)
{
	u16 lcl_ElapsedTime = 0;
	switch (tmr) {
		case TIMER_0:
			lcl_ElapsedTime = TCNT0;
			break;
		case TIMER_1:
            lcl_ElapsedTime = TCNT1;
			break;
		case TIMER_2:
			break;
		default:
			/* Error. */
			break;
	}
	return lcl_ElapsedTime;
}

void Timers_vSetPreloadValue(u8 u8_TimerID, u16 u16_preload)
{

}

void Timers_vSetCompareMatchValue(Timer_t tmr, u16 u16_ocrValue)
{
	switch (tmr) {
		case TIMER_0:
			OCR0 = u16_ocrValue;
			break;
		case TIMER_1:

			break;
		case TIMER_2:

			break;
		default:
			/*Error*/
			break;
	}
}

void Timers_vEnableInterrupts(u8 interrupt)
{
    SET_BIT(TIMSK, interrupt);
}

void Timers_vDisableInterrupts(u8 interrupt)
{
    CLEAR_BIT(TIMSK, interrupt);
}

void Timers_vSetCallback(Callback_t cbk, void (*fptr)(void))
{
    switch (cbk) {
        case TIMER2_COMP:
            TIMER2_COMP_callbck = fptr;
            break;
        case TIMER2_OVF:
            TIMER2_OVF_callbck = fptr;
            break;
        case TIMER1_CAPT:
            TIMER1_CAPT_callback = fptr;
            break;
        case TIMER1_COMPA:
            TIMER1_COMPA_callback = fptr;
            break;
        case TIMER1_COMPB:
            TIMER1_COMPB_callback = fptr;
            break;
        case TIMER1_OVF:
            TIMER1_OVF_callback = fptr;
            break;
        case TIMER0_COMP:
            TIMER0_COMP_callback = fptr;
            break;
        case TIMER0_OVF:
            TIMER0_OVF_callback = fptr;
            break;
        default:
            /* Error. */
            break;
    }
}

void __vector_4(void) __attribute((signal));
void __vector_4(void) 
{
    if (TIMER2_COMP_callbck) {
        TIMER2_COMP_callbck();
    }
}

void __vector_5(void) __attribute((signal));
void __vector_5(void) 
{
    if (TIMER2_OVF_callbck) {
        TIMER2_OVF_callbck();
    }
}

void __vector_6(void) __attribute((signal));
void __vector_6(void) 
{
    if (TIMER1_CAPT_callback) {
        TIMER1_CAPT_callback();
    }
}

void __vector_7(void) __attribute((signal));
void __vector_7(void) 
{
    if (TIMER1_COMPA_callback) {
        TIMER1_COMPA_callback();
    }
}

void __vector_8(void) __attribute((signal));
void __vector_8(void) 
{
    if (TIMER1_COMPB_callback) {
        TIMER1_COMPB_callback();
    }
}

void __vector_9(void) __attribute((signal));
void __vector_9(void) 
{
    if (TIMER1_OVF_callback) {
        TIMER1_OVF_callback();
    }
}

void __vector_10(void) __attribute((signal));
void __vector_10(void)
{
    if (TIMER0_COMP_callback) {
        TIMER0_COMP_callback();
    }
}

void __vector_11(void) __attribute((signal));
void __vector_11(void) 
{
    if (TIMER0_OVF_callback) {
        TIMER0_OVF_callback();
    }
}

