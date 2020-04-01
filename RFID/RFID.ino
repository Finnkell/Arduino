#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 sensor(SS_PIN, RST_PIN);

char str[20];

void setup() {
  Serial.begin(9600);
  SPI.begin();
  sensor.PCD_Init();
  Serial.println("Aprxime o cartão do leitor... ");
  Serial.println();
}

void loop() {
  if (!sensor.PICC_IsNewCardPresent()) return;
  if (!sensor.PICC_ReadCardSerial()) return;

  Serial.print("UID da tag: ");
  String conteudo = "";
  byte letra;

  for (byte i = 0; i < sensor.uid.size; i++) {
    Serial.print(sensor.uid.uidByte[i] < 0X10 ? " 0" : " ");
    Serial.print(sensor.uid.uidByte[i], HEX);
    conteudo.concat(String(sensor.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(sensor.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("Mensagem: ");
  conteudo.toUpperCase();

  if (conteudo.substring(1) == "ED 78 03 CA") {
    Serial.println("Ola Eric! ");
    Serial.println();
    delay(3000);
  }
}
