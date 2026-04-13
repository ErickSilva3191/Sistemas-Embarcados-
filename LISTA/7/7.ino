const int pot = A0;
const int led2 = 9;

unsigned long tempoAnterior = 0;
unsigned long intervalo = 1000;

bool estadoLed = false;

void setup() {
  pinMode(led2, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);

  intervalo = map(valor, 0, 1023, 2000, 100);

  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;
    estadoLed = !estadoLed;
    digitalWrite(led2, estadoLed);
  }
}