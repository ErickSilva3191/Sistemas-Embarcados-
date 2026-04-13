const int pot = A0;

const int led1 = 9;
const int led2 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);

  if (valor < 512) {
    int brilho1 = map(valor, 511, 0, 0, 255);
    analogWrite(led1, brilho1);
    analogWrite(led2, 0);
  } else {
    int brilho2 = map(valor, 512, 1023, 0, 255);
    analogWrite(led2, brilho2);
    analogWrite(led1, 0);
  }
}