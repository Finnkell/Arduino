void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  for(int i = 0; i <= 10; i++) {
    analogWrite(A0, (int)rand() % 1023);
    analogWrite(A1, (int)rand() % 1023);
    analogWrite(A2, (int)rand() % 1023);
    delay(300);
 }
}
