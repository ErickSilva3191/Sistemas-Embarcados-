const int botaoA = 2;
const int botaoB = 3;

const int led1 = 8;
const int ledErro = 11;

unsigned long tempoA = 0;
unsigned long tempoB = 0;

int estadoAnteriorA = HIGH;
int estadoAnteriorB = HIGH;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(ledErro, OUTPUT);
}

void loop() {
  int A = digitalRead(botaoA);
  int B = digitalRead(botaoB);
  unsigned long tempoAtual = millis();

  if (estadoAnteriorA == HIGH && A == LOW) {
    tempoA = tempoAtual;
  }

  if (estadoAnteriorB == HIGH && B == LOW) {
    tempoB = tempoAtual;
  }

  estadoAnteriorA = A;
  estadoAnteriorB = B;

  if (tempoA != 0 && tempoB != 0) {
    if ((tempoA > tempoB && tempoA - tempoB <= 500) ||
        (tempoB > tempoA && tempoB - tempoA <= 500)) {
      digitalWrite(led1, HIGH);
      digitalWrite(ledErro, LOW);
    } else {
      digitalWrite(led1, LOW);
      digitalWrite(ledErro, HIGH);
    }

    tempoA = 0;
    tempoB = 0;
  }
}