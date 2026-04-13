const int pot = A0;
const int led3 = 10;

void setup() {
  pinMode(led3, OUTPUT);
}

void loop() {
  long soma = 0;

  for (int i = 0; i < 10; i++) {
    soma = soma + analogRead(pot);
    delay(10);
  }

  int media = soma / 10;

  if (media > 700) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
}