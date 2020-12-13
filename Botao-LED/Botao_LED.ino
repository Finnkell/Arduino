/* Objetivo: ligar o led quando o botao for acionado */

int ledPin = 13;  // Porta de energia do LED
int inPin = 2;    // Porta de energia botao
int ledState = 0; // Estado inicial do led [deligado]

void setup() {
  pinMode(ledPin, OUTPUT);  // Configurando porta do led como saida
  pinMode(inPin, INPUT);  // Configurando porta do botao como entrada
  Serial.begin(9600); // Inicia a porta serial, configura a taxa de dados para 9600 bps
}

void loop() {
  if (digitalRead(inPin)) { // Se houver mudanca no estado do botao
    Serial.println(digitalRead(inPin)); // Mostra o valor da variavel no terminal

    ledState = !ledState; // A variavel do led recebe um valor diferente do atual
    
    digitalWrite(ledPin, ledState); // Ligar ou desligar o LED
    delay(200); // Espera em milissegundos

    if (ledState == 1) {  // Se o estado do botao for ativo 
      digitalWrite(ledPin, HIGH); // Ligar o LED
    }
    
    else {  // Senao
      digitalWrite(ledPin, LOW);  // Ligar o LED
    }
  }
}
