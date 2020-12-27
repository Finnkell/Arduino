#include <Servo.h>

#define M1 13
#define M2 12
#define M3 11
#define M4 10

int valor = 0;
int valor2 = 0;
int valor3 = 0;
int valor4 = 0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(M1);
  servo2.attach(M2);
  servo3.attach(M3);
  servo4.attach(M4);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor = analogRead(A1);
  valor = map(valor, 0, 1023, 1, 180);
  Serial.print("valor1: ");
  Serial.println(valor);
  servo1.write(valor);

  valor2 = analogRead(A0);
  valor2 = map(valor2, 0, 1023, 1, 180);
  Serial.print("valor2: ");
  Serial.println(valor2);
  servo2.write(valor2);

  valor3 = analogRead(A2);
  valor3 = map(valor3, 0, 1023, 1, 180);
  Serial.print("valor3: ");
  Serial.println(valor3);
  servo3.write(valor3);

  valor4 = analogRead(A3);
  valor4 = map(valor4, 0, 1023, 1, 180);
  Serial.print("valor4: ");
  Serial.println(valor4);
  servo4.write(valor4);

  delay(50);
  
}
