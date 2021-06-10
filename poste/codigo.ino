void setup()
{
  pinMode(A5, INPUT);
  Serial.begin(9600);

  pinMode(2, OUTPUT);
}

void loop()
{
  Serial.println(analogRead(A5));
  if (analogRead(A5) > 85) { // O valor deve mudar de acordo com a luminosidade do local
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  delay(10);
}