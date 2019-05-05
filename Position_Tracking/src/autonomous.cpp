#include "main.h"
#include "Variables.cpp"
#inlcude "Functions.hpp"
#include "Motors.hpp"
#include "Sensors.hpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
  task positionTracking(posTracking);
  
}//end of auton

void posTracking(void* param)
{
  int lEnc = 0, rEnc = 0, bEnc = 0;

  deltaL = (( leftEnc.get_value() - lEnc) / 360) * (M_PI * wheelSize);
  deltaR = ((rightEnc.get_value() - rEnc) / 360) * (M_PI * wheelSize);
  deltaS = (( backEnc.get_value() - bEnc) / 360) + (M_PI * wheelSize);

  lenc =  leftEnc.get_value();
  rEnc = rightEnc.get_value();

}//end of posTracking
