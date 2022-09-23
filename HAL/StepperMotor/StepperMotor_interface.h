#ifndef __STEPPER_MOTOR_INTERFACE_H__
#define __STEPPER_MOTOR_INTERFACE_H__

typedef struct {
	u8 Port;
	u8 Pin[4];
	s16 Angle;  // This for managing Absolute and Relative angle mode.
}

#define STEPPER_ANGLE_MODE  RELATIVE || ABSOLUTE


void STEPPER_Init(Stepper_t *me);

void STEPPER_MoveSteps(Stepper_t *me, u32 steps, u8 direction);

void STEPPER_MoveAngle(Stepper_t *me, s16 Angle);



#endif // __STEPPER_MOTOR_INTERFACE_H__
