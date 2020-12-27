#include <IRremote.h>
#include <Servo.h>

#define MOTOR 13
#define trigger 9
#define echo 8

int reciever = 7;
int distancia = 0;

Servo servo;

IRrecv controle(reciever);
decode_results results;

float valor = 0;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(11, OUTPUT);
  servo.attach(MOTOR);
  servo.write(0);
  Serial.begin(9600);
  controle.enableIRIn();
}

void loop() {

  digitalWrite(trigger, LOW);
  delayMicroseconds(20);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigger, LOW);

  distancia = pulseIn(echo, trigger);
  distancia = distancia * 0.05;

  Serial.println(distancia);

  if (controle.decode(&results)) {
    Serial.println(results.value, HEX);
    valor = results.value;

    if (valor == 0xFFA25D) {
      servo.write(90);
    }

    if (valor == 0xFF629D) {
      servo.write(0);
    }

    if (valor == 0xFFA857) {
      digitalWrite(11, HIGH);
    }

    if (valor == 0xFFE21D) {
      funcaoTeste();
    }

    controle.resume();
  }
}

void funcaoTeste() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    delay(100);
  }
}
