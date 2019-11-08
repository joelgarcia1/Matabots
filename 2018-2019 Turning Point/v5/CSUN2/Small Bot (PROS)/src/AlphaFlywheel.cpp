#include "main.h"
#include "AlphaFlywheel.hpp"

void MotorPx(int power)
{
  if (power > 0)
  {
  Right1.move(power + 2);
  Right2.move(power + 2);
  Left1.move(power);
  Left2.move(power);
  delay(20);
  }
  else if(power < 0)
  {
  Right1.move(power - 2);
  Right2.move(power - 2);
  Left1.move(power);
  Left2.move(power);
  delay(20);
  }
  else
  {
    Right1.move(0);
    Right2.move(0);
    Left1.move(0);
    Left2.move(0);
    delay(20);
  }
}
void StartFly(int rpm)
{
  Flywheel.move_velocity(rpm);
  delay(20);
}
void StartIntake()
{
  Intake.move_velocity(200);
  delay(20);
}
void TurnRight(int deg)
{
  Right1.move_relative(-deg,-50);  // (position, velocity)
  Right2.move_relative(-deg,-50); // change velocity
  Left1.move_relative(deg,50); // 270 to like 80
  Left2.move_relative(deg,50);
  delay(1400);
}
void TurnLeft(int deg)
{
  Right1.move_relative(deg,50);
  Right2.move_relative(deg,50);
  Left1.move_relative(-deg,-50);
  Left2.move_relative(-deg,-50);
  delay(1400);
}
void Move(double squares)
{
  //initialize units
  double units = squares * 420; //520, 540
  double timeDel = fabs(squares * 1.3); //Originial is 1.6125
  //First Part
  if (squares < 0)
  {
    MotorPx(-37);
    delay(0.5 * 1000);
  }
  else
  {
    MotorPx(37);
    delay(0.5 * 1000);
  }
  //Second Part
  Right1.move_relative(units,75.0);
  Right2.move_relative(units,75.0);
  Left1.move_relative(units,75.0);
  Left2.move_relative(units,75.0);
  delay((timeDel / 2) * 1000.0);
//Third Part
  if (squares < 0)
  {
    MotorPx(-37);
    delay((timeDel/2) * 1000);
    MotorPx(0);
  }
  else
  {
    MotorPx(39);
    delay((timeDel/2) * 1000);
    MotorPx(0);
  }
}
