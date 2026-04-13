const int botao1 = 2;
const int botao3 = 3;
const int led1 = 8;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  int estado1 = digitalRead(botao1);
  int estado3 = digitalRead(botao3);

  if (estado1 == LOW && estado3 == LOW) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}