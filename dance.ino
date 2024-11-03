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
  spinLeft(1800);
  stop(300);
  spinLeft(200);
  spinRight(200);
  spinLeft(200);
  spinRight(200);
  stop(100);

  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinRight(2000);
  spinLeft(200);
  spinRight(400);
  spinLeft(600);

  moveForward(1600);
  spinLeft(1600);
  moveForward(1600);
  spinRight(1600);

  moveForward(400);
  moveBackward(400);
  moveForward(400);
  moveBackward(400);
  spinLeft(1600);

  moveBackward(400);
  moveForward(400);
  moveBackward(400);
  moveForward(400);
  spinRight(1600);

  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(1800);
  stop(300);
  spinLeft(200);
  spinRight(200);
  spinLeft(200);
  spinRight(200);
  stop(100);

  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(400);
  spinRight(400);
  spinLeft(1800);
  stop(300);
  spinLeft(200);
  spinRight(200);
  spinLeft(200);
  spinRight(200);
  stop(10000);
  
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

void stop(int duration) {
  rightServo.write(1500);
  leftServo.write(1500);
  delay(duration);
}
