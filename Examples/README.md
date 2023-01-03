C++ & MicroPython-Examples for DualMCU RP2040 + ESP32
====================

<img src="Programming.jpg?raw=false" width="900px"><br/>

This repo features examples for MicroPython and Arduino for DualMCU RP2040 + ESP32.

> ### *C++  Basics*

### ESP32:

### 00.LEDs

__Blink.ino__

Turns on an LED (Connect to Pin 0 (IO0) or other ESP32 digital PIN on the DualMCU) for one second, then off for one second, repeatedly.

### 01.ADC

__ADC.ino__

These example reads de value of a potentiometer that is connected to GPIO 04 (Analog ADC2_CH0).

### 02.UART

__UART.ino__

 ESP32 has 3 serial ports: UART0, UART1, UART2:
 * UART0 -> Is connected to serial communication between ESP32 and computer, used for loading Arduino code to ESP32. GPIO 1 - RX, GPIO 3 - TX
 * UART1 -> This pins are internally connected to the SPI flash memory, we can not use UART1 directly without reassigning pins in Arduino IDE
 * UART2 -> GPIO 16 - RX, GPIO 17 - TX

### 03.TOUCH 

__CapacitiveTouch.ino__

Read a capacitive touch sensor:
* The DualMCU has three available  capacitive touch sensors: T0(GPIO4),T2(GPIO2) and T3(GPIO15). 

### 04.I2C

__I2C_Max17043.ino__

I2C MAX17043, MAX17048:
Battery Fuel Gauge Monitor wired to the I2C JST2 connector on the DualMCU for ESP32 MCU.

### 05.MicroSD

__DirectoryFunctions.ino__

Example use of chdir(), ls(), mkdir(), and  rmdir().

__QuickStart.ino__

Quick hardware test for SPI card access.

__SdInfo.ino__

This program attempts to initialize an SD card and analyze its structure.

### 06.PWM

__PWM_and_Bluetooth.ino__
PWM & Bluetooth:
 * This example demostrate the use of PWM function and Bluetooth, 
 * Also show the configuration of the RGB led placed on the Dual MCU
 * Pins configuration are GPIO 25 (Red color), GPIO 26 (Green color) and GPIO 4 (Blue color)
 * They are default connected and don't need extra wire
 * For this example you need to install a Bluetooth Serial Terminal app

### 07.CAN

__CANBUS_ESP32_NATIVE-RECEIVE.ino__
This is a Controller Area Network (CAN) interface configuration for an ESP32 microcontroller as a receiver node:
* The CAN driver is configured to operate in normal mode and use a speed of 500 kbit/s for these examples, but it can be changed.  
* The GPIO pins 26 and 25 are set to transmit and receive, respectively, and should be connected to a physical layer transceiver chip for the CAN protocol such as the [TJA1050T](https://uelectronics.com/producto/tja1050t-transceptor-can-de-alta-velocidad/) or [TCAN1051HVD](https://uelectronics.com/producto/tcan1051hvd-transceptor-can-smd/). These chips allow the microcontroller to interface with the CAN bus and communicate with other devices on the network. The transceiver handles the low-level signaling and data transmission on the bus, allowing the microcontroller to focus on higher-level tasks like protocol handling and message processing. It is important to choose a transceiver that is compatible with the voltage level of your microcontroller, so be sure to select a chip that works with 3.3v because that is the voltage level of the DUALMCU system. 


### RP2040:

### 00.LEDs

__Blink.ino__

Turns Builtin LED (L3) (GPIO 25) on for one second, then off for one second, repeatedly.

### 01.ADC

__ADC.ino__

These example obtain the read on ADC Port from RP2040.
* Analog signal is connected to GPIO 26,27,28 or 29  (Analogs A0,A1,A2,A3) 

### 02.UART

__SerialPassthrough.ino__

RP2040 has 2 serial ports: UART0, UART1, this sketch allows you to emulate the serial passthrough behaviour between UART0 and UART1:
* Connect TX0 to RX1 and RX0 to TX1 on the DualMCU

### 03.PWM

__Fade.ino__

This example shows how to fade an LED on pin 25 - DualMCU Builtin LED (L3) using the analogWrite()
function.

### 04.I2C

__I2C_Max17043.ino__
For I2C MAX17043, MAX17048 
* Battery Fuel Gauge Monitor wired to the I2C JST1 connector on the DualMCU for RP2040 MCU

__TalkingToMyself.ino__
Simple I2C master and slave demo based on  - Earle F. Philhower, III script for Raspberry Pi Pico:
* Using both onboard I2C interfaces, I2C_0 (Pins: SDA_0 =2, SDA_0 =3) and I2C_1 (Pins: SDA_1 =12, SDA_1 =13) have one master and one slave
and send data both ways between them
* To run, connect GPIO12 to GPIO2, GPIO13 to GPIO3 on a DualMCU board

### 07.CAN
The RP2040 chip on the DualMCU, which does not have built-in support for the Controller Area Network (CAN) protocol. However, it is possible to add CAN capability to the DualMCU RP2040 by using an external CAN transceiver chip and implementing the CAN protocol in software. There are a number of different CAN transceiver chips available, each with its own unique features and capabilities. Some popular options include the [MCP2515 Can Bus](https://uelectronics.com/producto/mcp2515-arduino-can-bus-spi-tja1050/), [TJA1050T](https://uelectronics.com/producto/tja1050t-transceptor-can-de-alta-velocidad/), the [TCAN1051HVD](https://uelectronics.com/producto/tcan1051hvd-transceptor-can-smd/), and SN65HVD230. To use CAN with the RP2040, you will need to connect the transceiver to the DualMCU's SPI GPIO pins:

Connect: 
* DUALMCU GPIO 20 (MISO) to MCP2515 (SO)
* DUALMCU GPIO 19 (MOSI) to MCP2515 (SI)
* DUALMCU GPIO 18 (SCK) to MCP2515 (SCK)
* DUALMCU GPIO 21 (CS) to MCP2515 (CS)

__RECV_CAN2515.ino__
This example is a Controller Area Network (CAN) interface configuration for the RP2040 microcontroller to communicate with a device using an MCP2515 CAN transceiver via the SPI port as a receiver node:
* The CAN driver is configured to operate in normal mode and use a speed of 500 kbit/s for these examples, but it can be changed.  
* The "loop()" function calls the "recv_data()" function, which reads CAN messages from the transceiver and prints them to the console.
* If a message is available, the function reads the data and CAN ID of the message and prints them to the console in hexadecimal format.
* It only reads and processes messages, but does not send messages.

__Send_CAN2515.ino__
This example is a Controller Area Network (CAN) interface configuration for the RP2040 microcontroller to communicate with a device using an MCP2515 CAN transceiver via the SPI port as a transmitter node:  
* The code sets up the MCP2515 to work at a speed of 500 kbit/s, but it can be changed. 
* It sends two different CAN messages in a loop. The messages are arrays of 8 bytes each, named "stmp0" and "stmp1", and are sent to two different CAN IDs, 0x000 and 0x001, respectively. 
* The messages are also printed to the serial console. 
* It only sends messages, but does not receive or process them.

> ### *Micropython Basics*

### RP2040:

### 00.LEDs

__blink.py__

Turns Builtin LED (L3) GPIO 25 on for one second, then off for one second, repeatedly.

### 01.ADC

__ADC.py__

These example obtain the read on ADC Port from RP2040.
* Analog signal is connected to GPIO 26,27,28 or 29  (Analogs A0,A1,A2,A3) 

### 02.PWM

__PWM.py__
This code is a simple example of how to use Pulse Width Modulation (PWM) on the microcontroller to control the brightness of an LED connected to Pin 25:
* The code first constructs a PWM object and sets the frequency to 1000 Hz. 
* It then enters an infinite loop where it alternately increases and decreases the duty cycle of the PWM signal, with a delay of 1 ms between each change. This causes the LED to fade in and out.
* The duty cycle is multiplied by itself in order to create a non-linear brightness change.

### 03.UART

__UART.py__
Example using UART 0 and 1 on RP2040:
* Connect TX0 to RX1 and run current script

__serial.py__
This code is an example of how to use the UART (Universal Asynchronous Receiver/Transmitter) interface on the microcontroller to receive data from another device:
* The code first initializes the UART with a baud rate of 115200 and then enters an infinite loop.
* It continually checks if there is any data available in the UART buffer, and if there is, it reads a line of data and tries to decode it as a UTF-8 encoded string. 
* If the decoding is successful, the decoded string is printed to the console. If it fails, the exception is caught and the program continues. 



__04.IRQ.py__

__05.PIO__

__06.I2C.py__

__07.spi.py__

__08.multicore__


### Troubleshooting

__BOOT Mode__  
For RP2040 micropython examples hold down BOOT switch and quickly press and release RST switch. Then release BOOT switch. This is boot mode, which is useful when install Micropython on DualMCU using Thonny Python IDE.

