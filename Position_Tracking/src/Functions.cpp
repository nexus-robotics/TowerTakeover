#include "main.h"
#include "Functions.hpp"
#include "Variables.cpp"
#include "Sensors.hpp"

void reset()
{
      thetaPrevious = 0;
      deltaL = 0;
      deltaR = 0;
}

double degToRad(double deg)
{
  return deg * (M_PI / 180);
}

double getOrientation(double dL, double dR)
{
  return (dL - dR) / (sL + sR);
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

double getDistance(double encValue, double prevEncValue)
{
  return (encValue - prevEncValue) / tickPerInch;
}

void drive(void*, double x, double y)
{

}

void posTracking(void*)
{
  int lEnc = 0, rEnc = 0, bEnc = 0;
  while(true)
  {

    deltaL = getDistance(leftEnc.getValue(), lEnc);
    deltaR = getDistance(rightEnc.getValue(), rEnc);
    deltaS = getDistance(backEnc.getValue(), bEnc);

    lenc =  leftEnc.get_value();
    rEnc = rightEnc.get_value();

    thetaGlobal = thetaPrevious + getOrientation(deltaL, deltaR);

    pros::delay(10);
  }/*end of while*/
}/*end of posTracking*/
