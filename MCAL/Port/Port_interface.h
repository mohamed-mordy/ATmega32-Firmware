
#ifndef __PORT_H__
#define __PORT_H__


void Port_Init(const Port_ConfigType *ConfigPtr);

void Port_SetPinDirection(Port_PinType pin, Port_PinDirectionType direction);
void Port_RefreshPortDirection(void);
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo);
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode);

#endif  /* __PORT_H__ */

