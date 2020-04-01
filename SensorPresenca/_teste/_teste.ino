// include the library code:
#include <LiquidCrystal.h>
#include "dht.h"

// define pinos Ultrasom
#define pino_sensorTemp A2

//define as variáveis
int temp_valor;
int hum_valor;

// Inicializa o objeto da biblioteca LiquidCrystal
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Inicializa o objeto do tipo DHT
dht DHT;

void setup() {
  // da set up no lcd, (colunas, linhas)
  lcd.begin(16, 2);
}

void loop() {
  //Le as informacoes do sensor, em cm e pol
  lcd.clear();
  //Le as informacoes do DHT11
  DHT.read11(pino_sensorTemp);
  temp_valor = DHT.temperature;
  hum_valor = DHT.humidity;
  
  //Exibe informacoes no LCD
  lcd.print("TEMPERATURA: ");
  lcd.print(temp_valor);
  lcd.setCursor(0,1);
  lcd.print(" UMIDADE: ");
  lcd.print(hum_valor);
  delay(1000);
  // Printa o número de segundos até que seja resetado o arduino:
  lcd.print(millis() / 1000);
} 