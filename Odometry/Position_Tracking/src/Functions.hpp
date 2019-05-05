#include "main.h"

double inToCm(int in);//converts inches to centimetres

double cmToTick(int cm);//converts centimetres to encoder ticks

double radTodeg(double theta);/*converts orientation from radians to degrees*/

double getAngle(double dL, double dR);/*determines the angle  of the robot|formula:(deltaL - deltaR)/(Sl+Sr)*/

void orient(double deg);/*orient function*/

double deltaD(double target);/*Calculate the change in distance for the left and rigth encoders*/

double getXPos();

double getYPos();

void drive(double x, double y);/*drive to point function*/
