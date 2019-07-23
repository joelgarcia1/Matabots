#include "vex.h"
#include "vex_task.h"
#include <calculation_methods.h>
#include <cortex_layout.h>

using namespace vex;

const double chassis_diameter = 0; // Diameter of Chassis (in inches)
const double pi = 22/7; // 3.14159...
const double chassis_circum = chassis_diameter * pi; // Circumference of Chassis (in inches)

// Moves the Motors on the Right Side of the Chassis for desired distance at desired power
void RMove(double degrees, double power)  // value of power should range from 20 to 100
{
  R1.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  R2.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  R3.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  R4.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  //R5.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
}

// Moves the Motors on the Left Side of the Chassis for desired distance at desired power
void LMove(double degrees, double power)
{
  L1.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  L2.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  L3.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  L4.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  //L5.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
}

// Moves Chassis for desired distance at desired power
  // NOTE: For moving backwards, enter negative inches & negative pow
void MoveForward(double inch, double pow)
{
  double degrees = InchToDeg(inch); // Convert travel distance from inches to degrees
  while((L1.rotation(rotationUnits::deg) < degrees) && (R1.rotation(rotationUnits::deg) < degrees))
  {
    RMove(degrees, pow);
    LMove(degrees, pow);  // Move Forward till degrees
    task::sleep(2);
  }
}

// Turns Chassis to the right for desired amount of degrees at desired power
void TurnRight(double rDeg, double pow)
{
  /* Convert degrees robot needs to turn to distance wheels need to travel in degrees */
  double targetIn = (rDeg) * (chassis_circum/360); // Target distance (in inches)
  double targetDeg = InchToDeg(targetIn); // Target distance (in degrees)
  while((L1.rotation(rotationUnits::deg) < targetDeg) && (R1.rotation(rotationUnits::deg) > -targetDeg))
  {
    RMove(-targetDeg, -pow);
    LMove(targetDeg, pow);  // Turn right till targetDeg
    task::sleep(2);
  }
}

// Turns Chassis to the left for desired amount of degrees at desired power
void TurnLeft(double rDeg, double pow)
{
  /* Convert degrees robot needs to turn to distance wheels need to travel in degrees */
  double targetIn = (rDeg) * (chassis_circum/360); // Target distance (in inches)
  double targetDeg = InchToDeg(targetIn); // Target distance (in degrees)
  while((L1.rotation(rotationUnits::deg) > -targetDeg) && (R1.rotation(rotationUnits::deg) < targetDeg))
  {
    RMove(targetDeg, pow);
    LMove(-targetDeg, -pow);  // Turn left till targetDeg
    task::sleep(2);
  }
}