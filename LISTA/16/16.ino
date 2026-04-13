const int ntc = A0;

const int exaustor = 9;
const int ledMax = 8;

void setup() {
  pinMode(exaustor, OUTPUT);
  pinMode(ledMax, OUTPUT);
}

void loop() {
  int leitura = analogRead(ntc);

  float temp = (leitura / 1023.0) * 100.0;

  int pwm = 0;

  if (temp < 30) {
    pwm = 51;
    digitalWrite(ledMax, LOW);
  }
  else if (temp <= 60) {
    pwm = map(temp, 30, 60, 51, 255);
    digitalWrite(ledMax, LOW);
  }
  else {
    pwm = 255;
    digitalWrite(ledMax, HIGH);
  }

  analogWrite(exaustor, pwm);
}