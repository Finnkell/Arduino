#include <Servo.h>
#include <IRremote.h>
#define M 13

Servo servo;

void setup() {
  servo.attach(M);
}

void loop() {
  servo.write(0);
}
