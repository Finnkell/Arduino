#include <Servo.h>
#include <NewPing.h>

#define M 13
#define TRIGGER1 8
#define TRIGGER2 3
#define ECHO1 9
#define ECHO2 2

#define SOBE 0
#define DESCE 90

Servo servo;
NewPing sonar1(TRIGGER1, ECHO1, 10);
NewPing sonar2(TRIGGER2, ECHO2, 10);

int valorSonar1 = 0;
int valorSonar2 = 0;

void setup() {
  servo.attach(M);
  Serial.begin(9600);
  servo.write(DESCE);
}

void loop() {
  valorSonar1 = sonar1.ping_cm();
  valorSonar2 = sonar2.ping_cm();

  do {
    if (valorSonar1 != 0 && valorSonar2 != 0) {
      servo.write(SOBE);
    }
    valorSonar1 = sonar1.ping_cm();
    valorSonar2 = sonar2.ping_cm();
    delay(1000);
  } while (valorSonar1 != 0);

  servo.write(DESCE);

}
