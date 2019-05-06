#include "main.h"

extern const double          Sl = 7.25;/*left-right distance from tracking center of the robot to the left tracking wheel*/
extern const double          Sr = 7.25;/*left-right distance from tracking center of the robot to the right tracking wheel*/
extern const double          Ss = 7.75;/*forward-back distance from tracking centre to back tracking wheel*/
extern const double   wheelSize = 2.75;/*diameter of tracking wheel*/
extern const double          kP = 0;/*constant for porortional tuning*/
extern const double          kI = 0;/*constant for integral tuning*/
extern const double          kD = 0;/*constant for derivation tuning*/

extern const double tickPerInch = 360 / (wheelSize * M_PI);

extern double prevGlobalPos[2] = 0;/*previous global position vector of the robot*/
extern double localPosOffset = 0;
extern double   thetaGlobal = 0;/*previous global orientation of the robot*/
extern double deltaTheta = 0;
extern double thetaPrevious = 0;/*global orientation at last reset*/

extern double deltaL = 0;/*distance moved on left wheel*/
extern double deltaR = 0;/*distance moved on right wheel*/

extern int powerL = 0;/*power for left base motors*/
extern int powerR = 0;/*power for right base motors*/
