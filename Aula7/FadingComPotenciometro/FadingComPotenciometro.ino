int ledPin = 9;
int potPin=A0;
void setup() {
  digitalWrite(ledPin, OUTPUT);
}
void loop() {
  int valor=analogRead(potPin);
  int valorF=(valor/4);
  analogWrite(ledPin, valorF);
}