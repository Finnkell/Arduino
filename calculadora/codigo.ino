#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

const byte lin = 4;
const byte col = 4;

char Teclado [lin][col] = {{'1', '2', '3', 'A'},
                           {'4', '5', '6', 'B'},
                           {'7', '8', '9', 'C'},
                           {'*', '0', '#', 'D'}};

byte pinLin[lin] = {7, 6, 5, 4};
byte pinCol[col] = {3, 2, 1, 0};

Keypad keyp = Keypad(makeKeymap(Teclado), pinLin, pinCol, lin, col);

bool inicio = true, final = false, numDigitado = false;

String num1, num2;
int resultado;
char op;

void setup()
{
  lcd.begin(15,2);
}

void loop()
{
  char key = keyp.getKey();
  
  if(key != NO_KEY && ( key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0')) {
    if(inicio) { 
      num1 = num1 + key;
      lcd.setCursor(0, 0);
      lcd.print(num1);
      numDigitado = true;
    }
    
    else {
      num2 = num2 + key;
      lcd.setCursor(0, 1);
      lcd.print(num2);
      final = true;
    }
  }
  
  if (inicio && numDigitado == 1 && key != NO_KEY && (key == 'A' || key == 'B' || key == 'C' || key == 'D')) {
    inicio = false;  
    op = key;
    char printOp;

    if(op == 'A') {
      printOp = '+';
    }

    if(op == 'B') {
      printOp = '-';
    }
    
    if(op=='C') {
      printOp = 'x';
    }

    if(op=='D') {
      printOp = '/';
    }

    lcd.setCursor(15, 0);
    lcd.print(printOp);

    numDigitado = false;
  }

  if(final && key !=NO_KEY && key == '#') {
    if(op == 'A') {
      resultado = num1.toInt() + num2.toInt();
    }

    if(op == 'B') {
      resultado = num1.toInt() - num2.toInt();
    }

    if(op == 'C') {
      resultado = num1.toInt() * num2.toInt();
    }

    if(op == 'D') {
      resultado = num1.toInt() / num2.toInt();
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("=");

    lcd.setCursor(1, 0);
    lcd.print((int)resultado);
  }

  if(key != NO_KEY && key == '*') {
    inicio = true;
    final = false;
    numDigitado = false;
    num1 = "";
    num2 = "";
    resultado = 0;
    op = ' ';
    lcd.clear();
  }
}