#include "main.h"
#include "Variables.cpp"

void driveTo(int target)
{
  while (power > 20)
  {
    error = target – ((adi_analog_read(leftEnc) + adi_analog_read(rightEnc)) / 2);
    integral = integral + error;
    if (error = 0 || error > target)
    {
      integral = 0;
    }//end of if
    if (error > 1500)
    {
      integral = 0;
    }//end of if
    derivative = error – prevError;
    prevError = error;
    power = (error*kP) + (integral*kI) + (derivative*kD);
    pros::delay(15);
  }//end of while
  power = 0;
}//end of driveTo function


void autonomous()
{
  adi_analog_calibrate(leftEnc);// calibrates the left encoder
  adi_analog_calibrate(rightEnc);// calibrates the right encoder

  driveTo(5000);

}
