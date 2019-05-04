#include "main.h"

int inToCm(int in);//converts inches to centimetres

int cmToTick(int cm);//converts centimetres to encoder ticks

int radTodeg(double theta);/*converts orientation from radians to degrees*/

double getAngle(double dL, double dR);/*determines the angle  of the robot|formula:(deltaL - deltaR)/(Sl+Sr)*/

void orient(double deg);/*orient function*/

double deltaD(double target);/*Calculate the change in distance for the left and rigth encoders*/

double getXPos();

douible getYPos();

void drive(double x, double y);/*drive to point function*/
