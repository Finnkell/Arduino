// include the library code:
#include <LiquidCrystal.h>
#include <NewPing.h>

// define pinos Ultrasom
#define pino_trigger 8
#define pino_echo 9
#define MAX_DISTANCE 200

// Inicializa os objetos das bibliotecas, LiquidCrystal e NewPing
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
NewPing sonar(pino_trigger, pino_echo, MAX_DISTANCE);

void setup() {
  // da set up no lcd, (colunas, linhas)
  lcd.begin(16, 2);
  // printa uma mensagem no LCD.
  lcd.print("hello, world!");
}

void loop() {
  //Le as informacoes do sensor, em cm e pol
  lcd.clear();
  //Exibe informacoes no serial monitor
  lcd.print("Distancia: ");
  lcd.print(sonar.ping_cm());
  delay(1000);
  // Printa o número de segundos até que seja resetado o arduino:
  lcd.print(millis() / 1000);
}
 
