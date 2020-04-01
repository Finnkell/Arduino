#define PIR 2
#define LED 7

void setup() {
  // put your setup code here, to run once:
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool valorPIR = digitalRead(PIR);

  if (!valorPIR) {
    digitalWrite(LED, HIGH);
  }else {
    digitalWrite(LED, LOW);
  }
}
