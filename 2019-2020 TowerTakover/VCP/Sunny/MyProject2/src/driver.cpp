#include "vex.h"
#include "vex_units.h"
#include <cortex_layout.h>
//#include "driver.h"

using namespace vex;

int Rval = 0, Lval = 0;

void driver_control()
{
  Lift.setVelocity(100, velocityUnits::rpm);
  /*
    if(master.ButtonR2.pressing())
    {
      testMotor.spin(directionType::fwd, 50, velocityUnits::rpm);
    }
    else if(master.ButtonR1.pressing())
    {
      testMotor.spin(directionType::rev, 50, velocityUnits::rpm);
    }
    else
    {
      testMotor.stop();
    }
*/
  
  // Right Drive
  if(master.Axis2.value() != 0)
    {
      Rval = master.Axis2.value() * .787; // (100/127)
      R1.spin(directionType::fwd, Rval, percentUnits::pct);
      R2.spin(directionType::fwd, Rval, percentUnits::pct);
      R3.spin(directionType::fwd, Rval, percentUnits::pct);
      R4.spin(directionType::fwd, Rval, percentUnits::pct);
      //R5.spin(directionType::fwd, Rval, percentUnits::pct);
    }
    else
    {
      R1.stop();
      R2.stop();
      R3.stop();
      R4.stop();
      //R5.stop();
    }

    // Left Drive
    if(master.Axis3.value() != 0)
    {
      Lval = master.Axis3.value()  * .787; // (100/127)
      L1.spin(directionType::fwd, Lval, percentUnits::pct);
      L2.spin(directionType::fwd, Lval, percentUnits::pct);
      L3.spin(directionType::fwd, Lval, percentUnits::pct);
      L4.spin(directionType::fwd, Lval, percentUnits::pct);
      //L5.spin(directionType::fwd, Lval, percentUnits::pct);
    }
    else
    {
      L1.stop();
      L2.stop();
      L3.stop();
      L4.stop();
      //L5.stop();
    }

    // Intakes
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
      rightArm.spin(directionType::fwd, 100, velocityUnits::rpm);
      leftArm.spin(directionType::fwd, 100, velocityUnits::rpm);
    }
    else if(master.ButtonL2.pressing())
    {
      rightArm.spin(directionType::rev, 100, velocityUnits::rpm);
      leftArm.spin(directionType::rev, 100, velocityUnits::rpm);
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