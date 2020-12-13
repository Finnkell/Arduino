/* Objetivo: ligar o led quando o valor do sensor luminoso [LDR] for menor que 100 */

int ledPin = 7;   // Porta de energia do LED
int ldrPin = 0;   // Porta do sensor luminoso [LDR]
int ldrValor = 0; // Valor inicial do sensor luminoso [LDR]

void setup() {
  pinMode(ledPin, OUTPUT);  // Configurando porta do led como saida
  Serial.begin(9600); // inicia a porta serial, configura a taxa de dados para 9600 bps
}

void loop() {
  ldrValor = analogRead(lrdPin);  // A variavel recebe o valor do sensor luminoso

  if (ldrValor <= 100) {  // Se o valor da variavel for menor ou igual que 100
    digitalWrite(ledPin, HIGH); // Liga o LED
  }

  else {  // Senao
    digitalWrite(ledPin, LOW);  // Desliga o LED
  }

  Serial.println(ldrValor); // Mostra o valor da variavel no terminal

  delay(100); // Espera em milissegundos
}
