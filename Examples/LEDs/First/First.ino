// there are 8 leds located at the back of the phone
// here are some basic examples of how to use them 
// in a variety of ways
// include libraries
#include <Arduino.h>
#include <MAKERphone.h>
#include <FastLED/FastLED.h>
// important to include pixeltypes.h -- that's where all the colors are defined
#include <FastLED/pixeltypes.h>

CRGB leds[8];

// creating an object 
MAKERphone mp;
// the setup starts when Ringo is booted up
void setup() {

  // initialize serial port
  Serial.begin(115200);
  // initialize Ringo 
  mp.begin(0);
  // pixelsBrightness is set to 0 (0-5) in begin function, so overriding it is necessary
  // in order to see LEDs flash 
  mp.pixelsBrightness = 1;
  // LEDs are initialized in the begin function, so their initialization is not necessary
  // however, addLeds function is how you would do it if that wasn't the case
  // initialize LEDs, constants NEOPIXEL and PIXELPIN are defined in loaded libraries
  //FastLED.addLeds<NEOPIXEL, PIXELPIN>(leds,8);
  
}

// loop routine runs again and again, until the program is stopped
void loop() {
  // set led[0] to Red=255, Green=0, Blue=0
  mp.leds[0] = CRGB(255, 0, 0);
  // set led[1] to Red=255, Green=0, Blue=0...
  mp.leds[1] = CRGB(255, 0, 0);
  mp.leds[2] = CRGB(255, 0, 0);
  mp.leds[3] = CRGB(255, 0, 0);
  mp.leds[4] = CRGB(255, 0, 0);
  mp.leds[5] = CRGB(255, 0, 0);
  mp.leds[6] = CRGB(255, 0, 0);
  mp.leds[7] = CRGB(255, 0, 0);

  // setBrightness is activated in update function and depends on pixelsBrightness 
  // FastLED.setBrightness(50);
  // FastLED.show() function is activated in update function so there is no need
  // to call it
  mp.update();

}
