/*
  UNIT Electronics 2022
  Fade
  This example shows how to fade an LED on pin 25 - DualMCU Builtin LED (L3) using the analogWrite()
  function.

  This example was modified from the arduino code which is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/
#define builtin_LED 25 // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(builtin_LED, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of LED:
  analogWrite(builtin_LED, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 20 milliseconds to see the dimming effect
  delay(20);
}
