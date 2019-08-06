
#include "vex.h"
#include "vex_units.h"
#include <Cortex_layout.h>

void Drive()
{
  
  Right1.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
    
  Left1.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis3.value(), vex::velocityUnits::pct);
  
  //intake
  if(Controller.ButtonR1.pressing())
  {
    R_intake.spin(vex::directionType::fwd, 70, vex::percentUnits::pct);
    L_intake.spin(vex::directionType::rev, 70, vex::percentUnits::pct);
  }
  

  else if(Controller.ButtonR2.pressing())
  {
    R_intake.spin(vex::directionType::rev, 70, vex::percentUnits::pct);
    L_intake.spin(vex::directionType::fwd, 70, vex::percentUnits::pct);
  } 

  else 
  {
    R_intake.stop();
    L_intake.stop();
  }
 


}

void Arms()
{
  //Arm

  if(Controller.ButtonL1.pressing())
  {
    R_arms.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
    L_arms.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
  }
   else if(Controller.ButtonL2.pressing())
  {
    R_arms.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
    L_arms.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
  }
  else 
  {
  R_arms.stop(vex::brakeType::hold);
  L_arms.stop(vex::brakeType::hold);
  }

}

void lift()
{
if(Controller.ButtonA.pressing())
{
  Lift.spin(vex::directionType::fwd, 40, vex::velocityUnits::pct);
}
else if(Controller.ButtonB.pressing())
{
  Lift.spin(vex::directionType::rev, 40, vex::velocityUnits::pct);
}
else {
Lift.stop();
}
}


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
/*
while(abs(Controller.Axis2.value()) && abs(Controller.Axis1.value()))
{

  Left1.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  

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
*/

void Gyro_Move(double degree)
{
   while(true)
  {


//if(Controller.ButtonA.pressing())
//{

  //           ADD a Tolerance             
  if(Gyro.value(vex::rotationUnits::deg) <= degree ) //Goes right
  {
  Left1.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::fwd, 30 , vex::velocityUnits::pct);
 

  Right1.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  Right2.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  Right3.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  Right4.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);

  }
  
   else if(Gyro.value(vex::rotationUnits::deg) >= degree )
     {
  Left1.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);
  Left2.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);
  Left3.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);
  Left4.spin(vex::directionType::rev, 30 , vex::velocityUnits::pct);


  Right1.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right2.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right3.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  Right4.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);

     }
     else 
      {
  Left1.stop(vex::brakeType::brake);
  Left2.stop(vex::brakeType::brake);
  Left3.stop(vex::brakeType::brake);
  Left4.stop(vex::brakeType::brake);
  

  Right1.stop(vex::brakeType::brake);
  Right2.stop(vex::brakeType::brake);
  Right3.stop(vex::brakeType::brake);
  Right4.stop(vex::brakeType::brake);
 
  Gyro.startCalibration();
 
     }
}
//}

}



