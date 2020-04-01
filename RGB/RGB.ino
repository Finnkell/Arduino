int ledPin = 7;
int ldrPin = 0;
int ldrValor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ldrValor = analogRead(lrdPin);

  if (ldrValor <= 100) {
    digitalWrite(ledPin, HIGH);
  }else {
    digitalWrite(ledPin, LOW);
  }

  Serial.println(ldrValor);
  delay(100);
}
