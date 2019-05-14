#include "main.h"
#include "motors.hpp"
#include "functions.hpp"

void drive(void*){
  double deltaL, deltaR, currentL, currentR, lastL = 0, lastR = 0;
  while(true){
    LF.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_X));
    LB.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_X));
    RF.move(master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_X));
    RB.move(master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_X));
    pros::delay(20);
  }
}
