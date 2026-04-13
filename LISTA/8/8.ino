const int botaoA = 2;
const int botaoB = 3;
const int led1 = 8;

unsigned long tempoInicio = 0;
bool ledLigado = false;

int estadoAnteriorA = HIGH;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  int estadoA = digitalRead(botaoA);
  int estadoB = digitalRead(botaoB);
  unsigned long tempoAtual = millis();

  if (estadoAnteriorA == HIGH && estadoA == LOW) {
    ledLigado = true;
    tempoInicio = tempoAtual;
    digitalWrite(led1, HIGH);
  }

  estadoAnteriorA = estadoA;

  if (ledLigado && estadoB == LOW) {
    ledLigado = false;
    digitalWrite(led1, LOW);
  }

  if (ledLigado && (tempoAtual - tempoInicio >= 5000)) {
    ledLigado = false;
    digitalWrite(led1, LOW);
  }
}