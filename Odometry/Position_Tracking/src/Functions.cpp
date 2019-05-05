#include "main.h"
#include "Functions.hpp"
#include "Variables.cpp"
#include "Sensors.hpp"

double inToCm(int in)
{
  return in * 2.54;
}

double cmToTick(int cm)
{
  return cm * (360 / ((wheelSize * M_PI) * 2.54));
}

double radTodeg(double theta)
{
  return theta * (180 / M_PI);
}

double getAngle(double dL, double dR)
{
  return radTodeg((dL - dR) / (sL + sR));
}

double deltaD(double target)
{
  double currentL, currentR;
  while(1)
  {
    currentL = leftEnc.get_position();
    currentR = rightEnc.get_position();
    deltaL = target - currentL;
    deltaR = target - currentR;

    powerL =
    return (deltaL - deltaR) / 2;
  }
}

void orient(double deg)
{

}

double getXPos()
{
  return 2 * sin(getAngle(deltaL, deltaR)) * ((deltaL + deltaR) /
  (getAngle(deltaL, deltaR) - thetaPrevious) + Ss);
}

double getYPos()
{
  return 2 * sin(getAngle(deltaL, deltaR)) * (deltaR /
  (getAngle(deltaL, deltaR) - thetaPrevious) + Sr);
}

void drive(double x, double y)
{

}
