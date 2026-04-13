const int botaoA = 2;
const int led1 = 8;
const int led2 = 9;

unsigned long tempoPressionado = 0;
bool pressionando = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int estado = digitalRead(botaoA);
  unsigned long tempoAtual = millis();

  if (estado == LOW && !pressionando) {
    pressionando = true;
    tempoPressionado = tempoAtual;
  }

  if (estado == HIGH && pressionando) {
    unsigned long duracao = tempoAtual - tempoPressionado;
    pressionando = false;

    if (duracao < 1000) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    } else if (duracao > 2000) {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
    }
  }
}