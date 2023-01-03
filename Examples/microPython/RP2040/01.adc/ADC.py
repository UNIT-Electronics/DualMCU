"""
Unit Electronics 2022
ADC
Obtain the read on ADC Port from RP2040.
"""
import machine #Machine module 
import utime

#Obtain the read on ADC Port, for RP2040 ADC: 0 (pin A0), 1 (pin A1), 2 (pin A2), 3 (pin A3)
voltage_read = machine.ADC(1)
conversion_factor = 3.3 / (65535)
  #Convert the input read on ADC pin in Voltage

while True:    
    voltage_write = voltage_read.read_u16() * conversion_factor  #Read the input with read_u16() function and obtain the equivalent voltage
    print(voltage_write," V")  #Print the result
    utime.sleep(0.5)