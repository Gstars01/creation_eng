#include <Servo.h>

Servo rightServo;
Servo leftServo;

void setup() {
  rightServo.attach(12);
  leftServo.attach(13);
}

void loop() {
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(1600);

  moveForward(400);
  moveBackward(400);
  moveForward(400);
  moveBackward(400);
  spinLeft(1700);

  moveBackward(400);
  moveForward(400);
  moveBackward(400);
  moveForward(400);
  spinRight(1700);
}

void moveForward(int duration) {
  rightServo.write(1300);
  leftServo.write(1700);
  delay(duration);
}

void moveBackward(int duration) {
  rightServo.write(1700);
  leftServo.write(1300);
  delay(duration);
}

void spinLeft(int duration) {
  rightServo.write(1300);
  leftServo.write(1300);
  delay(duration);
}

void spinRight(int duration) {
  rightServo.write(1700);
  leftServo.write(1700);
  delay(duration);
}
