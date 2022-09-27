/*
 * DIO_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Mohamed
 */



#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_



#define DIO_OUTPUT      1
#define DIO_INPUT       0

#define DIO_HIGH      1
#define DIO_LOW       0



#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3



#define DIO_PIN0     0    
#define DIO_PIN1     1    
#define DIO_PIN2     2    
#define DIO_PIN3     3    
#define DIO_PIN4     4    
#define DIO_PIN5     5    
#define DIO_PIN6     6    
#define DIO_PIN7     7    


void DIO_setPinDirection(u8 u8_portID, u8 u8_pinNo, u8 u8_direction);
void DIO_setPinValue(u8 u8_portID, u8 u8_pinNo, u8 u8_value);
u8 DIO_getPinValue(u8 u8_portID, u8 u8_pinNo);
void DIO_togglePinValue(u8 u8_portID, u8 u8_pinNo);
void DIO_setPortDirection(u8 u8_portID, u8 u8_direction);
void DIO_setPortValue(u8 u8_portID, u8 u8_value);
u8 DIO_getPortValue(u8 u8_portID);



#endif /* DIO_INTERFACE_H_ */

