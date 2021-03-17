#include "MotorController.h"
// motor vars
int motorPin = 3; // the motors pin, we default to 3;
int motorSpeed, maxSpeed; // the current and the overall max speed of motor;
bool runState = false; // flag: true = run everything, false = stop/shutdown motor;
bool drive = false; // flag: true = driving, false = idle;
void initMotor() {
  if (!runState) {
    maxSpeed = 255;
    pinMode(motorPin, OUTPUT);
    runState = true;
  }
  delay(100);
}
//drive loop for motor
void driveMotor() {
  if (runState) {
    if (!drive) {
      increaseSpeedTo(maxSpeed);
      drive = true;
    }
    else {
      increaseSpeedTo(maxSpeed);
      //todo
      // this is where i am going to need to ensure that things are running normal
      //there needs to be a way to catch if there are errors before getting to far into things to.
    }
  }
  else {
    drive = false;
    deadStop();
  }
}
//increase the speed of the motor
void increaseSpeedTo(int newSpeed) {
  if (runState) {
    if (newSpeed > maxSpeed) {
      newSpeed = maxSpeed;
    }
    for (int i = motorSpeed; i < newSpeed; i += 10) {
      motorSpeed += 10;
      analogWrite(motorPin, motorSpeed);
      delay(10);
    }

    if (motorSpeed > newSpeed) {
      motorSpeed = newSpeed;
      analogWrite(motorPin, motorSpeed);
    }
  }
  else {
    drive = false;
    deadStop();
  }
}

//decrease the speed of the motor
void decreaseSpeedTo(int newSpeed) {
  if (runState) {
    for (int i = motorSpeed; i > newSpeed; i -= 10) {
      motorSpeed -= 10;
      analogWrite(motorPin, motorSpeed);
      delay(10);
    }
    if (motorSpeed < newSpeed) {
      motorSpeed = newSpeed;
      analogWrite(motorPin, motorSpeed);
    }
  }
  else {
    drive = false;
    deadStop();
  }
}
//slowly reduces power to motor
void slowToStop() {
  for (int i = motorSpeed; i > 0; i -= 5) {
    motorSpeed -= 5;
    analogWrite(motorPin, motorSpeed);
    delay(10);
  }
}
// kills all power to motor
void deadStop() {
  analogWrite(motorPin, 0);
}
