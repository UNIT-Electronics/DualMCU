"""
Unit Electronics 2022
Blink
Turns Builtin LED (L3) on for one second, then off for one second, repeatedly.
"""
from machine import Pin, Timer

builtin_led = 25  #DualMCU-Builtin LED (L3) as GPIO25
led = Pin(builtin_led, Pin.OUT)  #Configured as Output pin

tim = Timer()

def tick(timer):
    global led
    led.toggle()

#Frequency equal to 1Hz for blinking the builtin led
tim.init(freq=1, mode=Timer.PERIODIC, callback=tick)
