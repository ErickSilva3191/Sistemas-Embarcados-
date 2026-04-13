const int pinoSensor = A0;

const int pinoLedBaixo = 8;
const int pinoLedMedio = 9;
const int pinoLedAlto = 10;
const int pinoLedAlerta = 11;

unsigned long tempoAnterior = 0;
bool estadoAlerta = false;

void setup() {
  pinMode(pinoLedBaixo, OUTPUT);
  pinMode(pinoLedMedio, OUTPUT);
  pinMode(pinoLedAlto, OUTPUT);
  pinMode(pinoLedAlerta, OUTPUT);
}

void loop() {
  int leitura = analogRead(pinoSensor);
  unsigned long tempoAtual = millis();

  digitalWrite(pinoLedBaixo, LOW);
  digitalWrite(pinoLedMedio, LOW);
  digitalWrite(pinoLedAlto, LOW);

  if (leitura < 300) {
    digitalWrite(pinoLedBaixo, HIGH);
  }
  else if (leitura < 700) {
    digitalWrite(pinoLedMedio, HIGH);
  }
  else {
    digitalWrite(pinoLedAlto, HIGH);
  }

  if (leitura < 150 || leitura > 900) {
    if (tempoAtual - tempoAnterior >= 300) {
      tempoAnterior = tempoAtual;
      estadoAlerta = !estadoAlerta;
      digitalWrite(pinoLedAlerta, estadoAlerta);
    }
  } else {
    digitalWrite(pinoLedAlerta, LOW);
  }
}