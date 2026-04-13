const int botaoA = 2;
const int botaoB = 3;
const int led1 = 8;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  int estadoA = digitalRead(botaoA);
  int estadoB = digitalRead(botaoB);

  if (estadoA == LOW && estadoB == LOW) {
    digitalWrite(led1, HIGH);
  } 
  else {
    digitalWrite(led1, LOW);
  }
}