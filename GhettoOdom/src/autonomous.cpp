#include "main.h"
#include "okapi/api.hpp"
using namespace okapi;

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
// auto myChassis = ChassisControllerFactory::create(
//   {20, 11}, // Left motors
//   {-10, -1},  // Right motors
//   AbstractMotor::gearset::green, // Torque gearset
//   {3.35_in, 14.5_in} // 4 inch wheels, 12.5 inch wheelbase width
// );
//
// auto profileController = AsyncControllerFactory::motionProfile(
//   1.0,  // Maximum linear velocity of the Chassis in m/s
//   2.0,  // Maximum linear acceleration of the Chassis in m/s/s
//   10.0, // Maximum linear jerk of the Chassis in m/s/s/s
//   myChassis // Chassis Controller
// );

void autonomous() {

  // profileController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
  // profileController.setTarget("A");
  // profileController.waitUntilSettled();
  // myChassis.turnAngle(90_deg);



}
