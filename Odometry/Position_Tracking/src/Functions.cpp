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

double deltaD(double target){
  double deltaL,deltaR, currentL, currentR;
  while(true){
    currentL = LF.get_position();
    currentR = RF.get_position();
    deltaL = target - currentL;
    delta
  }

}

void orient(double deg)
{

}


void drive(double x, double y)
{

}
