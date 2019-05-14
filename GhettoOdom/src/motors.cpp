#include "main.h"
#include "motors.hpp"

pros::Motor LB(20);
pros::Motor RB(10, true);
pros::Motor RF(1, true);
pros::Motor LF(11);
pros::ADIEncoder LeftEnc(3,4);
pros::ADIEncoder RightEnc(5,6,true);
pros::Controller master(pros::E_CONTROLLER_MASTER);
