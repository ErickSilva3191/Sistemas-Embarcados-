/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

led red liga se botao A e B forem ligados 
led green liga se A ou B forem ligados
led yellow liga se A xor B forem ligados

Autor: Erick da Silva de Souza
Data: 2/03/2023
Versão: 1.0

************************************************************************ */

const int ledRed = 7;		
const int ledGreen = 8;
const int ledYellow = 9;
const int pin_botaoA = 11;	
const int pin_botaoB = 12;

void setup() {
  pinMode(ledRed, OUTPUT);		
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(pin_botaoA, INPUT_PULLUP);
  pinMode(pin_botaoB, INPUT_PULLUP);
}

void loop() {
  int valorA = digitalRead(pin_botaoA);
  int valorB = digitalRead(pin_botaoB);
  if (valorA == LOW && valorB == LOW) {
    digitalWrite(ledRed, HIGH);
  } else {digitalWrite (ledRed, LOW);}
  if (valorA == LOW || valorB == LOW) {
    digitalWrite(ledGreen, HIGH);
  } else {
    digitalWrite (ledGreen, LOW);
    }
  if (valorA == valorB) {
    digitalWrite(ledYellow, LOW);
  } else {digitalWrite (ledYellow, HIGH);}
}
