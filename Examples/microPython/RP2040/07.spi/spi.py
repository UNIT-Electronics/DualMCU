"""
Unit Electronics 2022
SPI
Example for SPI 0 settings
"""

from machine import SPI

# Assign chip select (CS) pin (and start it high)
cs = machine.Pin(21, machine.Pin.OUT)

# Initialize SPI
MISO = 20
MOSI = 19
SCK = 18

spi = machine.SPI(0,
                  baudrate=1000000,
                  polarity=1,
                  phase=1,
                  bits=8,
                  firstbit=machine.SPI.MSB,
                  sck=machine.Pin(SCK),
                  mosi=machine.Pin(MOSI),
                  miso=machine.Pin(MISO))

spi.write('test')
spi.read(5)

buf = bytearray(3)
spi.write_readinto('out', buf)
