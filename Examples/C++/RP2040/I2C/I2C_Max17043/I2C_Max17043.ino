/*
Unit Electronics 2022
I2C MAX17043, MAX17048 
Battery Fuel Gauge Monitor wired to the I2C JST1 connector on the DualMCU for RP2040 MCU
*/

#include <Wire.h>
#include "MAX17043.h"

// ***
// *** Connections:
// *** 1) Conect SDA pin to SDA on UNIT Charger
// *** 2) Connect SCL pin to SCL on UNIT Charger
// *** 3) Connect the GND pin to ground on the Dual MCU.

MAX17043 fuelGauge(20, 4);  //Alert Threshold, Alert Pin
byte buffer[5];             //Receive the data
unsigned char bufferChar[5];
int percentage;

void setup() {
  Wire.setSDA(12); //Connected to de I2C JST Connector
  Wire.setSCL(13); //Connected to de I2C JST Connector
  fuelGauge.begin();        //Init de Fuel Gauge Circuit
  delay(500);
  Serial.begin(115200);
  while (!Serial);
  Serial.println("I2C CHARGE BATTERY MONITOR");
  menu();
}

void loop() {
  if (Serial.available()) {
    Serial.readBytes(buffer, sizeof(buffer));
    if (buffer [0] == '?')
      menu();
    else if (buffer [0] == 'o' or buffer [0] == 'O')
      getRegisters();
    else if ((buffer [0] == 'h' or buffer [0] == 'H') and (buffer [1] == 'v' or buffer [1] == 'V')) {
      Serial.print("Version: ");
      Serial.println(fuelGauge.getVersion());
    }
    else if (buffer [0] == 't' or buffer [0] == 'T') {
      Serial.print("Alert Interrupt: ");
      Serial.println(fuelGauge.getAlertThreshold() + String(" %"));
    }
    else if (buffer [0] == 'v' or buffer [0] == 'V') {
      Serial.write("Battery Voltage:");
      Serial.println(fuelGauge.getBatteryVoltage() + String(" V"));
    }
    else if (buffer [0] == 'p' or buffer [0] == 'P') {
      Serial.print("State of Charge: ");
      Serial.println(fuelGauge.getBatteryPercentage() + String(" %"));
    }
    else if ((buffer [0] == 'i' or buffer [0] == 'I') and (buffer [1] == 's' or buffer [1] == 'S') and (buffer [2] == 'a' or buffer [2] == 'A')) {
      Serial.print("Alert Interrupt? ");
      Serial.println(fuelGauge.isAlerting());
    }
    else if ((buffer [0] == 'i' or buffer [0] == 'I') and (buffer [1] == 's' or buffer [1] == 'S') and (buffer [2] == 's' or buffer [2] == 'S')) {
      Serial.print("Sleep Mode? ");
      Serial.println(fuelGauge.isSleeping());
    }
    else if (buffer [0] == 's' or buffer [0] == 'S') {
      Serial.println("Sleep Mode active.");
      fuelGauge.sleep();
    }
    else if (buffer [0] == 'w' or buffer [0] == 'W') {
      Serial.println("Wake up Fuel Gauge.");
      fuelGauge.wake();
    }
    else if ((buffer [0] == 'a' or buffer [0] == 'A') and buffer [1] == '=' ) {
      /*   for (int i = 0; i < sizeof(buffer) - 1; i++)
           bufferChar[i] = buffer[i + 2];
         percentage = atoi(bufferChar);
         if (percentage > 32 || percentage == 0)
           Serial.println("Set value among 1% and 32%);
         else {
           fuelGauge.setAlertThreshold(percentage);
           Serial.println("Alert percentage: " + String(percentage));
         }*/
    }
    else if ((buffer [0] == 'r' or buffer [0] == 'R') and (buffer [1] == 's' or buffer [1] == 'S')) {
      Serial.println("Reset system.");
      fuelGauge.reset();
    }
  }
}
void getRegisters() {
  Serial.print("\nVersion: ");
  Serial.println(fuelGauge.getVersion());
  Serial.print("Alert Interrupt: ");
  Serial.println(fuelGauge.getAlertThreshold() + String(" %"));
  Serial.print("Battery Voltage: ");
  Serial.println(fuelGauge.getBatteryVoltage() + String(" V"));
  Serial.print("State of Charge: ");
  Serial.println(fuelGauge.getBatteryPercentage() + String(" %"));
  Serial.print("Alert Interrupt? ");
  Serial.println(fuelGauge.isAlerting());
  Serial.print("Sleep mode? ");
  Serial.println(fuelGauge.isSleeping());
  Serial.println("");
}

void menu() {
  Serial.println("Unit LiPo Battery Fuel Gauge \n");
  Serial.println("?    : Menu");
  Serial.println("O    : Output and configurations.");
  Serial.println("HV   : Returns IC version");
  Serial.println("T    : Alert Interrupt.");
  Serial.println("V    : Battery Voltage.");
  Serial.println("P    : State of Charge.");
  Serial.println("IsA? : Alert Interrupt? Return \"1\" if Alert Interrupt is On and \"0\" if this mode is Off");
  Serial.println("IsS? : Sleep Mode?  Return \"1\" if Sleep Mode is On and \"0\" if this mode is Off.");
  Serial.println("S    : Sleep Mode On.");
  Serial.println("W    : Wake up sistem to Sleep Mode.");
  Serial.println("A=x  : Threshold level sets the state of charge level where an interrupt is generated on the ALRT pin (x= alert percentage among 1 and 32 %)");
  Serial.println("RS    : Reset the IC. Include Alert Interrupt and Sleep Mode");
  Serial.println("");
}
