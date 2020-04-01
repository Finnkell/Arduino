#include "DHT.h"
#include "DHT_U.h"

// include the library code:
#include <LiquidCrystal.h>

// define pinos Ultrasom
#define pino_sensorTemp A2

//define as variáveis
int temp_valor;

// Inicializa o objeto da biblioteca LiquidCrystal
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Inicializa o objeto do tipo DHT
DHT dht(pino_sensorTemp, DHT11);

void setup() {
  // da set up no lcd, (colunas, linhas)
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  
  lcd.clear();
  temp_valor = dht.readTemperature();
  
  //Exibe informacoes no LCD
  lcd.print("TEMPERATURA: ");
  lcd.print(temp_valor);
  delay(1000);
  
  // Printa o número de segundos até que seja resetado o arduino:
  lcd.print(millis() / 1000);
} 
