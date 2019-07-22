#include "vex.h"
//#include "motor.h"

using namespace vex;

// Brain
brain Brain;

// Right Drive
motor R1 = motor(PORT1, true);
motor R2 = motor(PORT2, false);
motor R3 = motor(PORT3, true);
motor R4 = motor(PORT4, false);
//motor R5 = motor(PORT5, true);

// Left Drive
motor L1 = motor(PORT13, false);
motor L2 = motor(PORT14, true);
motor L3 = motor(PORT15, false);
motor L4 = motor(PORT17, true);
//motor L5 = motor(PORT15, false);

// Lift Motor
motor Lift = motor(PORT9, true);

// Intakes
motor rightIntake = motor(PORT18, true);
motor leftIntake = motor(PORT19, false);

// Arms
motor rightArm = motor(PORT6, false);
motor leftArm = motor(PORT7, true);

// Controller
controller master = controller(controller());

void setup()
{
  rightArm.setBrake(brakeType::brake);
  leftArm.setBrake(brakeType::brake);
}
