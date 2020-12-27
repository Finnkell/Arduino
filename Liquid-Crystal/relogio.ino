#include <Wire.h>
#include <LiquidCrystal.h>
#include "RTClib.h"

LiquidCrystal lcd(13, 12, 7, 6, 5, 4);
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  delay(3000);

  if (!rtc.begin()) {
    Serial.print("Erro");
    while (1);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now(); // Data atual

  // Exibe a data
  lcd.setCursor(0,0); // Posicao inicial do cursor coluna 0/linha 0
  lcd.print(now.day(), DEC);  // Dia
  lcd.print("/"); // exibe /
  lcd.print(now.month(), DEC); // Mes
  lcd.print("/");
  lcd.print(now.year(), DEC); // Ano
  

  Serial.print(now.year(), DEC);  // Ano
  Serial.print("/");
  Serial.print(now.month(), DEC); // Mes
  Serial.print("/");
  Serial.println(now.day(), DEC); // Dia
  
  // Exibe o horario
  lcd.setCursor(0,1); // Posicao do cursor coluna 0/linha 1
  lcd.print(now.hour(), DEC); // Hora
  lcd.print(":");
  lcd.print(now.minute(), DEC); // Minuto
  lcd.print(":");
  lcd.print(now.second(), DEC); // Segundo

  delay(1000);
}
