const int BUZZER = 8;
const int LED = 7;

int botao = 6;
int push = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
