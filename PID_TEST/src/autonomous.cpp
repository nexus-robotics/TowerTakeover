#include "main.h"
#include "Variables.cpp"

int cmToTick(int cm)
{
  return cm * (int(360 / ((wheelSize * 3.14) * 2.54)));
}
void driveTo(int target)//takes a value in cm
{
  target = cmToTick(target);

  adi_analog_calibrate(leftEnc);// calibrates the left encoder
  adi_analog_calibrate(rightEnc);// calibrates the right encoder

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


void rotate(int degrees, bool right)
{
  adi_analog_calibrate(leftEnc);// calibrates the left encoder
  adi_analog_calibrate(rightEnc);// calibrates the right encoder

  const tickPerDeg = 34;
  int tickGoal = (tickPerDeg * degrees) / 10
  if (right)
  {
    lPower = 127;
    rPower = -127;
    while(adi_analog_read(leftEnc) < tickGoal || adi_analog_read(rightEnc) > (-1 * tickGoal))
    {
      if (adi_analog_read(leftEnc) > tickGoal) {lPower = 0;}
      if(adi_analog_read(rightEnc) < -1 * tickGoal) {rPower = 0;}

    }//end of while
  }//end of if
  else
  {
    lPower = -127;
    rPower = 127;
    while(adi_analog_read(leftEnc) > (-1 * tickGoal) || adi_analog_read(rightEnc) < tickGoal)
    {
      if (adi_analog_read(leftEnc) < (-1 * tickGoal)) {lPower = 0;}
      if(adi_analog_read(rightEnc) > tickGoal) {rPower = 0;}
    }//end of while
  }//end of else
}//end of rotate function


void autonomous()
{
  for(int i = 0; i < 4; i++)
  {
    driveTo(5000);
    rotate(90, true);
  }//end of for
}//end of auton
