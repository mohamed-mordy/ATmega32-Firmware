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

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define    ADC_CHANNEL_0                    0
#define    ADC_CHANNEL_1                    1
#define    ADC_CHANNEL_2                    2
#define    ADC_CHANNEL_3                    3
#define    ADC_CHANNEL_4                    4
#define    ADC_CHANNEL_5                    5
#define    ADC_CHANNEL_6                    6
#define    ADC_CHANNEL_7                    7

#define    ADC_Prescaler_2                  1
#define    ADC_Prescaler_4                  2
#define    ADC_Prescaler_8                  3
#define    ADC_Prescaler_16                 4 
#define    ADC_Prescaler_32                 5 
#define    ADC_Prescaler_64                 6 
#define    ADC_Prescaler_128                7  

#define    FREE_RUNNING_MODE                0
#define    ANALOG_COMPARATOR                1
#define    EXTERNAL_INTERRUPT_REQUEST_0     2           
#define    TIMER_COUNTER0_COMPARE_MATCH     3           
#define    TIMER_COUNTER0_OVERFLOW          4      
#define    TIMER_COUNTER1_COMPARE_MATCH_B   5             
#define    TIMER_COUNTER1_OVERFLOW          6      
#define    TIMER_COUNTER1_CAPTURE_EVEN      7          

void ADC_vInit(void);
u16 ADC_u16ReadDigitalValue_sync(u8 channelID);
void ADC_vSetCallback(void (*fpt)(void));
void ADC_vEnable(void);
void ADC_vDisable(void);
void ADC_vInterruptEnable(void);
void ADC_vInterruptDisable(void);
void ADC_vSelectChannel(u8 channelID);
void ADC_vStartConversion(void);
u16 ADC_u16ReadDigitalValue_async(void);

#endif /* ADC_INTERFACE_H_ */

