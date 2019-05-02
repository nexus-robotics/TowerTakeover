#include "main.h"
#include "Variables.cpp"

void myPID(int target, int sensorValue)
{
  while (1)
  {
    error = target – sensorValue;//calculates the remaining units between target and current values
    integral = integral + error;
    if (error = 0 || error > target)
    {
      integral = 0;
    }
    if (error > 1500)
    {
      integral = 0;
    }
    derivative = error – prevError;
    prevError = error;
    power = (error*kP) + (integral*kI) + (derivative*kD);
    pros::delay(15);
  }
}


void autonomous()
{

}
