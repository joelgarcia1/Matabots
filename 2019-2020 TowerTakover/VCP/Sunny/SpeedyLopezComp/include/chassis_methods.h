#pragma once
#include "vex.h"

using namespace vex;

// Move Individual Sides
extern void RMove(double power);
extern void LMove(double power);

// Move Chassis Forward
extern void MoveForward(double inch, double pow);

// Turn Chassis Right
extern void TurnRight(double rDeg, double pow);

// Turn Chassis Left
extern void TurnLeft(double rDeg, double pow);