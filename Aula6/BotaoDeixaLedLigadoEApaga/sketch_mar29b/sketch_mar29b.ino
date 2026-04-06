/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: led liga por botao e fica aceso ate o botao ser clicado de novo

Autor: Erick da Silva de Souza
Data: 29/03/2023
Versão: 1.0

************************************************************************ */
const int bt = 2;
const int led = 8;

bool leitura;
bool ultimo = HIGH;
bool estadoEstavel = HIGH;

bool estadoLed = false;

unsigned long tempo = 0;
const unsigned long debounce = 50;

void setup() {
  pinMode(bt, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  leitura = digitalRead(bt);

  
  if (leitura != ultimo) {
    tempo = millis();
  }

  // verifica debounce
  if ((millis() - tempo) > debounce) {

    
    if (leitura != estadoEstavel) {
      estadoEstavel = leitura;

    
      if (estadoEstavel == LOW) {
        estadoLed = !estadoLed; // alterna LED
      }
    }
  }

  digitalWrite(led, estadoLed);

  ultimo = leitura;
}