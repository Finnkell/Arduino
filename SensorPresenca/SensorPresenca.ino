#define PIR 7
#define Buzzer 5

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
}

void loop() {
  bool valorPIR = digitalRead(PIR);

  if (valorPIR) {
    tone(Buzzer, 100);
    delay(1000);
    noTone(Buzzer);
    Serial.println("*******");
  }else {
    Serial.println("-------");
  }
}
