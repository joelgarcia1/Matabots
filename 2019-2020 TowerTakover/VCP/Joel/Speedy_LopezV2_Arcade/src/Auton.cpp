
#include "vex.h"
#include "vex_triport.h"
#include "vex_units.h"
#include <Cortex_layout.h>
#include <PID.h>

using namespace vex;


const double diameter = 12; // Diameter (in inches)
const double pi = 22/7; // 3.14
const double Deg = .687137; //do the calc for weight later
const double circum = diameter * pi; // Circumference in inches

double DegPerInch(double Inch)
{


    double result = ((360 * Inch)/(3.12*pi)); //360 = 1.75  radius = 2.625
    return result;


}


void RightMotor(double degree)
{
           // Right1.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);  
            Right2.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);
            Right3.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);
            Right4.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);          
}

void LeftMotor(double degree)
{
            //Left1.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);  
            Left2.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);
            Left3.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);
            Left4.startRotateFor(degree,vex::rotationUnits::deg,70,vex::velocityUnits::pct);
     
}

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


void Foward(double inches)  //inches
{
    double distance = DegPerInch(inches);
    RightMotor(distance); //distance
    LeftMotor(distance);
}

