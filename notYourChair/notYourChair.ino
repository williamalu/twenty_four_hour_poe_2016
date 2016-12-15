#include "pins.h"

int leftMotorSpeed = 0;
int rightMotorSpeed = 0;
int prevMotorSpeed = 0;
int triggerCounter = 0;
float lastTimeTrigger = 0;

void setup() {
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  pinMode(SIT_DETECT_IR, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (checkSit()) {
    if (prevMotorSpeed == 0) {
      for (int i; i <= 255; i++) {
        leftMotorSpeed = i;
        rightMotorSpeed = i;
        prevMotorSpeed = i;
        analogWrite(LEFT_MOTOR, leftMotorSpeed);
        analogWrite(RIGHT_MOTOR, rightMotorSpeed);
      }
    }
    else {
      for (int i = prevMotorSpeed; i <= 255; i++) {
        leftMotorSpeed = i;
        rightMotorSpeed = i;
        prevMotorSpeed = i;
        analogWrite(LEFT_MOTOR, leftMotorSpeed);
        analogWrite(RIGHT_MOTOR, rightMotorSpeed);
      }
    }
  }
  if (checkSit() == false){
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
    prevMotorSpeed = 0;
    analogWrite(LEFT_MOTOR, leftMotorSpeed);
    analogWrite(RIGHT_MOTOR, rightMotorSpeed);
  }
  delay(100);
}

bool checkSit() {
  if (analogRead(SIT_DETECT_IR) > 250) {
    triggerCounter++;
    lastTimeTrigger = millis();
  }
  if (millis() - lastTimeTrigger >= 100) {
    triggerCounter = 0;
    return false;
  }
  if (triggerCounter > 5) {
    return true;
  }
  return false;
}

