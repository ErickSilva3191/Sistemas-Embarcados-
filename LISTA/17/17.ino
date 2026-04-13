const int A = 2;
const int B = 3;
const int esteira = 8;

int caixas = 0;
int lote = 0;

bool ligada = false;
unsigned long tempoPausa = 0;

int antA = HIGH;
int antB = HIGH;

void setup() {
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(esteira, OUTPUT);
}

void loop() {
  int a = digitalRead(A);
  int b = digitalRead(B);
  unsigned long t = millis();

  if (antA == HIGH && a == LOW) {
    if (caixas >= 20) {
      caixas = 0;
      lote = 0;
    }
    ligada = true;
  }

  if (ligada && antB == HIGH && b == LOW) {
    caixas++;
    lote++;

    if (lote == 5) {
      ligada = false;
      tempoPausa = t;
      lote = 0;
    }
  }

  if (!ligada && t - tempoPausa >= 3000 && caixas < 20) {
    ligada = true;
  }

  if (caixas >= 20) ligada = false;

  digitalWrite(esteira, ligada);

  antA = a;
  antB = b;
}