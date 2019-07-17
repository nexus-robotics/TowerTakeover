#include "main.h"
#include "motors.hpp"
#include "functions.hpp"

void pidDrive(double target){
  double currentL, pwr, currentR, lastL, lastR, deltaL, deltaR, error, DTL, DTR, thetaRad, thetaDeg, X, Y, deltaX, deltaY, totalError, lastError, P, I, D, kP, kI, kD;
  kP = 10;
  kI = 0.008;
  kD = 10;
  // lastL = currentL;
  // lastR = currentR;
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

    X = cos(thetaRad)*((DTL+DTR)/2);
    Y = sin(thetaRad)*((DTL+DTR)/2);

    totalError += error;
    lastError = error;
    error = X - target;

    P = error*kP;
    I = kI*totalError;
    D = kD*(error-lastError);
    pwr = P+I+D;

    LF.move_velocity(-pwr);
    LB.move_velocity(-pwr);
    RF.move_velocity(-pwr);
    RB.move_velocity(-pwr);
    pros::delay(20);
  }while(!(error <= 0.5 && error >=-0.5));
  LB.move_velocity(0);
  RB.move_velocity(0);
  LF.move_velocity(0);
  RF.move_velocity(0);
}

void driveToPoint(double x, double y){
  double desiredTheta ,currentL, pwr, currentR, lastL, lastR, deltaL, deltaR, error, DTL, DTR, thetaRad, thetaDeg, X, Y, deltaX, deltaY, totalError, lastError, P, I, D, kP, kI, kD;

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

  X = cos(thetaRad)*((DTL+DTR)/2);
  Y = sin(thetaRad)*((DTL+DTR)/2);

  desiredTheta = atan2(y,x);

  odomTurn_rad(desiredTheta);
  odomTurn_rad(desiredTheta);
  odomTurn_rad(desiredTheta);
  //Why are we doing this 3 times? -Greg
  //Why not??? -Farees
  pidDrive(x);


}

void printXY(void*){
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

    X = cos(thetaRad)*((DTL+DTR)/2);
    Y = sin(thetaRad)*((DTL+DTR)/2);

    pros::lcd::print(0, "X: %f", X);

    pros::lcd::print(1, "Y: %f", Y);

    pros::lcd::print(2, "angle: %f rads", thetaRad);

    pros::lcd::print(3, "angle: %f deg", thetaDeg);

    pros::delay(20);
  }
}

void goodTurn(double target){
  double  pwr, totalError, lastError, P, I, D, kP, kI, kD;
  double currentL, currentR, lastL, lastR, deltaL, deltaR, error, DTL, DTR, thetaRad, thetaDeg;

  kP = 2.1;
  kI = 0.008;
  kD = 10;

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

    totalError += error;
    lastError = error;
    error = thetaDeg - target;

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

  }while(!(error <= 0.5 && error >=-0.5));
  LB.move_velocity(0);
  RB.move_velocity(0);
  LF.move_velocity(0);
  RF.move_velocity(0);
}

void odomTurn_rad(double target){
  double  pwr, totalError, lastError, P, I, D, kP, kI, kD;
  double currentL, currentR, lastL, lastR, deltaL, deltaR, error, DTL, DTR, thetaRad, thetaDeg;

  kP = 150;
  kI = 0.8;
  kD = 1500;

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

    totalError += error;
    lastError = error;
    error = thetaRad - target;


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

  }while(!(error <= 0.1 && error >=-0.1));

  LB.move_velocity(0);
  RB.move_velocity(0);
  LF.move_velocity(0);
  RF.move_velocity(0);

}

void drive(void*){

  while(true){

    if(master.get_digital(DIGITAL_X)){odomTurn_rad(-1);}
    if(master.get_digital(DIGITAL_B)){
      driveToPoint(-10, 0);
      pros::delay(100);
      driveToPoint(-10, 0);
      pros::delay(100);
      driveToPoint(-10, 0);
    }
    if(master.get_digital(DIGITAL_Y)){
      driveToPoint(57.73, -25.18);
      pros::delay(100);
      driveToPoint(57.73, -25.18);
      pros::delay(100);
      driveToPoint(57.73, -25.18);
      //Also, why are we doing this 3 time? -Greg
      //Why not??? -Farees
    }

    LF.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_X));
    LB.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_X));
    RF.move(master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_X));
    RB.move(master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_X));
    pros::delay(20);
  }


}
