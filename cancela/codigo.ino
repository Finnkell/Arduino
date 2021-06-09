#include <Servo.h>

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo servo_13;

void setup()
{
  servo_13.attach(13, 500, 2500);

}

void loop()
{
  if (0.01723 * readUltrasonicDistance(8, 2) < 100) {
    servo_13.write(90);
  } else {
    servo_13.write(0);
  }
  delay(10);
}