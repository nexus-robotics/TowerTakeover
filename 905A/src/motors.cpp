#include "main.h"
#include "motors.hpp"
pros::Motor LB(2, true);
pros::Motor LM(3);
pros::Motor RB(9);
pros::Motor RM(8, true);
pros::Motor RF(7);
pros::Motor LF(4, true);
pros::Motor lift(6, true);
pros::Motor claw(5);
pros::ADIPotentiometer liftPot('h');
pros::Controller master(pros::E_CONTROLLER_MASTER);
