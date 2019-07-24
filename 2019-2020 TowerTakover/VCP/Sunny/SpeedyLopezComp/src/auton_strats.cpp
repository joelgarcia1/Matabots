#include "vex.h"
#include <chassis_methods.h>

using namespace vex;

void testMove()
{
  MoveForward(22, 50);
}

void testRightTurn()
{
  TurnRight(90, 60);
}

void testLeftTurn()
{
  TurnLeft(90, 60);
}