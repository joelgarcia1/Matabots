#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
// A global instance of vex::competition
vex::competition Competition;


vex:: controller Controller = vex::controller(); 
vex::motor Right1(vex::PORT1, true);
vex::motor Right2(vex::PORT2);
vex::motor Right3(vex::PORT3,true);
vex::motor Right4(vex::PORT4);
vex::motor Right5(vex::PORT5, true);

vex::motor Left1 (vex::PORT11);
vex::motor Left2 (vex::PORT12,true);
vex::motor Left3 (vex::PORT13);
vex::motor Left4 (vex::PORT14,true);
vex::motor Left5 (vex::PORT15);


vex::gyro Gyro = gyro(Brain.ThreeWirePort.C);
