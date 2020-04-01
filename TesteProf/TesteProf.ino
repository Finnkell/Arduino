#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

#define pinoChave 7
#define Buzzer 9
#define Led 13
#define Led2 12

bool estadoChave = false;
bool estadoLed = false;

int horaMed, minMed;
int horaMed2, minMed2;
int horaAtual, minAtual;

void setup() {
  Serial.begin(9600);
  delay(3000);

  if (!rtc.begin()) {
    Serial.print("Erro");
    while (1);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(Led, OUTPUT);
  pinMode(Buzzer, OUTPUT);

}

void loop() {
  DateTime now = rtc.now();
  horaAtual = now.hour();
  minAtual = now.minute();

  horaMed = 16;
  minMed = 50;

  horaMed2 = 16;
  minMed2 = 50;

  estadoChave = digitalRead(pinoChave);

  Serial.println(estadoChave);

  Serial.print(horaAtual, DEC);
  Serial.print(":");
  Serial.println(minAtual, DEC);

  if (horaMed == horaAtual && minMed == minAtual) {
    while (!estadoChave) {
      estadoChave = digitalRead(pinoChave);
      tone(Buzzer, 400);
      digitalWrite(Led, HIGH);
    }
    noTone(Buzzer);
    delay(1000);
    digitalWrite(Led, LOW);
    estadoChave = digitalRead(pinoChave);
    delay(1000);
    
    if (horaMed2 == horaAtual && minMed2 == minAtual) {
      while (!estadoChave) {
        estadoChave = digitalRead(pinoChave);
        tone(Buzzer, 700);
        digitalWrite(Led2, HIGH);
      }
      noTone(Buzzer);
      digitalWrite(Led2, LOW);
    } else {
      noTone(Buzzer);
    }
  } else {
    noTone(Buzzer);
  }

}
