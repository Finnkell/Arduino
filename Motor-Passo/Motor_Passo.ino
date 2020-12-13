/* Objetivo: mover o servo de passo no sentido horario e anti horario */

#include <Stepper.h>  // Biblioteca do motor de passo

// Variaveis
#define in1 8
#define in2 9
#define in3 10
#define in4 11

const int stepsPerRevolution = 32;  // Constante

Stepper myStepper(stepsPerRevolution, in1, in2, in3, in4);  // Funcao do motor

void setup() {
  myStepper.setSpeed(500);  // Velocidade do movimento
}

void loop() {
  Serial.println("Sentido Horario");  // Mostrar a mensagem no terminal
  myStepper.step(2000); // Valor para mover o motor no sentido horario

  delay(500); // Espera em milissegundos

  Serial.println("Sentido Anti Horario"); // Mostrar a mensagem no terminal
  myStepper.step(-1000);  // Valor para mover o motor no sentido anti horario
}
