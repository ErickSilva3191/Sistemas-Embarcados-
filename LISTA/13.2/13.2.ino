const int pinoNTC = A0;
const int pinoLed = 9;

void setup() {
  pinMode(pinoLed, OUTPUT);
}
void loop() {
  int leitura = analogRead(pinoNTC);
  int pwm = map(leitura, 0, 1023, 0, 255);
  analogWrite(pinoLed, pwm);
}