int botao = 0;

void setup()
{
  pinMode(5, INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  if (digitalRead(5) == HIGH) {
    if (botao == 1) {
      botao = 0;
      digitalWrite(10, LOW);
    } else {
      botao = 1;
      digitalWrite(10, HIGH);
    }
  }
  delay(100); // Espere por 100 milissegundo(s)
}