"""
Unit Electronics 2022
Example using PIO to drive a set of on-board WS2812 LED.
"""
import array, time
from machine import Pin
import rp2

# Configure the number of WS2812 LEDs.
NUM_LEDS = 1
NEOP_DIN = 16 #GPIO16 Connected to WS2812 DIN
#Configure de WS2812 enable pin (17) 
NEOPWR = Pin (17,Pin.OUT)
NEOPWR.value(1)


@rp2.asm_pio(sideset_init=rp2.PIO.OUT_LOW, out_shiftdir=rp2.PIO.SHIFT_LEFT, autopull=True, pull_thresh=24)
def ws2812():
    T1 = 2
    T2 = 5
    T3 = 3
    wrap_target()
    label("bitloop")
    out(x, 1)               .side(0)    [T3 - 1]
    jmp(not_x, "do_zero")   .side(1)    [T1 - 1]
    jmp("bitloop")          .side(1)    [T2 - 1]
    label("do_zero")
    nop()                   .side(0)    [T2 - 1]
    wrap()


# Create the StateMachine with the ws2812 program, For DualMCU the outputting is on GPIO16 -> "NEOP_DIN".
sm = rp2.StateMachine(0, ws2812, freq=8_000_000, sideset_base=Pin(NEOP_DIN))

# Start the StateMachine, it will wait for data on its FIFO.
sm.active(1)

# Display a pattern on the LEDs via an array of LED RGB values.
ar = array.array("I", [0 for _ in range(NUM_LEDS)])

while 1:
        
    # Cycle colours.
    for i in range(4 * NUM_LEDS):
        for j in range(NUM_LEDS):
            b = j * 100 // (NUM_LEDS)
            r = 100 - j * 100 // (NUM_LEDS)
            if j != i % NUM_LEDS:
                r >>= 3
                b >>= 3
            ar[j] = r << 16 | b
        sm.put(ar, 8)
        time.sleep_ms(50)

    # Fade out.
    for i in range(24):
        for j in range(NUM_LEDS):
            ar[j] >>= 1
        sm.put(ar, 8)
        time.sleep_ms(50)
