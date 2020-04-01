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
  DateTime now = rtc.now();

  lcd.setCursor(0,0);
  lcd.print(now.day(), DEC);;
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year(), DEC);
  

  Serial.print(now.year(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.println(now.day(), DEC);
  
  lcd.setCursor(0,1);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);

  delay(1000);
}
