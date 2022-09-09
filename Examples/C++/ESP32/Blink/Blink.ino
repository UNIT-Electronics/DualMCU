/*
Unit Electronics 2022
Blink
Turns on an LED (Connect to Pin 0 (IO0) or other ESP32 digital PIN on the DualMCU) for one second, then off for one second, repeatedly.
*/
#define LED 0

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
