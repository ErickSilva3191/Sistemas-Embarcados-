const int ntc = A0;
const int led4 = 11;

const int limite = 600;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 100;

bool estadoLed = false;

void setup() {
  pinMode(led4, OUTPUT);
}

void loop() {
  int valor = analogRead(ntc);
  unsigned long tempoAtual = millis();

  if (valor > limite) {
    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      estadoLed = !estadoLed;
      digitalWrite(led4, estadoLed);
    }
  } else {
    digitalWrite(led4, LOW);
    estadoLed = false;
  }
}