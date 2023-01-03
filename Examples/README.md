C++ & MicroPython-Examples for DualMCU RP2040 + ESP32
====================

<img src="Programming.jpg?raw=false" width="900px"><br/>

This repo features examples for MicroPython and Arduino for DualMCU RP2040 + ESP32.

> ### *C++  Basics*

### For ESP32:

### 00.LEDs

[__Blink.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/00.LEDs/Blink/Blink.ino)

Turns on an LED (Connect to Pin 0 (IO0) or other ESP32 digital PIN on the DualMCU) for one second, then off for one second, repeatedly.

### 01.ADC

[__ADC.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/01.ADC/ReadAnalogVoltage/ReadAnalogVoltage.ino)

These example reads de value of a potentiometer that is connected to GPIO 04 (Analog ADC2_CH0).

### 02.UART

[__UART.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/02.UART/UART/UART.ino)

 ESP32 has 3 serial ports: UART0, UART1, UART2:
 * UART0 -> Is connected to serial communication between ESP32 and computer, used for loading Arduino code to ESP32. GPIO 1 - RX, GPIO 3 - TX
 * UART1 -> This pins are internally connected to the SPI flash memory, we can not use UART1 directly without reassigning pins in Arduino IDE
 * UART2 -> GPIO 16 - RX, GPIO 17 - TX

### 03.TOUCH 

[__CapacitiveTouch.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/03.TOUCH/CapacitiveTouch/CapacitiveTouch.ino)

Read a capacitive touch sensor:
* The DualMCU has three available  capacitive touch sensors: T0(GPIO4),T2(GPIO2) and T3(GPIO15). 

### 04.I2C

[__I2C_Max17043.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/04.I2C/I2C_Max17043/I2C_Max17043.ino)

I2C MAX17043, MAX17048:
Battery Fuel Gauge Monitor wired to the I2C JST2 connector on the DualMCU for ESP32 MCU.

### 05.MicroSD

[__DirectoryFunctions.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/05.MicroSd/DirectoryFunctions/DirectoryFunctions.ino)

Example use of chdir(), ls(), mkdir(), and  rmdir().

[__QuickStart.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/05.MicroSd/QuickStart/QuickStart.ino)

Quick hardware test for SPI card access.

[__SdInfo.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/05.MicroSd/SdInfo/SdInfo.ino)

This program attempts to initialize an SD card and analyze its structure.

### 06.PWM

[__PWM_and_Bluetooth.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/06.PWM/PWM_and_Bluetooth/PWM_and_Bluetooth.ino)
PWM & Bluetooth:
 * This example demostrate the use of PWM function and Bluetooth, 
 * Also show the configuration of the RGB led placed on the Dual MCU
 * Pins configuration are GPIO 25 (Red color), GPIO 26 (Green color) and GPIO 4 (Blue color)
 * They are default connected and don't need extra wire
 * For this example you need to install a Bluetooth Serial Terminal app

### 07.CAN

[__CANBUS_ESP32_NATIVE-RECEIVE.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/ESP32/07.CAN/CANBUS_ESP32_NATIVE-RECEIVE/CANBUS_ESP32_NATIVE-RECEIVE.ino)
This is a Controller Area Network (CAN) interface configuration for an ESP32 microcontroller as a receiver node:
* The CAN driver is configured to operate in normal mode and use a speed of 500 kbit/s for these examples, but it can be changed.  
* The GPIO pins 26 and 25 are set to transmit and receive, respectively, and should be connected to a physical layer transceiver chip for the CAN protocol such as the [TJA1050T](https://uelectronics.com/producto/tja1050t-transceptor-can-de-alta-velocidad/) or [TCAN1051HVD](https://uelectronics.com/producto/tcan1051hvd-transceptor-can-smd/). These chips allow the microcontroller to interface with the CAN bus and communicate with other devices on the network. The transceiver handles the low-level signaling and data transmission on the bus, allowing the microcontroller to focus on higher-level tasks like protocol handling and message processing. It is important to choose a transceiver that is compatible with the voltage level of your microcontroller, so be sure to select a chip that works with 3.3v because that is the voltage level of the DUALMCU system. 


### For RP2040:

### 00.LEDs

[__Blink.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/00.Blink/Blink.ino)

Turns Builtin LED (L3) (GPIO 25) on for one second, then off for one second, repeatedly.

### 01.ADC

[__ReadAnalogVoltage.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/01.ADC/ReadAnalogVoltage.ino)

These example obtain the read on ADC Port from RP2040.
* Analog signal is connected to GPIO 26,27,28 or 29  (Analogs A0,A1,A2,A3) 

### 02.UART

[__SerialPassthrough.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/02.UART/SerialPassthrough/SerialPassthrough.ino)

RP2040 has 2 serial ports: UART0, UART1, this sketch allows you to emulate the serial passthrough behaviour between UART0 and UART1:
* Connect TX0 to RX1 and RX0 to TX1 on the DualMCU

### 03.PWM

[__Fade.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/03.PWM/Fade/Fade.ino)

This example shows how to fade an LED on pin 25 - DualMCU Builtin LED (L3) using the analogWrite()
function.

### 04.I2C

[__I2C_Max17043.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/04.I2C/I2C_Max17043/I2C_Max17043.ino)
For I2C MAX17043, MAX17048 
* Battery Fuel Gauge Monitor wired to the I2C JST1 connector on the DualMCU for RP2040 MCU

[__TalkingToMyself.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/04.I2C/TalkingToMyself/TalkingToMyself.ino)
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

[__RECV_CAN2515.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/05.CAN/RECV_CAN2515/RECV_CAN2515.ino)
This example is a Controller Area Network (CAN) interface configuration for the RP2040 microcontroller to communicate with a device using an MCP2515 CAN transceiver via the SPI port as a receiver node:
* The CAN driver is configured to operate in normal mode and use a speed of 500 kbit/s for these examples, but it can be changed.  
* The "loop()" function calls the "recv_data()" function, which reads CAN messages from the transceiver and prints them to the console.
* If a message is available, the function reads the data and CAN ID of the message and prints them to the console in hexadecimal format.
* It only reads and processes messages, but does not send messages.

[__Send_CAN2515.ino__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/C%2B%2B%20Basics/RP2040/examples/05.CAN/Send_CAN2515/Send_CAN2515.ino)
This example is a Controller Area Network (CAN) interface configuration for the RP2040 microcontroller to communicate with a device using an MCP2515 CAN transceiver via the SPI port as a transmitter node:  
* The code sets up the MCP2515 to work at a speed of 500 kbit/s, but it can be changed. 
* It sends two different CAN messages in a loop. The messages are arrays of 8 bytes each, named "stmp0" and "stmp1", and are sent to two different CAN IDs, 0x000 and 0x001, respectively. 
* The messages are also printed to the serial console. 
* It only sends messages, but does not receive or process them.

> ### *Micropython Basics*

### For RP2040:

### 00.LEDs

[__blink.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/00.LEDs/blink.py)

Turns Builtin LED (L3) GPIO 25 on for one second, then off for one second, repeatedly.

### 01.ADC

[__ADC.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/01.ADC/ADC.py)

These example obtain the read on ADC Port from RP2040.
* Analog signal is connected to GPIO 26,27,28 or 29  (Analogs A0,A1,A2,A3) 

### 02.PWM

[__PWM.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/02.PWM/PWM.py)
This code is a simple example of how to use Pulse Width Modulation (PWM) on the microcontroller to control the brightness of an LED connected to Pin 25:
* The code first constructs a PWM object and sets the frequency to 1000 Hz. 
* It then enters an infinite loop where it alternately increases and decreases the duty cycle of the PWM signal, with a delay of 1 ms between each change. This causes the LED to fade in and out.
* The duty cycle is multiplied by itself in order to create a non-linear brightness change.

### 03.UART

[__UART.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/03.UART/UART.py)
Example using UART 0 and 1 on RP2040:
* Connect TX0 to RX1 and run current script

[__serial.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/03.UART/serial.py)
This code is an example of how to use the UART (Universal Asynchronous Receiver/Transmitter) interface on the microcontroller to receive data from another device:
* The code first initializes the UART with a baud rate of 115200 and then enters an infinite loop.
* It continually checks if there is any data available in the UART buffer, and if there is, it reads a line of data and tries to decode it as a UTF-8 encoded string. 
* If the decoding is successful, the decoded string is printed to the console. If it fails, the exception is caught and the program continues. 

### 04.IRQ

[__irq.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/04.IRQ/irq.py)
Hardware interrupt handling:
* This code imports the Pin class from the machine module. It then creates an instance of the Pin class called p2, initialized with pin number 2, configured as an input pin, and using the internal pull-up resistor. * The code then sets up an interrupt handler for the p2 pin using the irq method. 
* This interrupt handler will be called whenever a falling edge is detected on the p2 pin, and it will print a message containing the flags associated with the interrupt request.

### 05.PIO

[__pio_1hz.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/05.PIO/pio_1hz.py)

Example using PIO to blink an Builtin LED and raise an IRQ at 1Hz.

[__pio_blink.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/05.PIO/pio_blink.py)

This code imports several modules: time, rp2, and Pin from the machine module. It then defines a function called blink using the asm_pio decorator from the rp2 module. This function sets the value of an output pin called pins to 1, waits for a few cycles, sets the value of pins to 0, and waits again. The wrap_target and wrap statements are used to implement looping behavior for the function.

The code then creates an instance of the StateMachine class from the rp2 module called sm, initialized with the blink function, a frequency of 2000Hz, and an output pin bound to pin 25. The active method is then used to start and stop the state machine, causing the LED to blink for 3 seconds.

[__pio_pwm.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/05.PIO/pio_pwm.py)
Example of using PIO for PWM, and fading the brightness of an LED.

This code defines a function called pwm_prog using the asm_pio decorator from the rp2 module. It then creates a class called PIOPWM that takes four arguments in its constructor: sm_id, pin, max_count, and count_freq. The PIOPWM class creates an instance of the StateMachine class from the rp2 module called sm, initialized with the pwm_prog function, a frequency of 2 * count_freq, and an output pin bound to pin. The class also has a method called set that sets the value of the output pin.

The code then creates an instance of the PIOPWM class called pwm, initialized with 0 for sm_id, builtin_LED for pin, (1 << 16) - 1 for max_count, and 10_000_000 for count_freq. It then enters an infinite loop, increasing the value of the output pin from 0 to 255 using the set method and delaying for 0.01 seconds between each iteration. This causes the output pin to produce a pulse-width modulated signal.

[__pio_ws2812.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/05.PIO/pio_ws2812.py)
Example using PIO to drive a set of on-board WS2812 LED.

This code defines a function called ws2812 using the asm_pio decorator from the rp2 module. It then creates an instance of the StateMachine class from the rp2 module called sm, initialized with the ws2812 function, a frequency of 8000000Hz, and an output pin bound to the NEOP_DIN pin. The code also configures the NEOPWR pin as an output and sets it to 1.

The code then enters an infinite loop that displays a pattern on a number of WS2812 LEDs specified by the NUM_LEDS variable. The pattern cycles through different colors and fades out over time. The colors and brightness of the LEDs are controlled using an array called "ar" containing the RGB values for each LED. The sm.put method is used to send the data in the "ar" array to the sm state machine, which drives the WS2812 LEDs. The loop delays for 50 milliseconds between each iteration.

[__neopixel_ring__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/05.PIO/neopixel_ring.py)
Combination of the PIO WS2812 demo with the Adafruit 'essential' NeoPixel example code to show off color fills, chases and of course a rainbow swirl on a 16-LED ring addapted for the DualMCU RP2040.

* This code defines a function called ws2812 using the asm_pio decorator from the rp2 module. It then creates an instance of the StateMachine class from the rp2 module called sm, initialized with the ws2812 function, a frequency of 8000000Hz, and an output pin bound to the NEOP_DIN pin. 
* The code also configures the NEOPWR pin as an output and sets it to 1.
* The code then defines a number of functions for controlling a number of WS2812 LEDs specified by the NUM_LEDS variable.
* The pixels_show function updates the WS2812 LEDs with the current state of an array called ar containing the RGB values for each LED, applying a brightness factor specified by the brightness variable. 
* The pixels_set and pixels_fill functions modify the values in the ar array. 
* The color_chase, wheel, and rainbow_cycle functions produce various visual effects on the WS2812 LEDs by updating the values in the ar array and calling the pixels_show function. The code also defines constants for various colors.

Finally, the code enters an infinite loop that repeatedly calls the various functions to produce a sequence of visual effects on the WS2812 LEDs. The loop delays for a short time between each function call.

### 06.I2C

[__I2C.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/06.I2C/I2C.py)

This example scans for the I2C device address.

### 07.SPI

[__spi.py__](https://github.com/UNIT-Electronics/DualMCU/tree/main/Examples/Micropython%20Basics/RP2040/07.SPI)

Example for SPI 0 settings.

* This code initializes the cs pin as an output pin and sets it high.
*  It then initializes the spi variable as an instance of the SPI class from the machine module, configured with a baud rate of 1000000Hz, clock polarity and phase of 1, 8 bits per word, most significant bit first, and the SCK, MOSI, and MISO pins as the clock, master out/slave in, and master in/slave out pins, respectively.
* The code then sends the string 'test' over the SPI bus using the spi.write method and reads 5 bytes from the bus using the spi.read method. 
* It then creates a bytearray called buf and uses the spi.write_readinto method to send the string 'out' over the bus and store the received data in the buf array.

### 08.MULTICORE

[__multicore.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/08.MULTICORE/multicore.py)
This example uses the multicore function on the RP2040.

* Defines a function called task that takes two arguments: n, which specifies the number of times to toggle an LED, and delay, which specifies the time to wait between each toggle.  
* The task function sets the led pin as an output pin and then enters a loop that toggles the led pin n times, waiting delay seconds between each toggle.
* After defining the task function, the code uses the _thread.start_new_thread function to start a new thread running the task function with the arguments (10, 0.5), which will cause the task function to toggle the led pin 10 times with a 0.5 second delay between each toggle. 
* This will run concurrently with the rest of the code.

[__multicore_semaphore.py__](https://github.com/UNIT-Electronics/DualMCU/blob/main/Examples/Micropython%20Basics/RP2040/08.MULTICORE/multicore_semaphore.py)
This example creates a semaphore using multicore task.

* It imports three modules: machine, utime, and _thread and  initializes two pins, led1 and led2, as output pins.
* The code defines a function called CoreTask that runs in an infinite loop. Inside the loop, the function acquires a lock using the sLock semaphore and then sleeps for 1 second. 
* It then turns on led2, sleeps for 2 seconds, turns off led2, and sleeps for another 1 second. After this, it releases the lock and sleeps for 1 second before the loop repeats.
* The code then starts a new thread running the CoreTask function and enters its own infinite loop. 
* Inside this loop, the main thread acquires the sLock semaphore, toggles led1, sleeps for 0.15 seconds, sleeps for 1 second, and then releases the sLock semaphore before repeating the loop.

Overall, this code creates a semaphore using the sLock lock object and uses it to synchronize the main thread and the CoreTask thread, allowing them to take turns running and accessing shared resources. The main thread toggles led1 at a rapid rate, while the CoreTask thread turns on and off led2 at a slower rate.

### Troubleshooting

__BOOT Mode__  
For RP2040 micropython examples hold down BOOT switch and quickly press and release RST switch. Then release BOOT switch. This is boot mode, which is useful when install Micropython on DualMCU using Thonny Python IDE.

