#include "vex.h"
//#include "chassis_methods.h"

using namespace vex;


void RMove(double power)
{
  R1.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  R2.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  R3.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  R4.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  //R5.spin(directionType::fwd, power * (100/127), percentUnits::pct);
}

void LMove(double power)
{
  L1.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  L2.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  L3.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  L4.spin(directionType::fwd, power * (100/127), percentUnits::pct);
  //L5.spin(directionType::fwd, power * (100/127), percentUnits::pct);
}

