#include "vex.h"
#include "vex_triport.h"
#include "vex_units.h"
#include <Cortex_layout.h>


// INTAKE METHODS
void Intake(int rotate, double power)
{
  R_intake.startRotateFor(rotate,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
  L_intake.startRotateFor(rotate,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
}
void Outtake(int rotate, double power)
{
  R_intake.startRotateFor(rotate,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
  L_intake.startRotateFor(rotate,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
}

void IntakeOff()
{
  R_intake.stop();
  L_intake.stop();
}


// ARM METHODS
void Lift_move(double move, double power)
{
  Lift.startRotateFor(move,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
}

// STACK METHODS
