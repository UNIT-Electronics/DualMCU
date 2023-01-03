/*
  UNIT Elelctronics 2022

  SerialPassthrough sketch

  This sketch allows you to emulate the serial passthrough behaviour between UART0 and UART1
  Connect TX0 to RX1 and RX0 to TX1 on the DualMCU
*/

#define PIN_SERIAL1_TX (0u)
#define PIN_SERIAL1_RX (1u)

#define PIN_SERIAL2_TX (8u)
#define PIN_SERIAL2_RX (9u)


void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial.println("Serial Pass Through");
}

void loop() {
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}
