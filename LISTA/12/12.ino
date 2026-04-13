const int botao1 = 2;
const int botao2 = 3;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

int etapa = 0;
unsigned long tempoAnterior = 0;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  int b1 = digitalRead(botao1);
  int b2 = digitalRead(botao2);
  unsigned long tempoAtual = millis();

  if (b1 == LOW && etapa == 0) {
    etapa = 1;
    tempoAnterior = tempoAtual;
  }

  if (b2 == LOW) {
    etapa = 0;
  }

  if (etapa > 0 && etapa < 4 && tempoAtual - tempoAnterior >= 1000) {
    tempoAnterior = tempoAtual;
    etapa++;
  }

  digitalWrite(led1, etapa >= 1);
  digitalWrite(led2, etapa >= 2);
  digitalWrite(led3, etapa >= 3);
  digitalWrite(led4, etapa >= 4);
}