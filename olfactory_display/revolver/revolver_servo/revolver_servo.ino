#include <Servo.h>

Servo servo;
int data;

void setup() {
  Serial.begin(9600);
  servo.attach(6);
}

void loop() {
  delay(3000);
  servo.write(0);
  delay(3000);
  servo.write(90);
}
