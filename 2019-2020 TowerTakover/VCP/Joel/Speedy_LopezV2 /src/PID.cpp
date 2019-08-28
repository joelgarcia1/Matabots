#include "vex.h"
#include "vex_triport.h"
#include "vex_units.h"
#include <Cortex_layout.h>



double kp1 = .01 ; // = #  
double kp2 = .01;

double ki1 =.001; // = #
double ki2 =.001;


double target = 60; //We set the disired velocity (initially)  (RPM)

double errorL;  // error (final - initial)
double errorR; 

double cum_errorL; //(Cumulative errir) Adding up the error = cum_error += error * delta_t
double cum_errorR;

double speed_L; // speed = (error*kp + error*ki)
double speed_R;

double current_t; //current time


double previous_tL; //previous time 
double previous_tR;

double delta_t; // current time - previous time
double current_enc = 0;
//PI for Straight 
//if(1) == pi & if(0) == PID
//PID for turning 

//Ticks/ rev originally from the motor == 900 
//Ticks/in  == 71.61972439



 //Set one motor equal to the other three motors
void reset_Enc()
{
Right1.resetRotation();
Right2.resetRotation();
Right3.resetRotation(); 
Right4.resetRotation();

Left1.resetRotation();
Left2.resetRotation();
Left3.resetRotation();
Left4.resetRotation();
}


void move_baseR(double speed)
{

  Right1.spin(vex::directionType::fwd, speed, vex::velocityUnits::rpm);
  Right2.spin(vex::directionType::fwd, speed, vex::velocityUnits::rpm);
  Right3.spin(vex::directionType::fwd, speed, vex::velocityUnits::rpm);
  Right4.spin(vex::directionType::fwd, speed, vex::velocityUnits::rpm);

}

void move_baseL(double speed)
{

  Left1.spin(vex::directionType::rev, speed, vex::velocityUnits::rpm );
  Left2.spin(vex::directionType::rev, speed, vex::velocityUnits::rpm );
  Left3.spin(vex::directionType::rev, speed, vex::velocityUnits::rpm );
  Left4.spin(vex::directionType::rev, speed, vex::velocityUnits::rpm );
}

//void Current_Enc ()
//{
//Right1.rotateFor(0,vex::rotationUnits::deg);
//Right2.rotateFor(0,vex::rotationUnits::deg);
//Right3.rotateFor(0,vex::rotationUnits::deg);
//Right4.rotateFor(0,vex::rotationUnits::deg);
//}

double InchPerTicks(double inch)
{
double ticks;
ticks = inch * 71.61972439;  //900ticks/rev  / circumference
return ticks;
}

void PI_straight(double target_i) //target set too
{
  reset_Enc();
  Brain.resetTimer();

    while(true)
    {

  current_t = Brain.timer(vex::timeUnits::sec);
  

  delta_t = double(current_t - previous_tL);
  

  errorL = InchPerTicks(target) - current_enc; //current enc 
  errorR = (target - target_i);

  //cum_errorL += errorL * delta_tL;
  //cum_errorR += errorR * delta_tR;

  speed_L = (errorL * kp1 );//+ cum_errorL*ki1);  //motor = speed motor is connected to speed
  speed_R = (errorR * kp2); //+ cum_errorR* ki2); 

  //set the move_base(speed);
  move_baseR(speed_R);
  //move_baseL(speed_L);
  
  //previous_tL = current_tL;
  //target_i = errorL;
  vex::task::sleep(40);
    }
}

