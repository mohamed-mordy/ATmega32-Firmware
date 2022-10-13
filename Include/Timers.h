/********************************************************************
 * @Title       : Timers
 * @Filename    : Timers.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 24, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#define ENABLED  1
#define DISABLED 0

/* Timers Clock Sources. */
#define   NO_CLK_SRC                       0
#define   CLK_PRESCALER_1                  1
#define   CLK_PRESCALER_8                  2
#define   CLK_PRESCALER_64                 3
#define   CLK_PRESCALER_256                4
#define   CLK_PRESCALER_1024               5
#define   CLK_EXT_FALLING_EDGE             6
#define   CLK_EXT_RISING_EDGE              7

/* Timer0 Wave Generation Modes. */
#define   TIMER0_NORMAL_MODE               0
#define   TIMER0_PWM_PHASE_CORRECT         1
#define   TIMER0_CLEAR_TIMER_ON_COMPARE    2      
#define   TIMER0_PWM_FAST                  3     

/* Timer0 Output compare pin behaviour. */
#define NORMAL_PORT_OPERATION              0
#define TOGGLE_OC                          1
#define CLEAR_OC                           2
#define SET_OC                             3

/* Timer1 Wave Generation Modes. */
//TIMER1__TIMER-MODE__TOP-VALUE__UPDATE-OF-OCR1x__TOV1-FLAG-SET-ON
#define   TIMER1_NORMAL__0XFFFF__IMMEDIATE__MAX                           0
#define   TIMER1_PWM_PHASE_CORRECT_8_BIT__0X00FF__TOP__BOTTOM             1               
#define   TIMER1_PWM_PHASE_CORRECT_9_BIT__0X01FF__TOP__BOTTOM             2               
#define   TIMER1_PWM_PHASE_CORRECT_10_BIT__0X03FF__TOP__BOTTOM            3                
#define   TIMER1_CTC__OCR1A_IMMEDIATE_MAX                                 4
#define   TIMER1_FAST_PWM_8_BIT__0X00FF__BOTTOM__TOP                      5      
#define   TIMER1_FAST_PWM_9_BIT__0X01FF__BOTTOM__TOP                      6      
#define   TIMER1_FAST_PWM_10_BIT__0X03FF__BOTTOM__TOP                     7       
#define   TIMER1_PWM_PHASE_FREQ_CORRECT__ICR1__BOTTOM__BOTTOM             8               
#define   TIMER1_PWM_PHASE_FREQ_CORRECT__OCR1A__BOTTOM__BOTTOM            9                
#define   TIMER1_PWM_PHASE_CORRECT__ICR1__TOP__BOTTOM                     10      
#define   TIMER1_PWM_PHASE_CORRECT__OCR1A__TOP__BOTTOM                    11       
#define   TIMER1_CTC_ICR1__ICR1__IMMEDIATE__MAX                           13
#define   TIMER1_FAST_PWM_ICR1__ICR1__BOTTOM__TOP                         14  
#define   TIMER1_FAST_PWM_OCR1A__OCR1A__BOTTOM__TOP                       15    


/* ICU */
#define ICU_RISING  1
#define ICU_FALLING 2

typedef enum {
    TIMER2_COMP,
    TIMER2_OVF,
    TIMER1_CAPT,
    TIMER1_COMPA,
    TIMER1_COMPB,
    TIMER1_OVF,
    TIMER0_COMP,
    TIMER0_OVF,
} Callback_t;

typedef enum {
	TIMER_0,
	TIMER_1,
	TIMER_2,
} Timer_t;

void Timers_vInit(void);
void Timers_vSetBusyWait_synch(u32 u32_Tick, u8 u8_TimerID);
void Timers_vStartTimer(Timer_t tmr);
void Timers_vSetClk(u8 u8_TimerID, u8 clk);
void Timers_vStopTimer(u8 u8_TimerID);
u16 Timers_u16GetElapsedTime(Timer_t tmr);
void Timers_vSetPreloadValue(u8 u8_TimerID, u16 u16_preload);
void Timers_vSetCompareMatchValue(Timer_t tmr, u16 u16_ocrValue);
void Timers_vEnableInterrupts(u8 interrupt);
void Timers_vDisableInterrupts(u8 interrupt);
void Timers_vSetCallback(Callback_t cbk, void (*fptr)(void));


#endif /* TIMERS_INTERFACE_H_ */

