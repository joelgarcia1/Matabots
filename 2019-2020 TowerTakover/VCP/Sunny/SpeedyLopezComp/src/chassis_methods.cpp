#include "vex.h"

using namespace vex;

//*** RMove is non-blocking ; LMove is blocking ***//

// Moves the Motors on the Right Side of the Chassis for desired distance at desired power
  // NON-BLOCKING FUNCTION
void RMove(double degrees, double power)  // value of power should range from 20 to 100
{
  R1.startRotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  R2.startRotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  R3.startRotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  R4.startRotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  //R5.rotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
}

// Moves the Motors on the Left Side of the Chassis for desired distance at desired power
  // BLOCKING FUNCTION
void LMove(double degrees, double power)
{
  L1.startRotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  L2.startRotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  L3.startRotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  L4.rotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
  //L5.rotateFor(directionType::fwd, degrees, rotationUnits::deg, power, velocityUnits::pct);
}

// Moves Chassis for desired distance at desired power
  // NOTE: For moving backwards, enter negative inches & negative pow
void MoveForward(double inch, double pow)
{
  double degrees = InchToDeg(inch);
  while((L1.rotation(rotationUnits::deg) < degrees) && (R1.rotation(rotationUnits::deg) < degrees))
  {
    RMove(degrees, 70);
    LMove(degrees, 70);
  }
}

// Turns Chassis to the right for desired amount of degrees at desired power
void TurnRight(double rDeg, double pow)
{

}

// Turns Chassis to the left for desired amount of degrees at desired power
void TurnLeft(double rDeg, double pow)
{
  
}