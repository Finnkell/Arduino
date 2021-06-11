#define NOTE_E4  330
#define NOTE_GS3 208
#define NOTE_F3  175
#define NOTE_G4  392
#define NOTE_DS4 311
#define NOTE_F4  349
#define NOTE_G3  196
#define NOTE_AS3 233
#define NOTE_C4  262
#define NOTE_D4  294

int speakerPin = 8;

void setup() 
{
    pinMode(speakerPin, OUTPUT);
}

void loop() 
{
  for(int i=0; i<4; i++) {
    tone(speakerPin, NOTE_G4);
    delay(500);
    noTone(speakerPin);

    tone(speakerPin, NOTE_C4);
    delay(500);
    noTone(speakerPin);

    tone(speakerPin, NOTE_DS4);
    delay(250);
    noTone(speakerPin);

    tone(speakerPin, NOTE_F4);
    delay(250);
    noTone(speakerPin);
  }

  for(int i=0; i<4; i++){
    tone(speakerPin, NOTE_G4);
    delay(500);
    noTone(speakerPin);

    tone(speakerPin, NOTE_C4);
    delay(500);
    noTone(speakerPin);

    tone(speakerPin, NOTE_E4);
    delay(250);
    noTone(speakerPin);

    tone(speakerPin, NOTE_F4);
    delay(250);
    noTone(speakerPin);
  }

  tone(speakerPin, NOTE_G4);
  delay(1500);
  noTone(speakerPin);

  tone(speakerPin, NOTE_C4);
  delay(1500);

  tone(speakerPin, NOTE_E4);
  delay(250);

  tone(speakerPin, NOTE_F4);
  delay(250);

  tone(speakerPin, NOTE_G4);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_C4);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_DS4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_F4);
  delay(250);
  noTone(speakerPin);
    
  for(int i=0; i<3; i++) {
    tone(speakerPin, NOTE_D4);
    delay(500);
    noTone(speakerPin);
    
    tone(speakerPin, NOTE_G3);
    delay(500);
    noTone(speakerPin);

    tone(speakerPin, NOTE_AS3);
    delay(250);
    noTone(speakerPin);

    tone(speakerPin, NOTE_C4);
    delay(250);
    noTone(speakerPin);
  }

  tone(speakerPin, NOTE_D4);
  delay(1500);
  noTone(speakerPin);
  
  tone(speakerPin, NOTE_F4);
  delay(1500);
  noTone(speakerPin);

  tone(speakerPin, NOTE_AS3);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_DS4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_D4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_F4);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_AS3);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_DS4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_D4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_C4);
  delay(500);
  noTone(speakerPin);

  for(int i=0; i<3; i++) {
	tone(speakerPin, NOTE_GS3);
	delay(250);
	noTone(speakerPin);

	tone(speakerPin, NOTE_AS3);
	delay(250);
	noTone(speakerPin);

	tone(speakerPin, NOTE_C4);
	delay(500);
	noTone(speakerPin);

	tone(speakerPin, NOTE_F3);
	delay(500);
	noTone(speakerPin);
  }

  tone(speakerPin, NOTE_G4);
  delay(1000); 
  noTone(speakerPin);

  tone(speakerPin, NOTE_C4);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_DS4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_F4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_G4);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_C4);
  delay(1000);
  noTone(speakerPin);

  tone(speakerPin, NOTE_DS4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_F4);
  delay(250);
  noTone(speakerPin);

  tone(speakerPin, NOTE_D4);
  delay(500);
  noTone(speakerPin);

  for(int i=0; i<4; i++) {
    tone(speakerPin, NOTE_G3);
    delay(500);
    noTone(speakerPin);

    tone(speakerPin, NOTE_AS3);
    delay(250);
    noTone(speakerPin);

    tone(speakerPin, NOTE_C4);
    delay(250);
    noTone(speakerPin);

    tone(speakerPin, NOTE_D4);
    delay(500);
    noTone(speakerPin);
  }
}