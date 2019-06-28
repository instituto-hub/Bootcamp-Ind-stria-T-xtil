                                /*
LilyPad Temperature Sensor Example
SparkFun Electronics
https://www.sparkfun.com/products/8777

This code reads the input of the temperature sensor, converts it to Farenheit and Celsius
and prints to the Serial Monitor.

Temperature sensor connections:
   * S tab to A3
   * + tab to A5 (or +)
   * - tab to -

Follow the tutorial at:
https://learn.sparkfun.com/tutorials/lilypad-temperature-sensor-hookup-guide

This code is released under the MIT License (http://opensource.org/licenses/MIT)
******************************************************************************/

// Connect the S tab of the Temperature Sensor to A3
// If using the LilyPad ProtoSnap Plus, change to A9
 int sensorPin = A3;  
// int led1 = 8;
//int led2 = 9;
 int led3 = 13;
  float i=0;
  float soma=0;
  float med=0;
  
void piscarLed(int tempo,int pino){
  
  digitalWrite(pino,HIGH);
  delay (tempo);
  digitalWrite(pino,LOW);
  delay (tempo);
}
  
void setup()
{

  // Set the temperature sensor pin as an INPUT:
  pinMode(sensorPin, INPUT);
  pinMode(led3, OUTPUT);

  // Initialize Serial, set the baud rate to 9600 bps.
  Serial.begin(9600);
}

void loop()
{
  i++;
  
  // Variable to store raw temperature
  long rawTemp;

  // Variable to store voltage calculation
  float voltage;

  // Variable to store Celsius value
  float celsius;

  // Read the raw 0-1023 value of temperature into a variable.
  rawTemp = analogRead(sensorPin);

  // Calculate the voltage, based on that value.
  // Multiply by maximum voltage (3.3V) and divide by maximum ADC value (1023).
  // If you plan on using this with a LilyPad Simple Arduino on USB power, change to 4.2
  voltage = rawTemp * (5.0 / 1023.0);

  // Calculate the celsius temperature, based on that voltage..
  celsius = (voltage - 0.5) * 100;
  Serial.print("Celsius: "); // Print celcius temp to serial monitor
  Serial.println(celsius);  
   
  soma = celsius+soma;
  med = soma/i;

  Serial.print("med: "); // Print voltage reading to serial monitor
  Serial.println(med);
  // Wait 1 second between readings

if(med < 36.8){
  piscarLed(1000,led3);
    }
    
else if(med>36.8 && med<37.8){
  piscarLed(600,led3);
    }

else if(med>37.8)
  digitalWrite(led3,HIGH);
else
    digitalWrite(led3,LOW);

}
