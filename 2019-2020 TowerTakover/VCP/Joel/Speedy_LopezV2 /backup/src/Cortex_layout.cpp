

#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
// A global instance of vex::competition
vex::competition Competition;


vex:: controller Controller = vex::controller(); 
vex::motor Right1(vex::PORT1,true);
vex::motor Right2(vex::PORT2);
vex::motor Right3(vex::PORT3,true);
vex::motor Right4(vex::PORT5);


vex::motor Left1 (vex::PORT20 );
vex::motor Left2 (vex::PORT14,true);
vex::motor Left3 (vex::PORT15);
vex::motor Left4 (vex::PORT17,true);

vex::motor R_arms(vex::PORT6);
vex::motor L_arms(vex::PORT16, true);

vex::motor Lift(vex::PORT9,true);

vex::motor R_intake(vex::PORT18);
vex::motor L_intake(vex::PORT19);




vex::gyro Gyro = gyro(Brain.ThreeWirePort.C);

