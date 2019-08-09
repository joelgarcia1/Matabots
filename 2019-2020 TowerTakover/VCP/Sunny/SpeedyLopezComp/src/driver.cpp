#include "vex.h"

using namespace vex;

int Rval = 0, Lval = 0;
const int DEADZONE = 20;

// Driver Control
void driver_control()
{
  Lift.setVelocity(100, velocityUnits::rpm);
  
  // Right Drive Control
  if(abs(master.Axis2.value()) > DEADZONE)
    {
      Rval = master.Axis2.value();// * .787; // (100/127)
      Right1.spin(directionType::fwd, Rval, percentUnits::pct);
      Right2.spin(directionType::fwd, Rval, percentUnits::pct);
      Right3.spin(directionType::fwd, Rval, percentUnits::pct);
      Right4.spin(directionType::fwd, Rval, percentUnits::pct);
      //Right5.spin(directionType::fwd, Rval, percentUnits::pct);
    }
    else
    {
      Right1.stop();
      Right2.stop();
      Right3.stop();
      Right4.stop();
      //Right5.stop();
    }

    // Left Drive Control
    if(abs(master.Axis3.value()) > DEADZONE)
    {
      Lval = master.Axis3.value();// * .787; // (100/127)
      Left1.spin(directionType::fwd, Lval, percentUnits::pct);
      Left2.spin(directionType::fwd, Lval, percentUnits::pct);
      Left3.spin(directionType::fwd, Lval, percentUnits::pct);
      Left4.spin(directionType::fwd, Lval, percentUnits::pct);
      //Left5.spin(directionType::fwd, Lval, percentUnits::pct);
    }
    else
    {
      Left1.stop();
      Left2.stop();
      Left3.stop();
      Left4.stop();
      //Left5.stop();
    }

    // Intake Control
    if(master.ButtonR2.pressing())
    {
      rightIntake.spin(directionType::fwd, 200, velocityUnits::rpm);
      leftIntake.spin(directionType::fwd, 200, velocityUnits::rpm);
    }
    else if(master.ButtonR1.pressing())
    {
      rightIntake.spin(directionType::rev, 75, velocityUnits::rpm);
      leftIntake.spin(directionType::rev, 75, velocityUnits::rpm);
    }
    else
    {
      rightIntake.stop();
      leftIntake.stop();
    }
    
    // Arm Control
    if(master.ButtonL1.pressing())
    {
      rightArm.spin(directionType::fwd, 200, velocityUnits::rpm);
      leftArm.spin(directionType::fwd, 200, velocityUnits::rpm);
    }
    else if(master.ButtonL2.pressing())
    {
      rightArm.spin(directionType::rev, 200, velocityUnits::rpm);
      leftArm.spin(directionType::rev, 200, velocityUnits::rpm);
    }
    else
    {
      rightArm.stop();
      leftArm.stop();
    }

    // Lift Control
    if(master.ButtonLeft.pressing())
    {
      Lift.spin(directionType::fwd);
    }
    else if(master.ButtonDown.pressing())
    {
      Lift.spin(directionType::rev);
    }
    else
    {
      Lift.stop();
    }

    vex::task::sleep(20);
}