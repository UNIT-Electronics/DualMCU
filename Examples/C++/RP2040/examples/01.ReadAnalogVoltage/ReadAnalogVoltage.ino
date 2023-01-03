/*
Unit Electronics 2022
ADC
Obtain the read on ADC Port from RP2040.
Analog signal is connected to GPIO 26,27,28 or 29  (Analogs A0,A1,A2,A3) 
*/
const int potPin = A3;
// variable for storing the potentiometer value
float voltage_write = 0;
//Convert the input read on ADC pin in Voltagec(3.3V / 2^12)
float conversion_factor = 3.3 / 1024;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value and obtain the equivalent voltage
  voltage_write = analogRead(potPin) * conversion_factor;
  
  Serial.println(voltage_write);
  delay(500);
}
