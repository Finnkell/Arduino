#define NOTE_E4  330
#define NOTE_CS4 277
#define NOTE_B4  494
#define NOTE_DS4 311
#define NOTE_B5  988
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415

int speaker = 8;

void setup() 
{
  pinMode(speaker, OUTPUT);
}

void loop() 
{
  for (int i = 0; i < 4; i++) {
    tone(speaker, NOTE_E4);
    delay(200);
    noTone(speaker);
    tone(speaker, NOTE_GS4);
    delay(250);
    noTone(speaker);
  }

  for (int i = 0; i < 2; i++) {
    tone(speaker, NOTE_E4);
    delay(300);
    tone(speaker, NOTE_DS4);
    delay(300);
    tone(speaker, NOTE_CS4);
    delay(300);
    tone(speaker, NOTE_B4);
    delay(300);
    tone(speaker, NOTE_B5);
	delay(500);
  }

  tone(speaker, NOTE_B4);
  delay(300);
  tone(speaker, NOTE_DS4);
  delay(300);
  tone(speaker, NOTE_FS4);
  delay(300);

  for (int i = 0; i < 6; i++) {
    tone(speaker, NOTE_B5);
    delay(200);
    noTone(speaker);
  }
  
  tone(speaker, NOTE_FS4);
  delay(300);
  tone(speaker, NOTE_G4);
  delay(300);
  tone(speaker, NOTE_GS4);
  delay(700);
}