"""
Unit Electronics 2022
I2C
Scans for the I2C device address
"""
from machine import I2C, Pin
import binascii

#set the pins used for i2c
i2c = I2C(1, scl=Pin(3), sda=Pin(2), freq=100000)  #set the pins used for i2c
#Scans for the i2c adress
devices = i2c.scan()
print("I2C Address: ", hex(devices[0]))

        