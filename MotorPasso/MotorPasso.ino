#include <Stepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

const int stepsPerRevolution = 32;

Stepper myStepper(stepsPerRevolution, in1, in2, in3, in4);

void setup() {
  myStepper.setSpeed(500);
}

void loop() {
  Serial.println("Sentido Horario");
  myStepper.step(2000);
  delay(500);
  Serial.println("Sentido Anti Horario");
  myStepper.step(-1000);

}
