#include <IRremote.h>
#include <Servo.h>

#define MOTOR1 8
#define MOTOR2 9
#define trigger 12
#define echo 11

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7

Servo servo1;
Servo servo2;

int BUZZER = 10;
int reciever = 13;

float valor = 0;
int distancia = 0;

IRrecv controle(reciever);
decode_results results;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  controle.enableIRIn();
  servo1.attach(MOTOR1);
  servo2.attach(MOTOR2);
  servo1.write(0);
  servo2.write(0);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(20);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigger, LOW);

  distancia = pulseIn(echo, trigger);
  distancia = distancia * 0.05;

  if (controle.decode(&results)) {
    Serial.print("Valor: ");
    Serial.println(results.value, HEX);

    valor = results.value;

    controle.resume();
  }

  // COMODO 1
  if (valor == 0xFFA25D || valor == 0xE318261B) {                // BOTAO 1
    digitalWrite(LED1, HIGH);
  }

  if (valor == 0xFF02FD || valor == 0xD7E84B1B) {                // BOTAO 5
    digitalWrite(LED1, LOW);
  }

  // COMODO 2
  if (valor == 0xFF629D || valor == 0x511DBB) {                // BOTAO 2
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  }

  if (valor == 0xFFC23D || valor == 0x20FE4DBB) {                // BOTAO 6
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  // COMODO 3
  if (valor == 0xFFE21D || valor == 0xEE886D7F) {                // BOTAO 3
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }

  if (valor == 0xFFE01F || valor == 0xF076C13B) {                // BOTAO 7
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }

  // COMODO 4
  if (valor == 0xFF22DD || valor == 0x52A3D41F) {                // BOTAO 4
    digitalWrite(LED6, HIGH);
  }

  if (valor == 0xFFA857 || valor == 0xA3C8EDDB) {                // BOTAO 8
    digitalWrite(LED6, LOW);
  }

  // ABRE PORTA
  if (valor == 0xFF6897 || valor == 0xC101E57B) {
    servo1.write(69);                    // BOTAO *
  }

  // FECHA PORTA
  if (valor == 0xFFB04F || valor == 0xF0C41643) {               // BOTAO #
    servo1.write(0);
  }

  // ABRE JANELA
  if (valor == 0x8C22657B || valor == 0xFF10EF) {               // BOTAO <-
    servo2.write(69);                    
  }

  // FECHA JANELA
  if (valor == 0x449E79F || valor == 0xFF5AA5) {               // BOTAO ->
    servo2.write(0);
  } 

  // TESTA ALARME
  if (valor == 0xFF38C7 || valor == 0x488F3CBB || distancia <= 10) {  // BOTAO ok (para desligar é só apertar qualquer botão).
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
  }
  
}
