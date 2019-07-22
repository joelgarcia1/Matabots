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

// Intake Motors
extern motor rightIntake;
extern motor leftIntake;

// Arm Motors
extern motor rightArm;
extern motor leftArm;

extern controller master;

// Setup Function
extern void setup();

// Resets Motors to 0
extern void reset_motors();