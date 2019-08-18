#include "main.h"
#include "functions.hpp"
#include "motors.hpp"

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
	liftPot.calibrate();
	int count = 0;
	bool pressed = false;
	lift.set_brake_mode(MOTOR_BRAKE_HOLD);

	pros::Task drive(Move_Drive, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
	pros::Task lift(Move_Lift, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
	pros::Task preset(Move_Preset, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");

	while (true) {
		pros::delay(20);
	}
}
