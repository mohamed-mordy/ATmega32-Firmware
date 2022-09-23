#ifndef __DCMOTOR_INTERFACE_H__
#define __DCMOTOR_INTERFACE_H__

enum DCMotor_Dir_t {
	CW, CWW, STOP
};

void DCMotor_Init(DCMotor_t *me, u8 port, u8 pinA, u8 pinB);
void DCMotor_SetSpeed(DCMotor_t *me, u16 speed);
void DCMotor_SetDirection(DCMotor_t *me, DCMotor_Dir_t direction);

void DCMotor_Run(DC_Motor_t *me);
void DCMotor_Stop(DC_Motor_t *me);



#endif // __DCMOTOR_INTERFACE_H__
