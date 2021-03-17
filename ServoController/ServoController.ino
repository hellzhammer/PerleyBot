#include <Servo.h>

//servo
Servo servo;
float rot;
int servoPin = 9;

int centerRot = 85;
float left, right;

void setup() {
  initServo();
  delay(100);
}

void loop() {
  //axleTurnRight();
  //axleTurnLeft();
}

void axleTurnRight() {
  // test turn right
  for (int i = rot; i < right; i += 1) {
    rot += 1;
    servo.write(rot);
    delay(10);
  }
  delay(10);
  if (rot > right) {
    rot = right;
    servo.write(rot);
  }
}

void axleTurnLeft() {
  // test turn right
  for (int i = rot; i > left; i -= 1) {
    rot -= 1;
    servo.write(rot);
    delay(10);
  }
  delay(10);
  if (rot < left) {
    rot = left;
    servo.write(rot);
  }
}

void initServo() {
  // set up the left, right rot values
  float val = centerRot / 2;
  left = val;
  right = centerRot + val;

  //get servo instance
  servo.attach(servoPin);

  //home servo
  homeServo();
  delay(100);

  //prep servo for drive
  rot = centerRot;
  positionUpdate(rot);
}

void homeServo() {
  rot = 0;
  servo.write(rot);
}

void positionUpdate(int value) {
  servo.write(value);
}
