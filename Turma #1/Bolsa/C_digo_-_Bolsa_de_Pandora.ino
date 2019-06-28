float lumen = 100;
int leitura = 0;
int ligado = true;


void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), muda, FALLING);
  Serial.begin(9600);

}

void loop()
{
//digitalWrite(2, HIGH); Teste
//analogWrite(2, lumen); Tetse
  
  if ((digitalRead(4) != 1) & (ligado == HIGH)){
  leitura = analogRead(A0);
    lumen = map(leitura, 0, 1023, 255, 0);
    analogWrite(2, lumen); 
  }
  else {
  digitalWrite(2, LOW);  
  }
  Serial.println("Circuito: ");
  Serial.print(ligado);
  Serial.println("Fecho: ");
  Serial.print(digitalRead(4));
  Serial.println("Valor do Sensor de Luz: ");
  Serial.print(leitura);
  Serial.println("Valor da Luminosidade: ");
  Serial.print(lumen);
  
  delay(3000); // Wait for 300 millisecond(s)*/
}

void muda(){
ligado = !ligado;
delay(10);  
}
