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
  mp.pixelsBrightness = 2;
  // LEDs are initialized in the begin function, so their initialization is not necessary
  // however, addLeds function is how you would do it if that wasn't the case
  // initialize LEDs, constants NEOPIXEL and PIXELPIN are defined in loaded libraries
  //FastLED.addLeds<NEOPIXEL, PIXELPIN>(leds,8);
  
}

// loop routine runs again and again, until the program is stopped
void loop() {

  /*for(int i = 0; i < 8; i++){
    for(int j = 0;j <= i; j++){
    mp.leds[j] = CRGB(random(0,255),random(0,255),random(0,255));
    }
    delay(1000);
    mp.update();
  }*/

  FastLED.showColor(CRGB::RED, uint8_t scale)
  

  // setBrightness is activated in update function and depends on pixelsBrightness 
  // FastLED.setBrightness(50);
  // FastLED.show() function is activated in update function so there is no need
  // to call it
  for(int i = 0; i < 8; i++){
    mp.leds[i] = CRGB(0,0,0);
  }
  mp.update();

}
