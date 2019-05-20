#include "main.h"
#include "Functions.hpp"
#include "Variables.cpp"
#include "Sensors.hpp"

void reset()
{

      thetaPrevious = thetaGlobal;
      thetaGlobal = 0;
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
  double deg2 = 360 - deg;

  if (deg < deg2)
  {
    if(getOrientation(deltaL, deltaR) > deg)
    {
      while(deg < getOrientation(deltaL, deltaR))
      {
        //rotate ccw
      }//end of while
      //stop motors
    }//end of if
    else if(getOrientation(deltaL, deltaR) < deg)
    {
      while(deg > getOrientation(deltaL, deltaR))
      {
        //rotate cw
      }//end of while
      //stop motors
    }//end of else if
  }//end of if
  else if(deg > deg2)
  {
    if(getOrientation(deltaL, deltaR) > deg2)
    {
      while(deg < getOrientation(deltaL, deltaR))
      {
        //rotate cw
      }//end of while
      //stop motors
    }//end of if
    else if(getOrientation(deltaL, deltaR) < deg2)
    {
      while(deg > getOrientation(deltaL, deltaR))
      {
        //rotate ccw
      }//end of while
      //stop motors
    }//end of else if
  }//end of else if
  else
  {
      return;
  }//end of else
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

void driveTo(void*, double x, double y)
{
      
}

void drive_arc(void*, double x, double y)
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

    deltaTheta = thetaPrevious + getOrientation(deltaL, deltaR);

    if (deltaTheta == 0)
    {
      //localPosOffset vector = eqn 6 (getXPos,getYPos)
    }//end of if

    pros::delay(10);
  }/*end of while*/
}/*end of posTracking*/
