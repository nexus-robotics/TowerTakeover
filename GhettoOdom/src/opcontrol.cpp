#include "main.h"
#include "motors.hpp"
#include "functions.hpp"
#include "okapi/api.hpp"

/**
* Runs the operator control code. This function will be started in its own task
* with the default priority and stack size whenever the robot is enabled via
* the Field Management System or the VEX Competition Switch in the operator
* control mode.
*
* If no competition control is connected, this function will run immediately
* following initialize().
*
* If the robot is disabled or communications is lost, the
* operator control task will be stopped. Re-enabling the robot will restart the
* task, not resume it from where it left off.
*/


void opcontrol() {
  pros::Task driveTask(drive, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
  pros::Task coordinates(printXY, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
  LeftEnc.reset();
  RightEnc.reset();

  while(true){

    pros::delay(20);
  }
}
