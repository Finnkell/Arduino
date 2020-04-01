#include <Stepper.h>
#include <NewPing.h>

#define MAX 10

const int stepsPerRevolution = 500;

//ligacao ao motor
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

NewPing sonar1(4, 3, MAX);
NewPing sonar2(7, 6, MAX);
NewPing sonar3(13, 12, MAX);

int valorSonar1 = 0;
int valorSonar2 = 0;
int valorSonar3 = 0;
bool valor;

void setup()
{
  //Determina a velocidade inicial do motor
  myStepper.setSpeed(60);
  Serial.begin(9600);
}

void loop()
{
  valorSonar1 = sonar1.ping_cm();
  valorSonar2 = sonar2.ping_cm();

  if (valorSonar1 != 0 || valorSonar2 != 0) {
    myStepper.step(-512);
    delay(10000);
    valorSonar1 = sonar1.ping_cm();
    valorSonar2 = sonar2.ping_cm();
    valorSonar3 = sonar3.ping_cm();

    if (valorSonar2 == 0 && valorSonar3 == 0) {
      myStepper.step(511);
      delay(1000);
    } else {
      do {
        valorSonar1 = sonar1.ping_cm();
        valorSonar2 = sonar2.ping_cm();
        valorSonar3 = sonar3.ping_cm();
      } while (valorSonar2 == 0 && valorSonar3 == 0);
      myStepper.step(511);
      delay(1000);
    }
    
  } else {
    Serial.print("Nada");
  }

  delay(1000);

}
