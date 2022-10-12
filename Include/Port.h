/********************************************************************
 * @Title       : Port Driver
 * @Filename    : Port.h
 * @Author      : Mohamed Abdelmordy
 * @Origin Date : Sep 5, 2022
 * @Version     : 1.0.0
 * @Compiler    : avr-gcc
 * @Target      : ATmega32A
 * @Notes       : None
 */


#ifndef __PORT_H__
#define __PORT_H__


#define INPUT    0
#define OUTPUT   1

#define LOW      0
#define HIGH     1

void Port_Init(const Port_ConfigType *ConfigPtr);

void Port_SetPinDirection(Port_PinType pin, Port_PinDirectionType direction);

#endif  /* __PORT_H__ */

