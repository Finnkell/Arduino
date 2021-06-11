void setup()
{
  pinMode(A5, INPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  analogWrite(5, analogRead(A5));
  delay(10);
}