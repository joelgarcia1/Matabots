/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       SangatShah                                                */
/*    Created:      Fri Jun 14 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// define your global instances of motors and other devices here

int main() 
{
  /*float x = Sonar.distance(distanceUnits::cm);
  while(true)
  {
    Brain.Screen.print("Distance: %f", x);
    task::sleep(20);
    Brain.Screen.clearLine();
  }*/

  while(1)
  {
    driver_control();
    /*
    // Right Drive
    Speedy.Rdrive = master.Axis2.value();

    // Left Drive
    Speedy.Ldrive = master.Axis4.value();

    // Driver Control
    driver_control(Speedy.Rdrive, Speedy.Ldrive);
    */
  }
}