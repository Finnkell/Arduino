#include <Stepper.h>

const int stepsPerRevolution = 500;

//Utilizando as portas digitais 08 a 11 para conexao ao motor
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()
{
  // Velocidade inicial do motor (MAX 100)
  myStepper.setSpeed(60);
}

void loop()
{
  //Gira o eixo  do motor no sentido horario - 90 graus
  for (int i = 0; i < 1; i++)
  {
    myStepper.step(-512);
    delay(2000);
  }

  for (int i = 0; i < 1; i++)
  {
    myStepper.step(511);
    delay(2000);
  }

  delay(2000);
}
