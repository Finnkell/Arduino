#define pinButton1 13
#define pinLED1 10
#define Buzzer 6

#define pinButton2 12
#define pinLED2 9

bool pinButton1Ret();
bool pinButton2Ret();

void setup() {
    pinMode(pinButton1, INPUT_PULLUP);
    pinMode(pinButton2, INPUT_PULLUP);
    pinMode(pinLED1, OUTPUT);
    pinMode(pinLED2, OUTPUT);
    pinMode(Buzzer, OUTPUT);
}

void loop() {
    if (digitalRead(pinButton1) == LOW) {
        digitalWrite(pinLED1, HIGH);
        digitalWrite(Buzzer, HIGH);
    }else {
        digitalWrite(pinLED1, LOW);
        digitalWrite(Buzzer, LOW);
    }

    if (pinButton2Ret()) {
        digitalWrite(pinLED2, HIGH);
    }else {
        digitalWrite(pinLED2, LOW);
    }    
}

bool pinButton1Ret() {
    #define tempoDebounce 50 //(tempo para eliminar o bounce, milisegundos)

    bool ButtonState;
    static bool ButtonStateAnt;
    static bool RetState = true;
    static unsigned long delayButton = 0;

    if ((millis() - delayButton) > tempoDebounce) {
        ButtonState = digitalRead(pinButton1);
        if (ButtonState && (ButtonState != ButtonStateAnt)) {
            RetState = !RetState;
            delayButton = millis();
        }
        ButtonStateAnt = ButtonState;
    }

    return RetState;
    
}

bool pinButton2Ret() {
    #define tempoDebounce 50 //(tempo para eliminar o bounce, milisegundos)

    bool ButtonState;
    static bool ButtonStateAnt;
    static bool RetState = true;
    static unsigned long delayButton = 0;

    if ((millis() - delayButton) > tempoDebounce) {
        ButtonState = digitalRead(pinButton2);
        if (ButtonState && (ButtonState != ButtonStateAnt)) {
            RetState = !RetState;
            delayButton = millis();
        }
        ButtonStateAnt = ButtonState;
    }

    return RetState;
    
}
