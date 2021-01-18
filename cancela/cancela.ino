#include <Servo.h>
#include <NewPing.h>

#define M 13
#define TRIGGER 8
#define ECHO 2

Servo servo;
NewPing sonar(TRIGGER, ECHO, 10);

int valorSonar = 0;

void setup() {
  Serial.begin(9600);
  servo.write(0); // Valor inicial do servo 
}

void loop() {
  valorSonar = sonar.ping_cm();

  do {
    servo.write(90); // Servo fazendo um angulo de 90 graus
    valorSonar = sonar.ping_cm();
    delay(1000);
  } while (valorSonar1 != 0);

  servo.write(0); // Servo fazendo um angulo de 0 graus
}

