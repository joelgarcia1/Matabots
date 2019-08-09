#pragma once
#include "vex.h"
#include <PID.h>

using namespace vex;

extern brain Brain;

// Right Drive
extern motor Right1;
extern motor Right2;
extern motor Right3;
extern motor Right4;
//extern motor R5;

// Left Drive
extern motor Left1;
extern motor Left2;
extern motor Left3;
extern motor Left4;
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

// Brake Chassis
extern void Brake();

// Unbrake Chassis
extern void UnBrake();

// Resets Motors to 0
extern void reset_Enc();