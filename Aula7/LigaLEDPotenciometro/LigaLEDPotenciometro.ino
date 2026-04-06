int pin_sensor = A0;
int valor=0;
int led1=9;
int led2=10;
int led3=11;
void setup(){ 
  pinMode(pin_sensor, INPUT);
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  valor=analogRead(pin_sensor);
  Serial.println(valor);
  delay(200);
  if (valor<204){
    digitalWrite(led1, LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3, LOW);
  }
  if (204<=valor && valor<408){
    digitalWrite(led1, HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3, LOW);
  }
  if (408<=valor && valor<612){
    digitalWrite(led1, LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3, LOW);
  }
  if (612<=valor && valor<816){
    digitalWrite(led1, LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3, HIGH);
  }
  if (816<=valor){
    digitalWrite(led1, HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3, HIGH);
  }
}