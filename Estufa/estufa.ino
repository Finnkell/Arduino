/*
 *   NÃO ESQUECER QUE O RTC NÃO PODDE LIGAR NO 5V, LIGAR ELE NO 3.3V
 *   
 *   SE NÃO EXPLODE!!!!!!!!!
 * 
*/

#include <dht.h>
#include <Servo.h>
#include <Wire.h>
#include <RTClib.h>

// Define os pinos do motor e dos sensores de temperatura
#define MOTOR 2
#define pinoSensorTemp1 A0
#define pinoSensorTemp2 A1


// Define os pinos dos Led's
#define LED1 13
#define LED2 12

// Cria a variavel do Servo, dos sensores de Temperatura e do RTC
Servo servo;
dht DHT1;
dht DHT2;
RTC_DS3231 rtc;

// Inicializa as variáveis para guardar os valore de temperatura e média
int tempValor1 = 0;
int tempValor2 = 0;
int media = 0;

void setup() {
  // Adiciona o MOTOR na variável servo e seta em 0°
  servo.attach(MOTOR);
  servo.write(0);

  // Inicializa o Serial Monitor
  Serial.begin(9600);


  // Inicializa os tratamentos de Exceções do RTC (Não precisa mexer nessa parte do código até o delay(300))
  if (!rtc.begin()) {
    Serial.print("Erro");
    while (1);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  delay(300);
}

void loop() {

  // Variável que calcula o tempo
  DateTime tempo = rtc.now();

  // Inicializa os sensores de Temperatura
  DHT1.read11(pinoSensorTemp1);
  DHT2.read11(pinoSensorTemp2);

  // Guarda nas variaveis o valor de temperatura
  tempValor1 = DHT1.temperature;
  tempValor2 = DHT2.temperature;

  // Calcula a média das temperaturas
  media = (tempValor1 + tempValor2) / 2;


  // Mostra no monitor Serial o valores de Horario, Temperatura e a Media. CTRL + SHIFT + M;
  Serial.print("Horario: ");
  Serial.print(tempo.hour());
  Serial.print(":");
  Serial.println(tempo.minute());

  Serial.print("Temperatura 1: ");
  Serial.println(tempValor1);

  Serial.print("Temperatura 2: ");
  Serial.println(tempValor2);

  // Abre cortina quando a temperatura se a média da temperatura dos sensores for maior ou igual à 28°
  if (media >= 28) {
    // Gira o servo em 180°
    servo.write(180);

    // Le novamente o valor de temperatura
    tempValor1 = DHT1.temperature;
    tempValor2 = DHT2.temperature;

    // Calcula a média das temperaturas
    media = (tempValor1 + tempValor2) / 2;

    Serial.print("Temperatura 1: ");
    Serial.println(tempValor1);

    Serial.print("Temperatura 2: ");
    Serial.println(tempValor2);
    
    Serial.print("Media: ");
    Serial.println(media);
    delay(50);
    
  } else if (media <= 16) { // Abre cortina quando a temperatura se a média da temperatura dos sensores for menor ou igual à 16°
    // Gira o servo em 0°
    servo.write(0);

    // Le novamente o valor de temperatura
    tempValor1 = DHT1.temperature;
    tempValor2 = DHT2.temperature;

    // Calcula a média das temperaturas
    media = (tempValor1 + tempValor2) / 2;

    Serial.print("Temperatura 1: ");
    Serial.println(tempValor1);

    Serial.print("Temperatura 2: ");
    Serial.println(tempValor2);
    
    Serial.print("Media: ");
    Serial.println(media);
    delay(50);
  }


  // Apaga LED as 22:00 horas. Obs.: Colocar o resto dos Led's
  if (tempo.hour() == 22) {
    digitalWrite(LED1, LOW);
    // Aqui o resto dos Led's
  }

  // Acende LED as 06:00 horas. Obs.: Colocar o resto dos Led's
  if (tempo.hour() == 6) {
    digitalWrite(LED1, HIGH);
    // Aqui o resto dos Led's
  }


  delay(100);

}
