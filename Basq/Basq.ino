int Basquete = A0;
int Motor = 7;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Basquete, INPUT);  
  pinMode(Motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Basquete = analogRead(A0);
  Serial.println(Basquete);
  
  state = Basquete;
//  digitalWrite(Led, state);

  if (Basquete >= 10) {
    digitalWrite(Motor, HIGH);
  }
}
