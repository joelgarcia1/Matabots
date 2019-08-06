#include "vex.h"


// INTAKE METHODS
void IntakeOn(int power)
{
  rightIntake.spin(directionType::fwd, power, velocityUnits::rpm);
  leftIntake.spin(directionType::fwd, power, velocityUnits::rpm);
}

void OuttakeOn(int power)
{
  rightIntake.spin(directionType::fwd, power, velocityUnits::rpm);
  leftIntake.spin(directionType::fwd, power, velocityUnits::rpm);
}

void IntakeOff()
{
  rightIntake.stop();
  leftIntake.stop();
}


// ARM METHODS


// STACK METHODS