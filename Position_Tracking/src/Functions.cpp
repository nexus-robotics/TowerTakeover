#include "main.h"
#include "Functions.hpp"
#include "Variables.cpp"
#include "Sensors.hpp"

double degToRad(double deg)
{
  return deg * (M_PI / 180);
}

double getAngle(double dL, double dR)
{
  return degToRad((dL - dR) / (sL + sR));
}

double deltaD(double target)
{
  double currentL, currentR;
  while(true)
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
  degToRad(deg);
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
