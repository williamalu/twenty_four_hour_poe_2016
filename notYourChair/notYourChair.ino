#include "pins.h"

int leftMotorSpeed = 0;
int rightMotorSpeed = 0;

void setup() {
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
}

void loop() {
  for (int i; i <= 255; i++) {
    leftMotorSpeed = i;
    rightMotorSpeed = i;
    analogWrite(LEFT_MOTOR, leftMotorSpeed);
    analogWrite(RIGHT_MOTOR, rightMotorSpeed);
    delay(100);
  }
}
