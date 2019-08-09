#include "vex.h"
#include "vex_task.h"
#include <calculation_methods.h>
#include <cortex_layout.h>

using namespace vex;

const double chassis_diameter = 12; // Diameter of Chassis (in inches)
const double pi = 22/7; // 3.14159...
const double chassis_circum = chassis_diameter * pi; // Circumference of Chassis (in inches)

// Moves the Motors on the Right Side of the Chassis for desired distance at desired power
void RMove(double degrees, double power)  // value of power should range from 20 to 100
{
  Right1.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  Right2.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  Right3.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  Right4.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  //R5.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
}

// Moves the Motors on the Left Side of the Chassis for desired distance at desired power
void LMove(double degrees, double power)
{
  Left1.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  Left2.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  Left3.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  Left4.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
  //L5.startRotateTo(degrees, rotationUnits::deg, power, velocityUnits::pct);
}

// Moves Chassis for desired distance at desired power
  // NOTE: For moving backwards, enter negative inches & negative pow
void MoveForward(double inch, double pow)
{
  reset_Enc();
  double degrees = InchToDeg(inch); // Convert travel distance from inches to degrees
  RMove(degrees, pow);
  LMove(degrees, pow);  // Move Forward till degrees
  while((Left1.rotation(rotationUnits::deg) < degrees) && (Right1.rotation(rotationUnits::deg) < degrees))
  {
    task::sleep(2);
  }
  RMove(0, 0);
  LMove(0,0);
}

// Turns Chassis to the right for desired amount of degrees at desired power
void TurnRight(double rDeg, double pow)
{
  reset_Enc();
  /* Convert degrees robot needs to turn to distance wheels need to travel in degrees */
  double targetIn = (rDeg) * (chassis_circum/360); // Target distance (in inches)
  double targetDeg = InchToDeg(targetIn); // Target distance (in degrees)
  RMove(-targetDeg, -pow);
  LMove(targetDeg, pow);  // Turn right till targetDeg
  while((Left1.rotation(rotationUnits::deg) < targetDeg) && (Right1.rotation(rotationUnits::deg) > -targetDeg))
  {
    task::sleep(2);
  }
}

// Turns Chassis to the left for desired amount of degrees at desired power
void TurnLeft(double rDeg, double pow)
{
  reset_Enc();
  /* Convert degrees robot needs to turn to distance wheels need to travel in degrees */
  double targetIn = (rDeg) * (chassis_circum/360); // Target distance (in inches)
  double targetDeg = InchToDeg(targetIn); // Target distance (in degrees)
  RMove(targetDeg, pow);
  LMove(-targetDeg, -pow);  // Turn left till targetDeg
  while((Left1.rotation(rotationUnits::deg) > -targetDeg) && (Right1.rotation(rotationUnits::deg) < targetDeg))
  {
    task::sleep(2);
  }
}