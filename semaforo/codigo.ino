void setup()
{
  pinMode(11, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(11, HIGH);
  delay(4000); // Espere por 4 segundo(s)
  digitalWrite(11, LOW);
  digitalWrite(1, HIGH);
  delay(4000); // Espere por 4 segundo(s)
  digitalWrite(1, LOW);
  digitalWrite(7, HIGH);
  delay(2000); // Espere por 2 segundo(s)
  digitalWrite(7, LOW);
}