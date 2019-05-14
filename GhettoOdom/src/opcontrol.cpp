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

void goodTurn(double target){
  double  pwr, totalError, lastError, P, I, D, kP, kI, kD;
  double currentL, currentR, lastL, lastR, deltaL, deltaR, error, DTL, DTR, thetaRad, thetaDeg;

  kP = 2.1;
  kI = 0.003;
  kD = 1.35;

  do{
    lastL = currentL;
    lastR = currentR;
    lastL = DTL;
    lastR = DTR;

    currentL = LeftEnc.get_value();
    currentR = RightEnc.get_value();

    DTL = (currentL/360)*(M_PI*4);
    DTR = (currentR/360)*(M_PI*4);

    deltaL = DTL - lastL;
    deltaR = DTR - lastR;

    thetaRad = (DTL-DTR)/14;

    thetaDeg = thetaRad*(180/M_PI);

    error = thetaDeg - target;
    totalError += error;
    lastError = error;

    P = error*kP;
    I = kI*totalError;
    D = kD*(error-lastError);

    pros::lcd::print(2, "angle: %f", thetaDeg);

    pros::lcd::print(4, "pwr: %f", pwr);

    pwr = P+I+D;

    LF.move_velocity(-pwr);
    LB.move_velocity(-pwr);
    RF.move_velocity(pwr);
    RB.move_velocity(pwr);
    pros::delay(20);

  }while(!(error >= -1 && error <=1));
  LB.move_velocity(0);
  RB.move_velocity(0);
  LF.move_velocity(0);
  RF.move_velocity(0);
}

void opcontrol() {
  pros::Task driveTask(drive, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
  LeftEnc.reset();
  RightEnc.reset();

  double currentL, currentR, lastL, lastR, deltaL, deltaR, error, DTL, DTR, thetaRad, thetaDeg, X, Y, deltaX, deltaY;

  lastL = currentL;
  lastR = currentR;
  while(true){
    lastL = currentL;
    lastR = currentR;
    lastL = DTL;
    lastR = DTR;

    currentL = LeftEnc.get_value();
    currentR = RightEnc.get_value();

    DTL = (currentL/360)*(M_PI*4);
    DTR = (currentR/360)*(M_PI*4);

    deltaL = DTL - lastL;
    deltaR = DTR - lastR;

    thetaRad = (DTL-DTR)/14;

    thetaDeg = thetaRad*(180/M_PI);
    // if(master.get_digital(DIGITAL_X)){
    //   goodTurn(90);
    // }
    //
    // if(master.get_digital(DIGITAL_Y)){
    //   goodTurn(0);
    // }
    X = cos(thetaRad)*((DTL+DTR)/2);
    Y = sin(thetaRad)*((DTL+DTR)/2);

    pros::lcd::print(0, "X: %f", X);

    pros::lcd::print(1, "Y: %f", Y);

    pros::lcd::print(2, "angle: %f rads", thetaRad);

    pros::lcd::print(3, "angle: %f deg", thetaDeg);

    pros::delay(20);
  }
}
