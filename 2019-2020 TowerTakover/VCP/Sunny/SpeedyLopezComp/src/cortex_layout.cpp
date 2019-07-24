#include "vex.h"

using namespace vex;

// Brain
brain Brain;

// Right Drive
motor R1 = motor(PORT1, false );
motor R2 = motor(PORT2, true);
motor R3 = motor(PORT3, false );
motor R4 = motor(PORT4, true);
//motor R5 = motor(PORT5, false );

// Left Drive
motor L1 = motor(PORT13, true);
motor L2 = motor(PORT14, false );
motor L3 = motor(PORT15, true);
motor L4 = motor(PORT17, false );
//motor L5 = motor(PORT15, true);

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

// Function will run before Autonomous and Before UserControl
void setup()
{
  Brake();
  reset_motors();
  rightArm.setBrake(brakeType::brake);
  leftArm.setBrake(brakeType::brake);
}

// Add Brake to Drive
void Brake()
{
  R1.setBrake(brakeType::brake);
  R2.setBrake(brakeType::brake);
  R3.setBrake(brakeType::brake);
  R4.setBrake(brakeType::brake);
  
  L1.setBrake(brakeType::brake);
  L2.setBrake(brakeType::brake);
  L3.setBrake(brakeType::brake);
  L4.setBrake(brakeType::brake);
}

// Resets All Motor Values to 0
void reset_motors()
{
  R1.resetRotation();
  R2.resetRotation();
  R3.resetRotation();
  R4.resetRotation();
  
  L1.resetRotation();
  L2.resetRotation();
  L3.resetRotation();
  L4.resetRotation();

  Lift.resetRotation();

  rightIntake.resetRotation();
  leftIntake.resetRotation();

  rightArm.resetRotation();
  leftArm.resetRotation();
}