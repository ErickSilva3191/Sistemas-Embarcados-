const int pinoBotaoA = 2;
const int pinoSensorNTC = A0;

const int pinoAquecimento = 8;
const int pinoLedFaixa = 9;

bool sistemaLigado = false;
bool aquecendo = false;

int estadoAnteriorBotao = HIGH;

void setup() {
  pinMode(pinoBotaoA, INPUT_PULLUP);
  pinMode(pinoAquecimento, OUTPUT);
  pinMode(pinoLedFaixa, OUTPUT);
}

void loop() {
  int estadoBotao = digitalRead(pinoBotaoA);
  int leituraNTC = analogRead(pinoSensorNTC);

  if (estadoAnteriorBotao == HIGH && estadoBotao == LOW) {
    sistemaLigado = true;
    aquecendo = true;
  }

  estadoAnteriorBotao = estadoBotao;

  if (sistemaLigado) {
    if (leituraNTC >= 820) aquecendo = false;
    if (leituraNTC <= 770) aquecendo = true;

    digitalWrite(pinoAquecimento, aquecendo);

    if (leituraNTC >= 770 && leituraNTC <= 820) {
      digitalWrite(pinoLedFaixa, HIGH);
    } else {
      digitalWrite(pinoLedFaixa, LOW);
    }
  } else {
    digitalWrite(pinoAquecimento, LOW);
    digitalWrite(pinoLedFaixa, LOW);
  }
}