const int pinoPotenciometro = A0;
const int botaoEmergencia = 2;

const int pinoMotor = 9;
const int ledStatus = 8;

bool falhaAtiva = false;

unsigned long tempoAnterior = 0;
bool estadoLed = false;

int estadoAnteriorBotao = HIGH;

void setup() {
  pinMode(botaoEmergencia, INPUT_PULLUP);
  pinMode(pinoMotor, OUTPUT);
  pinMode(ledStatus, OUTPUT);
}

void loop() {
  int estadoBotao = digitalRead(botaoEmergencia);
  int leituraPot = analogRead(pinoPotenciometro);
  unsigned long tempoAtual = millis();

  if (estadoAnteriorBotao == HIGH && estadoBotao == LOW) {
    falhaAtiva = true;
  }

  estadoAnteriorBotao = estadoBotao;

  if (falhaAtiva) {
    analogWrite(pinoMotor, 0);

    if (tempoAtual - tempoAnterior >= 300) {
      tempoAnterior = tempoAtual;
      estadoLed = !estadoLed;
      digitalWrite(ledStatus, estadoLed);
    }
  } else {
    int velocidade = map(leituraPot, 0, 1023, 0, 255);
    analogWrite(pinoMotor, velocidade);
    digitalWrite(ledStatus, LOW);
  }
}