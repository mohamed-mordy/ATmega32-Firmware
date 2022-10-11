/********************************************************************
 * @Title       : Digital Input / Output (DIO)
 * @Filename    : DIO.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 16, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum {
    DIO_INPUT,
    DIO_OUTPUT,
} DIO_Dir_t;

typedef enum {
    DIO_LOW,
    DIO_HIGH,
} DIO_Level_t;

typedef enum {
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD,
} DIO_Port_t;

typedef enum {
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7,
} DIO_Pin_t;

typedef u8 DIO_PortDir_t;
typedef u8 DIO_PortLevel_t;

void DIO_setPinDirection(DIO_Port_t port, DIO_Pin_t pin, DIO_Dir_t direction);
void DIO_setPinValue(DIO_Port_t port, DIO_Pin_t pin, DIO_Level_t value);
void DIO_togglePinValue(DIO_Port_t port, DIO_Pin_t pin);
void DIO_setPortDirection(DIO_Port_t port, DIO_PortDir_t portDir);
void DIO_setPortValue(DIO_Port_t port, DIO_PortLevel_t PortLevel);
void DIO_togglePortValue(u8 u8_portID);
DIO_PortLevel_t DIO_getPortValue(DIO_Port_t port);
DIO_Level_t     DIO_getPinValue(DIO_Port_t port, DIO_Pin_t pin);

#endif /* DIO_INTERFACE_H_ */

