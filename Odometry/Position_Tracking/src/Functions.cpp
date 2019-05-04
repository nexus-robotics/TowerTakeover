#include "main.h"
#include "Functions.hpp"
#include "Variables.cpp"

double inToCm(int in)
{
  return in * 2.54;
}

double cmToTick(int cm)
{
  return cm * (int(360 / ((wheelSize * 3.14) * 2.54)));
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
    currentL = LF.get_position();
    currentR = RF.get_position();
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
  (getAngle(deltaL, deltaR) - thetaPrevious) + Ss;
}

double getYPos()
{

}

void drive(double x, double y)
{

}
