#include "main.h"

extern const double        Sl = 7.25;/*left-right distance from tracking center of the robot to the left tracking wheel*/
extern const double        Sr = 7.25;/*left-right distance from tracking center of the robot to the right tracking wheel*/
extern const double        Ss = 7.75;/*forward-back distance from tracking centre to back tracking wheel*/
extern const double wheelSize = 2.75;

extern double prevGlobalPos;/*previous global position vector of the robot*/
extern double   thetaGlobal;/*previous global orientation of the robot*/
extern double thetaPrevious;/*globla orientation at last reset*/

extern double deltaL = 0;//distance moved on left wheel
extern double deltaR = 0;//distance moved on right wheel

extern int powerL = 0;
extern int powerR = 0;
