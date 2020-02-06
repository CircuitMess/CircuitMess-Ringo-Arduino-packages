// in this example we are going to use some more complex button functions
// that also take into consideration the amount of times a button has been pressed
// and for how long
// including necessary libraries
#include <Arduino.h>
#include <MAKERphone.h>
// button library, located in the subfolder
#include <utility/Buttons/Buttons.h>
// LED libraries, located in the subfolder
#include <FastLED/FastLED.h>
#include <FastLED/pixeltypes.h>

MAKERphone mp;

// variables used for measuring length of a button press
uint16_t time1;
double time2;
uint16_t time3;

void setup() {
  Serial.begin(115200);
  mp.begin(0);
  mp.pixelsBrightness = 2;

}

void loop() {
// here we are going to count for how many seconds
// you held a specific button
 mp.update();
 

mp.display.fillScreen(TFT_BLACK);
mp.display.setTextFont(2);
mp.display.setTextSize(3);
mp.display.setTextColor(TFT_WHITE);
mp.display.setCursor(5, 34);
// when the button 'A' is released, create a 2 second delay
// so the final time appears on the screen
if(mp.buttons.released(BTN_A)) delay(2000);
// measures how many times has the screen been refreshed
// since the button was pressed
time1 = mp.buttons.timeHeld(BTN_A);
// update function refreshes the screen approximately 50 times a second
// be careful if you're using while(!mp.update()) because it refreshes the screen
// at a different rate
mp.display.print((double) time1/50);
mp.display.print(" s");

// you can also combine pressing buttons with LEDs
time3 = mp.buttons.timeHeld(BTN_B);
time2 = (double) time3/50;

  if (time2 >0 && time2 <=1){
    for(int i = 0; i < 8; i++){
    mp.leds[i] = CRGB::WhiteSmoke;
    }
  }
  else if(time2 >1 && time2 <=2){
    for(int i = 0; i < 8; i++){
    mp.leds[i] = CRGB::BlueViolet;
    }
  }
  else if(time2 >2 && time2 <=3){
    for(int i = 0; i < 8; i++){
    mp.leds[i] = CRGB::LawnGreen;
    }
  }
  else if(time2 >3 && time2 <=4){
    for(int i = 0; i < 8; i++){
    mp.leds[i] = CRGB::DarkOrange;
    }
  }
  else if(time2 > 4){
    for(int i = 0; i < 8; i++){
    mp.leds[i] = CRGB::Cyan;
    }
  }
  else
    for(int i = 0; i < 8; i++){
    mp.leds[i] = CRGB::Black;
    }
}
