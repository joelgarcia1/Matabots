
#include "vex.h"
#include "vex_units.h"
#include <Cortex_layout.h>
#include <PID.h>

using namespace vex;

void Auton_Strat()
{
  PI_straight(12);
}


// Method for going straight 
//WIP
void AStraight(double distanceR, double speedRpm)
{
  while(distanceR<Right1.rotation(rotationUnits::rev)){
    Right1.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);
    Right2.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);
    Right3.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);
    Right4.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);

    Left1.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);
    Left2.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);
    Left3.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);
    Left4.spin(vex::directionType::fwd,speedRpm,vex::velocityUnits::rpm);
  }
}