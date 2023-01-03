UF2 Examples for DualMCU RP2040
====================

This repository contains UF2 (Universal Firmware Update) files specifically for the RP2040 microcontroller on the DualMCU board. These files can be used to easily load example code onto the DualMCU board, enabling users to customize and update the functionality of the RP2040 microcontroller. The repository includes various codes in UF2 format, allowing users to explore different examples to find the one that best meets their needs for the RP2040 microcontroller on the DualMCU board.


[# Test.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/Test.uf2) is an example file that can be used to test the USB-serial communication, LED ["L3"](https://raw.githubusercontent.com/UNIT-Electronics/DualMCU/main/Hardware/Resources/Front%20View%20DualMCU%20Topology.jpg) (GPIO 25), and neopixel on the DualMCU RP2040 board. When loaded onto the board, this file will allow users to verify that these features are functioning properly. This can be useful for testing or simply exploring the capabilities of the DualMCU RP2040 board.

[# UNIT_NEOPIXEL_ws2812.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/UNIT_NEOPIXEL_ws2812.uf2) is an example file that can be used to test the ["L4"](https://raw.githubusercontent.com/UNIT-Electronics/DualMCU/main/Hardware/Resources/Front%20View%20DualMCU%20Topology.jpg) (WS2812 LED) neopixel on the DualMCU RP2040 board. When loaded onto the board, this file will generate a random sequence of multiple color combinations on the neopixel. This can be useful for verifying the functionality of the neopixel or for exploring the capabilities of the DualMCU RP2040 board.

[# Blink.UF2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/blink.uf2) is an example file that can be used to test the "L3" (GPIO25) LED on the DualMCU RP2040 board. When loaded onto the board, this file will cause the LED to blink at a 1-second interval. This can be useful for verifying the functionality of the ["L3"](https://raw.githubusercontent.com/UNIT-Electronics/DualMCU/main/Hardware/Resources/Front%20View%20DualMCU%20Topology.jpg) LED  of the DualMCU RP2040 board.

*"It is also recommended to use this file as a "clean" file when the COM port is not recognized from the Arduino IDE."*

[# flash_nuke.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/flash_nuke.uf2)  is a file that is used to completely erase the firmware on a device, also known as "nuking" the device. This file is usually used to restore a device to its factory default state or to prepare it for new firmware to be installed. 

*"It is important to note that using flash_nuke.uf2 will permanently delete any existing firmware and data on the device, so it should be used with caution."*

[# usb_microphone.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/usb_microphone.uf2) is an example file that can be used to transform the DualMCU into a high-performance USB microphone using the RP2040 microcontroller. To use this file, it is necessary to connect a PDM (Pulse Density Modulation) type MEMS microphone, such as the MP34DT05-A, the MP34DT06J, or the Adafruit PDM microphone module MP34DT01-M, to the DualMCU board. This allows the DualMCU to function as an excellent microphone for use in video conferences or simply for entertainment, with very good sound quality. This file is particularly useful for those looking to add microphone functionality to their DualMCU project or to explore the capabilities of the RP2040 microcontroller.

<img src="UF2_Testing_File/PDM-Mic.jpg?raw=false" width="200px"><br/> 
**To connect an Adafruit PDM microphone module to the RP2040 microcontroller on the DualMCU board, follow these steps:**

1. First, make sure that you have the necessary equipment: an Adafruit PDM microphone module and the DualMCU board with the RP2040 microcontroller.
2. Locate the GPIO22 and GPIO23 pins on the DualMCU board ([Pinout](https://github.com/UNIT-Electronics/DualMCU/blob/main/Hardware/Resources/EU0002-DUALMCU%20V3.1.jpg]). Connect the PDM microphone module to the DualMCU board using the appropriate cables or connectors, following these connections:

* DualMCU (3.3V)   to  PDM-MIC (3.3V)
* DualMCU (GND)    to  PDM-MIC (GND)
* DualMCU (GPIO23) to  PDM-MIC (SCL signal)
* DualMCU (GPIO22) to  PDM-MIC (DAT signal)

3. Power on the DualMCU board and the PDM microphone module.

4. Follow the instructions and steps required to enable BOOT mode on the RP2040, and drag and drop usb_microphone.uf2 file on the DualMCU board.

With these steps, you should be able to successfully connect an Adafruit PDM microphone module to the RP2040 microcontroller on the DualMCU board.


### Troubleshooting

__BOOT Mode__  
o load the UF2 examples onto the RP2040 in the DualMCU, hold down the BOOT switch and quickly press and release the RST switch. Then, release the BOOT switch. This will enter boot mode. Now, simply drag and drop the UF2 file example into the window explorer files that have appeared. ([For more information, see section 5 "Board Operation" of the Product Manual Reference](https://github.com/UNIT-Electronics/DualMCU/blob/main/DualMCU(Product%20Reference%20Manual).pdf))

