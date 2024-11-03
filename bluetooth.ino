#include <Servo.h>
Servo sr, sl;
void setup() {
  Serial.begin(9600);
  sr.attach(13);
  sl.attach(12);
}
void loop() {
  if (Serial.available()) {
    char b[2];
    int p, r;
    Serial.readBytes(b, 2);
    p = b[0] * 3;
    r = b[1];
    sr.write(1500 + p - r);
    sl.write(1500 - p - r);
    Serial.write('1');
  }
}
