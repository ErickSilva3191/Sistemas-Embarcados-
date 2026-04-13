const int botaoA = 2;
const int led1 = 9;

int estadoBotaoAnterior = HIGH;
int nivel = 0;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  int estadoBotaoAtual = digitalRead(botaoA);

  if (estadoBotaoAnterior == HIGH && estadoBotaoAtual == LOW) {
    nivel++;
    if (nivel > 4) nivel = 0;
  }

  estadoBotaoAnterior = estadoBotaoAtual;

  int brilho = nivel * 255 / 4;
  analogWrite(led1, brilho);
}