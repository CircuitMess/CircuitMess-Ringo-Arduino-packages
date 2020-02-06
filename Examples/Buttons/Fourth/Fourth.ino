// this is the last example of buttons usage
// and it demonstrates using buttons together with LEDS and
// LCD screen
#include <Arduino.h>
#include <MAKERphone.h>
#include <utility/Buttons/Buttons.h>
#include <utility/soundLib/MPWavLib.h>
#include <FastLED/FastLED.h>
#include <FastLED/pixeltypes.h>

MAKERphone mp;
// oscillator is used for creating sounds
Oscillator *osc;

// variable a used in second example
int8_t a = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  osc = new Oscillator(SINE);
  addOscillator(osc);
  mp.begin(0);
}

void loop() {
  mp.update();

  mp.display.fillScreen(TFT_BLACK);
  // setting the volume in the 0-128 interval
  osc->setVolume(40);
  // oscillator will make sound when button 'A' is pressed
  if(mp.buttons.repeat(BTN_A,0)) {
  osc->note(80,1);
  }

  // sound is stopped when button 'A' is released
  if(!mp.buttons.repeat(BTN_A,0)) osc->stop();

  // when button 'B' is pressed, everything turns red and 
  // oscillator starts making sounds
  if(mp.buttons.pressed(BTN_B)){
    a*=-1;
    }

  // when button 'B' is pressed again, everything turns off
  if(a > 0){  
    for(int i = 0; i < 8; i++){
      mp.leds[i] = CRGB::IndianRed;
    }
    mp.display.fillScreen(TFT_RED);
    osc->note(100, 2);
  }
}
