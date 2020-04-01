void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  analogWrite(A0, 1000);
//  analogWrite(A1, 500);
//  analogWrite(A2, 300);
//  delay(1000);
//  
//  analogWrite(A0, 0);
//  analogWrite(A1, 0);
//  analogWrite(A2, 0);
//  delay(500);
//
//  analogWrite(A0, 100);
//  analogWrite(A1, 50);
//  analogWrite(A2, 0);
//  delay(1000);
//
//  analogWrite(A0, 0);
//  analogWrite(A1, 0);
//  analogWrite(A2, 0);
//  delay(500);
//
//  analogWrite(A0, 100);
//  analogWrite(A1, 0);
//  analogWrite(A2, 30);
//  delay(1000);
//
//  analogWrite(A0, 0);
//  analogWrite(A1, 0);
//  analogWrite(A2, 0);
//  delay(500);

  for(int i = 0; i <= 10; i++) {
    analogWrite(A0, (int)rand() % 1023);
    analogWrite(A1, (int)rand() % 1023);
    analogWrite(A2, (int)rand() % 1023);
    delay(300);
 }
}
