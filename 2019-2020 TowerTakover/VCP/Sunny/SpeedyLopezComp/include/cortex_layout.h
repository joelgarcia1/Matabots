#pragma once

#include "vex.h"

using namespace vex;

extern brain Brain;

// Right Drive
extern motor R1;
extern motor R2;
extern motor R3;
extern motor R4;
//extern motor R5;

// Left Drive
extern motor L1;
extern motor L2;
extern motor L3;
extern motor L4;
//extern motor L5;

// Lift Motor 
extern motor Lift;

// Intakes
extern motor rightIntake;
extern motor leftIntake;

// Arms
extern motor rightArm;
extern motor leftArm;

extern controller master;

extern void setup();