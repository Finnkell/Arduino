/* Objetivo: teste do potenciometro utilizando led */

// Portas utilizadas
int pont = A0;
int Led = A1;

// Valor inicial do penciometro
int state = 0;

void setup() {
  pinMode(pont, INPUT); // Potencimetro como entrada
  pinMode(Led, OUTPUT); // LED como saida
  Serial.begin(9600); // Inicia a porta serial, configura a taxa de dados para 9600 bps
}

void loop() {
  state = analogRead(pont); // variavel receba valor do potenciometro
  Serial.println(state);  // Mostra o valor no terminal
  analogWrite(Led, state);  // led acende de acordo com o valor do potenciometro
}
