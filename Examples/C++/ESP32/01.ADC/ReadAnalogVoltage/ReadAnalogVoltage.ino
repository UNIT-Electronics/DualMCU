/* 
 *  UNIT Electronics 2022
 *  ADC
 *  Potentiometer is connected to GPIO 04 (Analog ADC2_CH0) */
 
const int potPin = 4;
// variable for storing the potentiometer value
float voltage_write = 0;
//Convert the input read on ADC pin in Voltagec(3.3V / 2^12)
float conversion_factor = 3.3 / 4095;

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
