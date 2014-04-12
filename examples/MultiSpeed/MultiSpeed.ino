#include <BiColorLED.h>

// Simple demo of multiple blink speeds in V1.4+ of the BiColorLED library
// (C) 2014 Wolfgang Faust

// To see the effects of this example, just plug a bi-color LED
// into pins 4 and 5, along with the appropriate resistors.

BiColorLED led=BiColorLED(4,5); // (pin 1, pin 2)

void setup() {
  // Set LED to flash red for 50ms every half-second
  led.setColor(0, 1);
  led.setBlinkSpeed(450, 50);
}

void loop() {
  // led.drive() MUST be called frequently for blinking
  // and yellow to work (at least once every 10 ms).
  // Otherwise, it will just stay red or green.
  // This means that you should avoid calling delay().
  // Before 10ms, there is no flicker visible
  // At ~10ms, there is a barely noticible `jitter'
  // At ~15ms, the flickering is quite obvious.
  led.drive();
}
