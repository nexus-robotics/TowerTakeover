#include "main.h"
#include "motors.hpp"
#include "functions.hpp"
void Move_Drive(void*){
  double current, last, passed;
  while(true){
    LF.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_LEFT_X));
    LM.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_LEFT_X));
    LB.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_LEFT_X));
    RF.move(master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_LEFT_X));
    RM.move(master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_LEFT_X));
    RB.move(master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_LEFT_X));

    pros::delay(20);
  }
}

void Move_Lift(void*){
  lift.set_brake_mode(MOTOR_BRAKE_HOLD);
  while(true){

    if((abs(master.get_analog(ANALOG_RIGHT_Y))) < 5){
      lift.move_velocity(0);
    }
    else{
      lift.move(master.get_analog(ANALOG_RIGHT_Y));
    }
    pros::delay(20);
  }
}

void liftPID(double target){
  lift.set_brake_mode(MOTOR_BRAKE_HOLD);
  double current, error, lastError, P, D, kP = 0.7, kD = 0.75, pwr, currTime, lastTime, totalError, I, kI = 0.1;
  do{
    current = liftPot.get_value_calibrated();

    lastError = error;
    error = target - current;
    totalError+=error;

    P = error * kP;
    I = kI * totalError;
    D = kD * (error - lastError);

    pwr = P + D;

    lift.move(-pwr);

    if(fabs(error) < 20){
      lastTime = currTime;
      currTime = pros::millis();
      if(currTime - lastTime > 1000){
        break;
      }
    }
  }while(fabs(error) > 5);
  lift.move_velocity(0);

}

void Move_Preset(void*){
  while(true){
    if(master.get_digital(DIGITAL_B)){
      liftPID(0);
    }
    else if(master.get_digital(DIGITAL_Y)){
			liftPID(-320);
		}
		else if(master.get_digital(DIGITAL_X)){
			liftPID(-400);
		}

		if(master.get_digital(DIGITAL_L1)){
				claw.move_absolute(-300, 200);
		}

		else if (master.get_digital(DIGITAL_L2)){
			claw.move_absolute(-50, 200);
		}

    pros::delay(20);
  }
}
