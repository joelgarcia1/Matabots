#include "vex.h"

void Drive()
{
  /*
  Right1.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
    
  Left1.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  */

/*
  //Arcade two joySticks
while(abs(Controller.Axis3.value()) && abs(Controller.Axis1.value()))
{

  Left1.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
}

//Foward Drive
if(Controller.Axis3.value())//10 = deadzone
  {
     Left1.spin(vex::directionType::fwd, Controller.Axis3.value() , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis3.value() , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis3.value() , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis3.value() , vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, Controller.Axis3.value() , vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  }
  //Left and Right
  else if (Controller.Axis1.value())
   {
  Left1.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value(), vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  }
  //Turns off motors
  else
  {
  Left1.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  }
*/

//One joystick Arcade
while(abs(Controller.Axis2.value()) && abs(Controller.Axis1.value()))
{

  Left1.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
}

//Foward Drive
if(Controller.Axis2.value())//10 = deadzone
  {
     Left1.spin(vex::directionType::fwd, Controller.Axis2.value() , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis2.value() , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis2.value() , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis2.value() , vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, Controller.Axis2.value() , vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  }
  //Left and Right
  else if (Controller.Axis1.value())
   {
  Left1.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  }
  //Turns off motors
  else
  {
  Left1.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, 0 , vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
  }

}

void Gyro_Move()
{
   while(1)
  {


//if(Controller.ButtonA.pressing())
//{

  /*           ADD a Tolerance             */
  if(Gyro.value(vex::rotationUnits::deg) <= 90 ) //Goes right
  {
  Left1.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);

  Right1.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  Right2.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  Right3.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  Right4.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  Right5.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  }
  
   else if(Gyro.value(vex::rotationUnits::deg) >= 90 )
     {
  Left1.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);
  Left5.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
     }
     else 
      {
  Left1.stop(vex::brakeType::brake);
  Left2.stop(vex::brakeType::brake);
  Left3.stop(vex::brakeType::brake);
  Left4.stop(vex::brakeType::brake);
  Left5.stop(vex::brakeType::brake);

  Right1.stop(vex::brakeType::brake);
  Right2.stop(vex::brakeType::brake);
  Right3.stop(vex::brakeType::brake);
  Right4.stop(vex::brakeType::brake);
  Right5.stop(vex::brakeType::brake);
  Gyro.startCalibration();
 
     }
}
//}

}

void Foward()
{
  Left1.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left5.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);

  Right1.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right5.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);


}