const int pot = A0;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);
  float porcentagem = (valor / 1023.0) * 100.0;

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  if (porcentagem > 25) digitalWrite(led1, HIGH);
  if (porcentagem > 50) digitalWrite(led2, HIGH);
  if (porcentagem > 75) digitalWrite(led3, HIGH);
  if (porcentagem > 90) digitalWrite(led4, HIGH);
}