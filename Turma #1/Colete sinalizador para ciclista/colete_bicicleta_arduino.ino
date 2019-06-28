/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

int direita = 0;
int esquerda = 0;
int freio = 0;
int direitaLast = 0;
int esquerdaLast = 0;
int freioLast = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(10, INPUT);
  
  pinMode(8, INPUT);
  Serial.begin(9600);
  
}

// the loop function runs over and over again forever
void loop() {
  esquerda = analogRead(A3);
  direita = analogRead(A4);
  freio = analogRead(A2);
  Serial.println(esquerda);
  Serial.println(direita);
  Serial.println(freio);
  
 if (esquerda != esquerdaLast) {
    // if the state has changed, increment the counter
    if (esquerda >= 1000) {
    digitalWrite(2, HIGH);  
    delay(500);    
    digitalWrite(2, LOW); 
    delay(500); 


    
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("Esquerda off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  esquerdaLast = esquerda;

 if (freio != freioLast) {
    // if the state has changed, increment the counter
    if (freio == 0) {
    analogWrite(A2, 255);  
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("freio off");
      analogWrite(A2, 0);  
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  freioLast = freio;

   if (direita != direitaLast) {
    // if the state has changed, increment the counter
    if (direita == 0) {
    analogWrite(A3, 255);  
    delay(500);    
    analogWrite(A3, 0); 
    delay(500); 
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("direita off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  direitaLast = direita;

}

