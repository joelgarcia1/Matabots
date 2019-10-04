#include "vex.h"
#include "vex_triport.h"
#include "vex_units.h"
#include <Cortex_layout.h>


// INTAKE METHODS
void Intake(int rotate)
{
  R_intake.startRotateFor(rotate,vex::rotationUnits::deg,80,vex::velocityUnits::pct);
  L_intake.startRotateFor(rotate,vex::rotationUnits::deg,80,vex::velocityUnits::pct);
}
void Outtake(int rotate)
{
  R_intake.startRotateFor(-rotate,vex::rotationUnits::deg,80,vex::velocityUnits::pct);
  L_intake.startRotateFor(-rotate,vex::rotationUnits::deg,80,vex::velocityUnits::pct);
}

void IntakeOff()
{
  R_intake.stop();
  L_intake.stop();
}


// ARM METHODS
void Lift_move(int rotate)
{
  Lift.startRotateFor(rotate,vex::rotationUnits::deg,80,vex::velocityUnits::pct);
}

// STACK METHODS
