const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

int indice = 0;
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 200;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

    if (indice == 0) digitalWrite(led1, HIGH);
    if (indice == 1) digitalWrite(led2, HIGH);
    if (indice == 2) digitalWrite(led3, HIGH);
    if (indice == 3) digitalWrite(led4, HIGH);

    indice++;
    if (indice > 3) indice = 0;
  }
}