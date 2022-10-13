/********************************************************************
 * @Title       : Timers
 * @Filename    : Timers_config.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 24, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

/*
###################################################
################ TIMER 0 CONFIG ###################
###################################################
*/
/***************************************************/
/*
 * Select one of the following:
 *      ENABLED
 *      DISABLED
 */
#define TIMER0_ENABLED      ENABLED
/***************************************************/


/***************************************************/
/*
 * Select one of the following:
 *       NO_CLK_SRC          
 *       CLK_PRESCALER_1     
 *       CLK_PRESCALER_8     
 *       CLK_PRESCALER_64    
 *       CLK_PRESCALER_256   
 *       CLK_PRESCALER_1024  
 *       CLK_EXT_FALLING_EDGE
 *       CLK_EXT_RISING_EDGE 
 */
#define  TIMER0_CLK_SRC  CLK_PRESCALER_8
/***************************************************/


/****************************************************/
/* 
 * Select one of the following:
 *      TIMER0_NORMAL_MODE            
 *      TIMER0_PWM_PHASE_CORRECT      
 *      TIMER0_CLEAR_TIMER_ON_COMPARE 
 *      TIMER0_PWM_FAST               
 */
#define   TIMER0_WAVE_GENERATION  TIMER0_PWM_FAST
/***************************************************/


/***************************************************/
/*
 * Set the output compare value
 */
#define OCR0_OUTPUT_COMAPRE_VALUE   100
/***************************************************/


/***************************************************/
/*
 * Select one of the following:
 *      NORMAL_PORT_OPERATION
 *      TOGGLE_OC
 *      CLEAR_OC
 *      SET_OC
 */
#define TIMER0_COMPARE_OUTPUT_NON_PWM
/***************************************************/


/***************************************************/
/*
 * Select one of the following:
 *      NORMAL_PORT_OPERATION
 *      CLEAR_OC
 *      SET_OC
 */
#define TIMER0_COMPARE_OUTPUT_FAST_PWM  CLEAR_OC
/***************************************************/


/***************************************************/
/*
 * Select one of the following:
 *      NORMAL_PORT_OPERATION
 *      CLEAR_OC
 *      SET_OC
 */
#define TIMER0_COMPARE_OUTPUT_PHASE_CORRECT
/***************************************************/

/***************************************************/
/*
 * Select one of the following:
 *      ENABLED
 *      DISABLED
 */
#define TIMER0_OVF_INTERRUPT_ENABLE   DISABLED
#define TIMER0_CTC_INTERRUPT_ENABLE   DISABLED
/***************************************************/

/*
###################################################
################ TIMER 1 CONFIG ###################
###################################################
*/

/***************************************************/
/*
 * Select one of the following:
 *      ENABLED
 *      DISABLED
 */
#define TIMER1_ENABLED      ENABLED
/***************************************************/

/***************************************************/
/*
 * Select one of the following:
 *       NO_CLK_SRC          
 *       CLK_PRESCALER_1     
 *       CLK_PRESCALER_8     
 *       CLK_PRESCALER_64    
 *       CLK_PRESCALER_256   
 *       CLK_PRESCALER_1024  
 *       CLK_EXT_FALLING_EDGE
 *       CLK_EXT_RISING_EDGE 
 */
#define  TIMER1_CLK_SRC  CLK_PRESCALER_8
/***************************************************/

/****************************************************/
/* TIMER1__TIMER-MODE__TOP-VALUE__UPDATE-OF-OCR1x__TOV1-FLAG-SET-ON
 * Select one of the following:
 *      TIMER1_NORMAL__0XFFFF__IMMEDIATE__MAX
 *      TIMER1_PWM_PHASE_CORRECT_8_BIT__0X00FF__TOP__BOTTOM
 *      TIMER1_PWM_PHASE_CORRECT_9_BIT__0X01FF__TOP__BOTTOM
 *      TIMER1_PWM_PHASE_CORRECT_10_BIT__0X03FF__TOP__BOTTOM
 *      TIMER1_CTC__OCR1A_IMMEDIATE_MAX
 *      TIMER1_FAST_PWM_8_BIT__0X00FF__BOTTOM__TOP
 *      TIMER1_FAST_PWM_9_BIT__0X01FF__BOTTOM__TOP
 *      TIMER1_FAST_PWM_10_BIT__0X03FF__BOTTOM__TOP
 *      TIMER1_PWM_PHASE_FREQ_CORRECT__ICR1__BOTTOM__BOTTOM
 *      TIMER1_PWM_PHASE_FREQ_CORRECT__OCR1A__BOTTOM__BOTTOM
 *      TIMER1_PWM_PHASE_CORRECT__ICR1__TOP__BOTTOM
 *      TIMER1_PWM_PHASE_CORRECT__OCR1A__TOP__BOTTOM
 *      TIMER1_CTC_ICR1__ICR1__IMMEDIATE__MAX
 *      TIMER1_FAST_PWM_ICR1__ICR1__BOTTOM__TOP
 *      TIMER1_FAST_PWM_OCR1A__OCR1A__BOTTOM__TOP
 */
#define   TIMER1_WAVE_GENERATION  TIMER1_FAST_PWM_ICR1__ICR1__BOTTOM__TOP
/***************************************************/

/***************************************************/
/*
 * Set the output compare value
 */
#define OCR1A_OUTPUT_COMAPRE_VALUE   0x0000
#define OCR1B_OUTPUT_COMAPRE_VALUE   0x0000
/***************************************************/

/***************************************************/
/*
 * Select one of the following:
 *      NORMAL_PORT_OPERATION
 *      TOGGLE_OC
 *      CLEAR_OC
 *      SET_OC
 */
#define TIMER1_UNIT_A_COMPARE_OUTPUT_NON_PWM
#define TIMER1_UNIT_B_COMPARE_OUTPUT_NON_PWM
/***************************************************/

/***************************************************/
/*
 * Select one of the following:
 *      NORMAL_PORT_OPERATION
 *      TOGGLE_OC
 *      CLEAR_OC
 *      SET_OC
 */
#define TIMER1_UNIT_A_COMPARE_OUTPUT_FAST_PWM  CLEAR_OC
#define TIMER1_UNIT_B_COMPARE_OUTPUT_FAST_PWM  CLEAR_OC
/***************************************************/

/***************************************************/
/*
 * Select one of the following:
 *      NORMAL_PORT_OPERATION
 *      TOGGLE_OC
 *      CLEAR_OC
 *      SET_OC
 */
#define TIMER1_UNIT_A_COMPARE_OUTPUT_PHASE_CORRECT
#define TIMER1_UNIT_B_COMPARE_OUTPUT_PHASE_CORRECT
/***************************************************/

/***************************************************/
/*
 * Select one of the following:
 *      ENABLED
 *      DISABLED
 */
#define TIMER1_INPUT_CAPTURE_INTERRUPT_ENABLE          DISABLED
#define TIMER1_OUTPUT_COMPARE_A_INTERRUPT_ENABLE       DISABLED
#define TIMER1_OUTPUT_COMPARE_B_INTERRUPT_ENABLE       DISABLED
#define TIMER1_OVERFLOW_INTERRUPT_ENABLE               DISABLED
/***************************************************/



/*
###################################################
################ TIMER 2 CONFIG ###################
###################################################
*/

/***************************************************/
/*
 * Select one of the following:
 *      ENABLED
 *      DISABLED
 */
#define TIMER2_ENABLED      ENABLED
/***************************************************/

#endif /* TIMERS_CONFIG_H_ */

