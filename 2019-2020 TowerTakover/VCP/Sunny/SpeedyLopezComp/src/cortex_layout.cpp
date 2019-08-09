#include "vex.h"
#include <PID.h>
#include <cortex_layout.h>

using namespace vex;

// Brain
brain Brain;

// Right Drive
motor Right1 = motor(PORT1, false );
motor Right2 = motor(PORT2, true);
motor Right3 = motor(PORT3, false );
motor Right4 = motor(PORT4, true);
//motor R5 = motor(PORT5, false );

// Left Drive
motor Left1 = motor(PORT13, true);
motor Left2 = motor(PORT14, false );
motor Left3 = motor(PORT15, true);
motor Left4 = motor(PORT17, false );
//motor L5 = motor(PORT15, true);

// Lift Motor
motor Lift = motor(PORT9, true);

// Intakes
motor rightIntake = motor(PORT20, false);
motor leftIntake = motor(PORT18, true);

// Arms
motor rightArm = motor(PORT6, false);
motor leftArm = motor(PORT7, true);

// Controller
controller master = controller(controller());

// Function will run before Autonomous and Before UserControl
void setup()
{
  Brake();
  reset_Enc();
  rightArm.setBrake(brakeType::brake);
  leftArm.setBrake(brakeType::brake);
}

// Add Brake to Drive
void Brake()
{
  Right1.setBrake(brakeType::brake);
  Right2.setBrake(brakeType::brake);
  Right3.setBrake(brakeType::brake);
  Right4.setBrake(brakeType::brake);
  
  Left1.setBrake(brakeType::brake);
  Left2.setBrake(brakeType::brake);
  Left3.setBrake(brakeType::brake);
  Left4.setBrake(brakeType::brake);
}

// Remove Brake from Drive
void UnBrake()
{
  Right1.setBrake(brakeType::coast);
  Right2.setBrake(brakeType::coast);
  Right3.setBrake(brakeType::coast);
  Right4.setBrake(brakeType::coast);
  
  Left1.setBrake(brakeType::coast);
  Left2.setBrake(brakeType::coast);
  Left3.setBrake(brakeType::coast);
  Left4.setBrake(brakeType::coast);
}

// Resets All Motor Values to 0
void reset_Enc()
{
  Right1.resetRotation();
  Right2.resetRotation();
  Right3.resetRotation();
  Right4.resetRotation();
  
  Left1.resetRotation();
  Left2.resetRotation();
  Left3.resetRotation();
  Left4.resetRotation();

  Lift.resetRotation();

  rightIntake.resetRotation();
  leftIntake.resetRotation();

  rightArm.resetRotation();
  leftArm.resetRotation();
}

