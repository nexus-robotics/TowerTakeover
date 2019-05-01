#Define target = 0; // units that the robot or function needs to move
#Define sensorValue = 0; // current value of the encoder, potentiometer, etc.
#Define error = target - sensorValue; //remaining units to be travelled
#Define kP = 0; //tuning variable to scale motor powers
#Define kI = 0;//tunning variable to eliminate small amounts of error
#Define kD = 0;//tuning variable to account for issues with scaling the derivative
#Define integral = integral + error;//keeps track of the total error
#Define prevError = 0;//tracks the previous error
#Define derivative = (error - prevError);//calculates the derivative
        prevError = error; // sets the previous error
#Define power = (error * kP) + (integral * kI) + (derivative * kD); //sets the power of the motors
        
