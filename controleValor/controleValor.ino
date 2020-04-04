#include <IRremote.h>

int reciever = 13;

IRrecv controle(reciever);
decode_results results;

void setup() {
  controle.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if (controle.decode(&results)) {
    Serial.println(results.value, HEX);
    controle.resume();
  }
}
