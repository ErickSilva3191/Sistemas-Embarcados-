const int sensor = A0;

const int valvula = 8;
const int alarme = 11;

bool travado = false;

unsigned long tempoAnterior = 0;
bool estadoAlarme = false;

void setup() {
  pinMode(valvula, OUTPUT);
  pinMode(alarme, OUTPUT);
}

void loop() {
  int leitura = analogRead(sensor);
  float nivel = (leitura / 1023.0) * 100.0;

  unsigned long tempoAtual = millis();

  if (nivel >= 95) travado = true;
  if (nivel < 30) travado = false;

  if (!travado && nivel < 80) digitalWrite(valvula, HIGH);
  else digitalWrite(valvula, LOW);

  if (travado) {
    if (tempoAtual - tempoAnterior >= 300) {
      tempoAnterior = tempoAtual;
      estadoAlarme = !estadoAlarme;
      digitalWrite(alarme, estadoAlarme);
    }
  } else {
    digitalWrite(alarme, LOW);
  }
}