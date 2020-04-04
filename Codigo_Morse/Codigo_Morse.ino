const int BUZZER = 8;
const int LED = 7;

int botao = 6;
int push = 0;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
  push = digitalRead(botao);
  
  if (push == HIGH) {
    Serial.println("True");
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    Serial.println("False");
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
}
