#include <LiquidCrystal.h>
#define PIR 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(PIR, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  bool valorPIR = digitalRead(PIR);
  lcd.setCursor(0, 0);
  
  if (valorPIR) {
    lcd.print("TEM GENTE");
  }else {
    lcd.print("NAO TEM GENTE");
  }
  delay(1000);
  lcd.clear();
}


 
