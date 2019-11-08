#ifndef ALPHAFLYWHEEL_HPP
#define ALPHAFLYWHEEL_HPP

#include "main.h"

extern void StartFly(int rpm);
extern void StartIntake();
extern void TurnRight(int deg);
extern void TurnLeft(int deg);
extern void Move(double squares);
extern void MotorPx(int power);
#endif
