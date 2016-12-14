#include "pins.h"

int leftMotorSpeed = 0;
int rightMotorSpeed = 0;
int prevMotorSpeed = 0;
int triggerCounter = 0;

void setup() {
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  pinMode(SIT_DETECT_IR, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (checkSit()) {
    Serial.println("checkSit True");
    if (prevMotorSpeed == 0) {
      for (int i; i <= 255; i++) {
        leftMotorSpeed = i;
        rightMotorSpeed = i;
        prevMotorSpeed = i;
        analogWrite(LEFT_MOTOR, leftMotorSpeed);
        analogWrite(RIGHT_MOTOR, rightMotorSpeed);
//        Serial.println(i);
      }
    }
    else {
      for (int i = prevMotorSpeed; i <= 255; i++) {
        leftMotorSpeed = i;
        rightMotorSpeed = i;
        prevMotorSpeed = i;
        analogWrite(LEFT_MOTOR, leftMotorSpeed);
        analogWrite(RIGHT_MOTOR, rightMotorSpeed);
//        Serial.println(i);
      }
    }
  }
  if (checkSit() == 0){
    Serial.println("checkSit False");
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
  }
  if (triggerCounter > 5) {
    triggerCounter = 0;
    return 1;
  }
  return 0;
}

