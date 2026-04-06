int pin_sensor = A0;
int valor=0;
void setup(){ 
  pinMode(pin_sensor, INPUT);
  Serial.begin(115200);

}

void loop() {
  valor=analogRead(pin_sensor);
  Serial.println(valor);
  delay(200);
}