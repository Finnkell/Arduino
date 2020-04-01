int pont = A0;
int state = 0;
int Led = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(pont, INPUT);
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = analogRead(pont);
  Serial.println(state);
  analogWrite(Led, state);
}
