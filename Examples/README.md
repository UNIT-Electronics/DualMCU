C++ & MicroPython-Examples
====================

<img src="Programming.jpg?raw=false" width="900px"><br/>

This repo features examples for MicroPython and Arduino for DualMCU RP2040 + ESP32.

> ### C++  Basics

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


__RP2040:__

__00.Blink.ino__

__01.ReadAnalogVoltage.ino__

__02.UART.ino__

__03.PWM.ino__

__04.I2C__

__07.CAN__

### Micropython Basics

__RP2040:__

__00.blink.py__

__01.ADC.py__

__02.PWM.py__

__03.UART.py__

__04.IRQ.py__

__05.PIO__

__06.I2C.py__

__07.spi.py__

__08.multicore__


### Troubleshooting

__BOOT Mode__  
For RP2040 micropython examples hold down BOOT switch and quickly press and release RST switch. Then release BOOT switch. This is boot mode, which is useful when install Micropython on DualMCU using Thonny Python IDE.

