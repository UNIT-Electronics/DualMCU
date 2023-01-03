/*
 * UNIT ELectronics 2022
 * PWM & Bluetooth
 * This example demostrate the use of PWM function and Bluetooth, 
 * also show the configuration of the RGB led placed on the Dual MCU
 * Pins configuration are GPIO 25 (Red color), GPIO 26 (Green color) and GPIO 4 (Blue color)
 * they are default connected and don't need extra wire
 * For this example you need to install a Bluetooth Serial Terminal
*/

#include "BluetoothSerial.h"  //Bluetooth library
//Check if Bluetooth is properly enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;   //Object used to initialize the Bluetooth interface

//Define the RGB pins, they are default connected and don't need extra wire
#define Red 25
#define Green 26
#define Blue 4

/*Configure the PWM signal:
 * freq -> PWM signal frequency in Hertz
 * Choose a PWM channel. There are 16 channels from 0 to 15
 * resolution -> control the LED duty cycle from 0 to 255 
 */
int freq = 5000;
int RedChannel = 0;     //Channel 0 to control pin associated with Red led
int GreenChannel = 1;   //Channel 1 to control pin associated with Green led
int BlueChannel = 2;    //Channel 2 to control pin associated with Blue led
int resolution = 8;     //8 bit resolution, to control led from 0 to 255

int incomingChar;       //Variable to save the bluetooth incoming character 

void setup() {
  SerialBT.begin("DualMCU");  //Bluetooth device name
  SerialBT.register_callback(callback);   //This method display a message when you establishes a Bluetooth connection with the ESP32

  //Configure the LED PWM with the parameters that we defined
  //Red set up
  ledcSetup (RedChannel, freq, resolution);  //Function to configure the PWM properties 
  ledcAttachPin (Red, RedChannel);           //Function to asign the PWM channel to the corresponding pin
  //Green set up
  ledcSetup (GreenChannel, freq, resolution);
  ledcAttachPin (Green, GreenChannel);
  //Blue set up
  ledcSetup (BlueChannel, freq, resolution);
  ledcAttachPin (Blue, BlueChannel);
  /*
   * Starts the RGB LED off.
   * The RGB LED that includes the Dual mcu is Common Anode:
   * 0 -> Led on at maximum brightness
   * 255 -> Led off
   */
  ledcWrite(RedChannel, 255);
  ledcWrite(GreenChannel, 255);
  ledcWrite(BlueChannel, 255);
}

void loop() {  
  if (SerialBT.available()) {     //Check if there are bytes being received in the serial port
    incomingChar = SerialBT.read();   //Save a character coming via Bluetooth
    //According to the character receive is configurate the color
    switch (incomingChar){
    case '1':   //Red
      //set the brightness of the LED, function ledcWrite(ledChannel, dutyCycle)
      ledcWrite(RedChannel, 0);     //Maximum brightness
      ledcWrite(GreenChannel, 255); //Channel off
      ledcWrite(BlueChannel, 255);  //Channel off
      SerialBT.println("\nOk ;)");  //Send a Bluetooth message informing that the configuration is ok
      break;
    case '2':   //Green
      ledcWrite(RedChannel, 255);
      ledcWrite(GreenChannel, 0);
      ledcWrite(BlueChannel, 255);
      SerialBT.println("\nOk ;)");
      break;
    case '3':   //Blue
      ledcWrite(RedChannel, 255);
      ledcWrite(GreenChannel, 255);
      ledcWrite(BlueChannel, 0);
      SerialBT.println("\nOk ;)");
      break;
    case '4':   //White
      ledcWrite(RedChannel, 0);
      ledcWrite(GreenChannel, 0);
      ledcWrite(BlueChannel, 0);
      SerialBT.println("\nOk ;)");
      break;
    case '5':   //Yellow
      ledcWrite(RedChannel, 0);
      ledcWrite(GreenChannel, 0);
      ledcWrite(BlueChannel, 255);
      SerialBT.println("\nOk ;)");
      break;
    case '6':   //Magenta
      ledcWrite(RedChannel, 0);
      ledcWrite(GreenChannel, 255);
      ledcWrite(BlueChannel, 0);
      SerialBT.println("\nOk ;)");
      break;
    case '7':   //Cyan
      ledcWrite(RedChannel, 255);
      ledcWrite(GreenChannel, 0);
      ledcWrite(BlueChannel, 0);
      SerialBT.println("\nOk ;)");
      break;
    case '8':   //Pink
      ledcWrite(RedChannel, 0);
      ledcWrite(GreenChannel, 255);
      ledcWrite(BlueChannel, 128);
      SerialBT.println("\nOk ;)");
      break;
    case '9':   //Off
      ledcWrite(RedChannel, 255);
      ledcWrite(GreenChannel, 255);
      ledcWrite(BlueChannel, 255);
      SerialBT.println("\nOk ;)");
      break;
    
    default:
      break;
    }
  }
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  //This metod have a predefined signature and help us to know when a Bluetooth device connect with the ESP32
  if (event == ESP_SPP_SRV_OPEN_EVT) {
    //If a Bluetooth device is connected, display the next message on your Bluetooth Terminal for only time
    SerialBT.println("\nSelect the RGB color:");
    SerialBT.println("\t1. Red");
    SerialBT.println("\t2. Green");
    SerialBT.println("\t3. Blue");
    SerialBT.println("\t4. White");
    SerialBT.println("\t5. Yellow");
    SerialBT.println("\t6. Magenta");
    SerialBT.println("\t7. Cyan");
    SerialBT.println("\t8. Pink");
    SerialBT.println("\t9. Off");
    }
  }
