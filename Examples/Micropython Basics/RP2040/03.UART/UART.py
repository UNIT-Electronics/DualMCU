"""
Unit Electronics 2022
UART
Example using UART 0 and 1 on RP2040
Connect TX0 to RX1 and run current script
"""

from machine import UART, Pin #From machine module call Pin and UART register
import time
# Starting UART port's with the next syntax:
#UART(UART Port 1 or 0, clock rate, Transmission port, Reception port)
uart1 = UART(1, baudrate=115200, tx=Pin(8,Pin.OUT), rx=Pin(9,Pin.IN)) 
uart0 = UART(0, baudrate=115200, tx=Pin(0,Pin.OUT), rx=Pin(1,Pin.IN))

#Connect pin 8 Tx and pin 1 Rx to communicate both UART ports

txData = 'Hello World!\n\r' #Variable defined with characters that we will transmit

uart1.write(txData) #Write the buffer of bytes to the bus, in this case we transmit through UART Pins 1 (pin 8)

time.sleep(0.1) #Wait 0.1s 

rxData = bytes() #Define a reception variable

#Receive the characters in UART Pins 0 and save in the reception variable
while uart0.any()>0:  
    rxData += uart0.read()
    
#Print the information obtained in ASCII code
print(rxData.decode('utf-8'))

