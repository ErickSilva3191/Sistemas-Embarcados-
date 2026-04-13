const int pot = A0;
const int led = 9;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 500;

bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);
  float tensao = valor * (5.0 / 1023.0);

  unsigned long tempoAtual = millis();

  if (tensao <= 2.0) {
    digitalWrite(led, LOW);
  }
  else if (tensao < 4.0) {
    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  }
  else {
    digitalWrite(led, HIGH);
  }
}