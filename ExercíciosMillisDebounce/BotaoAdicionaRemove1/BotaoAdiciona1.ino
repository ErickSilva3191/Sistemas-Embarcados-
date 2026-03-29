/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: botão adiciona e remove 1 no monitor serial

Autor: Erick da Silva de Souza
Data: 29/03/2023
Versão: 1.0

************************************************************************ */

const int btMais = 2;
const int btMenos = 3;

int cont = 0;

//botao mais
bool leitura1;
bool ultimo1 = HIGH;
bool estadoEstavel1 = HIGH;
unsigned long tempo1 = 0;

//botão menos
bool leitura2;
bool ultimo2 = HIGH;
bool estadoEstavel2 = HIGH;
unsigned long tempo2 = 0;

const unsigned long debounce = 50;

void setup() {
  pinMode(btMais, INPUT_PULLUP);
  pinMode(btMenos, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

  //botao mais
  leitura1 = digitalRead(btMais);

  if (leitura1 != ultimo1) {
    tempo1 = millis();
  }

  if ((millis() - tempo1) > debounce) {
    if (leitura1 != estadoEstavel1) {
      estadoEstavel1 = leitura1;

      if (estadoEstavel1 == LOW) {
        cont++;
        Serial.println(cont);
      }
    }
  }

  ultimo1 = leitura1;

  //botao menos
  leitura2 = digitalRead(btMenos);

  if (leitura2 != ultimo2) {
    tempo2 = millis();
  }

  if ((millis() - tempo2) > debounce) {
    if (leitura2 != estadoEstavel2) {
      estadoEstavel2 = leitura2;

      if (estadoEstavel2 == LOW) {
        cont--;
        Serial.println(cont);
      }
    }
  }

  ultimo2 = leitura2;
}