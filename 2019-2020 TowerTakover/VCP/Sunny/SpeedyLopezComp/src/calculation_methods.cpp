#include "vex.h"

using namespace vex;

const double wheel_diameter = 4; // Diameter of Wheel (in inches)
const double pi = 22/7; // 3.14159...
const double wheelCircumference = wheel_diameter * pi;  // Circumference of Wheel (in inches)


// Converts Inches to Degrees
double InchToDeg(double inch)
{
  double deg = inch * (360/wheelCircumference);
  return deg;
}