#include "vex.h"
#include "vex_triport.h"
#include "vex_units.h"
#include <Cortex_layout.h>


double kp1 ; // = #  
double kp2;

double ki1; // = #
double ki2;


double target; //We set the disired velocity (initially)  (RPM)

double errorL;  // error (final - initial)
double errorR; 

double cum_errorL; //(Cumulative errir) Adding up the error = cum_error += error * delta_t
double cum_errorR;

double speed_L; // speed = (error*kp + error*ki)
double speed_R;

double current_tL; //current time
double current_tR;

double previous_tL; //previous time 
double previous_tR;

double delta_tL; // current time - previous time
double delta_tR;
//PI for Straight 
//if(1) == pi & if(0) == PID
//PID for turning 

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


void move_baseR(double power)
{

  Right1.spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);
  Right2.spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);
  Right3.spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);
  Right4.spin(vex::directionType::fwd, power, vex::velocityUnits::rpm);

}

void move_baseL(double power)
{

  Left1.spin(vex::directionType::rev, power, vex::velocityUnits::rpm );
  Left2.spin(vex::directionType::rev, power, vex::velocityUnits::rpm );
  Left3.spin(vex::directionType::rev, power, vex::velocityUnits::rpm );
  Left4.spin(vex::directionType::rev, power, vex::velocityUnits::rpm );
}
void PI_straight(double target_i) //target set too
{
  reset_Enc();
  Brain.resetTimer();

    while(true)
    {



  current_tL = Brain.timer(vex::timeUnits::sec);
  current_tR = Brain.timer(vex::timeUnits::sec);

  delta_tL = double(current_tL - previous_tL);
  delta_tR = double(current_tR - previous_tR);

  errorL = (target - target_i);
  errorR = (target - target_i);

  cum_errorL += errorL * delta_tL;
  cum_errorR += errorR * delta_tR;

  speed_L = (errorL * kp1 + cum_errorL*ki1);  //motor = speed motor is connected to speed
  speed_R = (errorR * kp2 + cum_errorR* ki2); 

  //set the move_base(speed);
  move_baseR(speed_R);
  move_baseL(speed_L);
  previous_tL = current_tL;
  target_i = errorL;
    }
}

