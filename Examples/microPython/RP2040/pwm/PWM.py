"""
Unit Electronics 2022
Example using PWM to fade an LED.
"""

import time
from machine import Pin, PWM  #From machine module call Pin and PWM register

builtin_LED =25
# Construct PWM object, with LED on Pin(25).
pwm = PWM(Pin(builtin_LED))

# Set the PWM frequency.
pwm.freq(1000)

# Fade the LED in and out a few times.
duty = 0

while True:
    #Cycle to increase the PWM duty and set the output value
    for i in range(0, 255):
        duty = i
        pwm.duty_u16(duty*duty)
        time.sleep(0.001)
        
    #Cycle to decrease the PWM duty and set the output value 
    for j in range(255,0, -1):
        duty = j
        pwm.duty_u16(duty*duty)
        time.sleep(0.001)

