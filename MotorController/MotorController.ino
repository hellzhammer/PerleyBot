#include "MotorController.h"

void setup() {
  initMotor();
}

void loop() {
  driveMotor();
  delay(1000);
  slowToStop();
  delay(1000);  
}
