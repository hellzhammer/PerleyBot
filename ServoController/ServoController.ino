#include "ServoController.h"

void setup() {
  initServo();
  delay(1000);
}

void loop() {
  axleTurnRight();
  delay(100);
  axleTurnLeft();
  delay(100);
}
