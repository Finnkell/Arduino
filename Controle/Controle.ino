#include <IRremote.h>

int LED1 = 10;
int LED2 = 11;
int LED3 = 12;

float valor;
int reciever = 7;

IRrecv controle(reciever);
decode_results results;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
  controle.enableIRIn();
}

void loop() {
  if (controle.decode(&results)){
    Serial.print("Valor: ");
    Serial.println(results.value, HEX);

    valor = results.value;

    if (valor == 0xFFA25D) {
      digitalWrite(LED1, HIGH);
    }
    
    if (valor == 0xFF629D) {
      digitalWrite(LED2, HIGH);
    }

    if (valor == 0xFFE21D) {
      digitalWrite(LED3, HIGH);
    }
    
    if (valor == 0xFF22DD) {
      digitalWrite(LED1, LOW);
    }

    if (valor == 0xFF02FD) {
      digitalWrite(LED2, LOW);
    }

    if (valor == 0xFFC23D) {
      digitalWrite(LED3, LOW);
    }    

    controle.resume();
  }
}
