int ledPin = 13;
int inPin = 2;
int ledState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(inPin)){
    Serial.println(digitalRead(inPin));
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(200);

    if (ledState == 1) {
      digitalWrite(ledPin, HIGH);
    }else {
      digitalWrite(ledPin, LOW);
    }
  }

  
}
