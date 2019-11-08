#include "main.h"
#include "declare.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor Right1(9,true);
pros::Motor Right2(10,true);
pros::Motor Left1(11,false);
pros::Motor Left2(12,false);
pros::Motor Flywheel(16,true);
pros::Motor Arm(4,false);
pros::Motor Intake(5,false);

void setup_bot()
{
  Right1.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  Right2.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  Left1.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  Left2.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  Arm.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  Flywheel.set_brake_mode(E_MOTOR_BRAKE_COAST);
}
