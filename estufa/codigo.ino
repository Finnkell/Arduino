void setup()
{
  pinMode(A5, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  if (-40 + 0.488155 * (analogRead(A5) - 20) > 20) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
  if (-40 + 0.488155 * (analogRead(A5) - 20) >= 10 && -40 + 0.488155 * (analogRead(A5) - 20) <= 20) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  if (-40 + 0.488155 * (analogRead(A5) - 20) < 10) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  delay(10);
}