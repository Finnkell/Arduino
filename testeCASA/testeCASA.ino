#include <Servo.h>
#include <IRremote.h>

#define speaker A1

#define NOTE_E4 330
#define NOTE_GS4 415
#define NOTE_DS4 311
#define NOTE_B4 494
#define NOTE_B5 988
#define NOTE_CS4 277
#define NOTE_FS4 370
#define NOTE_G4 392

#define M1 13
#define M2 12

#define reciever A2

#define LED1 2 
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define TV 8

float valor;

Servo servo1;
Servo servo2;
IRrecv controle(reciever);
decode_results results;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(TV, OUTPUT);
  pinMode(speaker, OUTPUT);

  servo1.attach(M1);
  servo2.attach(M2);
  controle.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if (controle.decode(&results)) {
    Serial.print("Valor: ");
    Serial.println(results.value, HEX);

    valor = results.value;
    
    if (valor == 0xB4B48C73) {
      servo1.write(90);
    }

    if (valor == 0xB4B49C63) {
      servo1.write(0);
    }

    if (valor == 0xB4B41AE5) {
      servo2.write(90);
    }

    if (valor == 0xB4B41CE3) {
      servo2.write(0);
    }

    if (valor == 0xB4B4E21D) {
      digitalWrite(LED1, HIGH);
    }

    if (valor == 0xB4B45AA5) {
      digitalWrite(LED2, HIGH);
    }

    if (valor == 0xB4B412ED) {
      digitalWrite(LED3, HIGH);
    }

    if (valor == 0xB4B49A65) {
      digitalWrite(LED4, HIGH);
    }

    if (valor == 0xB4B4FC03) {
      digitalWrite(LED5, HIGH);
    }

    if (valor == 0xB4B402FD) {
      digitalWrite(LED6, HIGH);
    }

    if (valor == 0xB4B4827D) {
      digitalWrite(TV, HIGH);
    }

    if (valor == 0xB4B43EC1) {
      digitalWrite(LED1, LOW);
    }

    if (valor == 0xB4B4BE41) {
      digitalWrite(LED2, LOW);
    }

    if (valor == 0xB4B47E81) {
      digitalWrite(LED3, LOW);
    }

    if (valor == 0xB4B4FE01) {
      digitalWrite(LED4, LOW);
    }
    
    if (valor == 0xB4B426D9) {
      digitalWrite(LED5, LOW);
    }

    if (valor == 0xB4B48679) {
      digitalWrite(LED6, LOW);
    }

    if (valor == 0xB4B446B9) {
      digitalWrite(TV, LOW);
    }
    
    controle.resume();
  }
}
