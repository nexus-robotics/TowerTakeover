#include "main.h"

double degToRad(double deg);/*converts orientation from degrees to radians*/

double getAngle(double dL, double dR);/*determines the angle  of the robot|formula:(deltaL - deltaR)/(Sl+Sr)*/

void orient(double deg);/*orient function*/

double deltaD(double target);/*Calculate the change in distance for the left and rigth encoders*/

double getXPos();//returns the current x position of the bot

double getYPos();//returns the current y position of the bot

void drive(double x, double y);/*drive to point function*/
