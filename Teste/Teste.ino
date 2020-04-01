#include <NewPing.h>

#define T1 13
#define E1 12
#define T2 10
#define E2 9
#define T3 7
#define E3 6

NewPing S1(T1,E1,500);
NewPing S2(T2,E2,500);
NewPing S3(T3,E3,500);

int distancia1 = 0;
int distancia2 = 0;
int distancia3 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  distancia1 = S1.ping_cm();
  Serial.println(distancia1);
  distancia2 = S2.ping_cm();
  Serial.println(distancia2);
  distancia3 = S3.ping_cm();
  Serial.println(distancia3);
  delay(200);
}
