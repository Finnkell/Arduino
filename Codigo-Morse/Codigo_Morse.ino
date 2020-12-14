/* Objetivo: mandar mensagens por codigo morse com sinais de LED e Buzzer */

const int BUZZER = 8; // Porta do Buzzer
const int LED = 7;  // Porta do led

int botao = 6;  // Valor inicial nulo do botao
int push = 0; // Valor inicial da vaiavel como desligada

void setup() {
  pinMode(BUZZER, OUTPUT);  // Buzzer usa um pino de saida
  pinMode(LED, OUTPUT); // LED usa um pino de saida
  pinMode(botao, INPUT);  // Botao usa um pino de entrada
  Serial.begin(9600); // inicia a porta serial, configura a taxa de dados para 9600 bps
}

void loop() {
  push = digitalRead(botao);  // A variavel recebe o estado do botao
  
  if (push == HIGH) { // Se o botao estiver ativo
    Serial.println("True"); // Mostra a mensagem no terminal
    digitalWrite(LED, HIGH);  // Liga o LED
    digitalWrite(BUZZER, HIGH); // Liga o Buzzer
  } 
  
  else {  // Senao
    Serial.println("False");  // Mostra a mensagem no terminal
    digitalWrite(LED, LOW); // Desliga o LED
    digitalWrite(BUZZER, LOW);  // Desliga o Buzzer
  }
}
