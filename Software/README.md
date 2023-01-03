UF2 Examples for DualMCU RP2040
====================

This repository contains UF2 (Universal Firmware Update) files specifically for the RP2040 microcontroller on the DualMCU board. These files can be used to easily load example code onto the DualMCU board, enabling users to customize and update the functionality of the RP2040 microcontroller. The repository includes various codes in UF2 format, allowing users to explore different examples to find the one that best meets their needs for the RP2040 microcontroller on the DualMCU board.


[### Test.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/Test.uf2) is an example file that can be used to test the USB-serial communication, LED [L3](https://raw.githubusercontent.com/UNIT-Electronics/DualMCU/main/Hardware/Resources/Front%20View%20DualMCU%20Topology.jpg) (GPIO 25), and neopixel on the DualMCU RP2040 board. When loaded onto the board, this file will allow users to verify that these features are functioning properly. This can be useful for testing or simply exploring the capabilities of the DualMCU RP2040 board.

[### UNIT_NEOPIXEL_ws2812.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/UNIT_NEOPIXEL_ws2812.uf2) is an example file that can be used to test the ["L4"](https://raw.githubusercontent.com/UNIT-Electronics/DualMCU/main/Hardware/Resources/Front%20View%20DualMCU%20Topology.jpg) (WS2812 LED) neopixel on the DualMCU RP2040 board. When loaded onto the board, this file will generate a random sequence of multiple color combinations on the neopixel. This can be useful for verifying the functionality of the neopixel or for exploring the capabilities of the DualMCU RP2040 board.

[### Blink.UF2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/blink.uf2)

[### flash_nuke.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/flash_nuke.uf2)

[### usb_microphone.uf2](https://github.com/UNIT-Electronics/DualMCU/blob/main/Software/UF2_Testing_File/usb_microphone.uf2)
### Troubleshooting

__BOOT Mode__  
To load the UF2 examples on the RP2040 in the DualMCU, hold down BOOT switch and quickly press and release RST switch. Then release BOOT switch. This is boot mode, now just drag and drop de UF2 file.

