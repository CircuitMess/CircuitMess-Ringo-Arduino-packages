// objects can be drawn on top of each other
// allowing you to create more complex shapes
// include libraries
#include <Arduino.h>
#include <MAKERphone.h>
// creating an object 
MAKERphone mp;


// the setup starts when Ringo is booted up
void setup() {

  // initialize serial port
  Serial.begin(115200);
  // initialize Ringo 
  mp.begin(0);
  
}

// loop routine runs again and again, until the program is stopped
void loop() {
  // here we're going to write a couple of letters over a circle shape
  // and then have animated circles go around the screen
  // also here's an example how an animated shape can have it's trail
  // permanently drawn on the screen
  mp.display.fillScreen(TFT_WHITE);
  for(int i = 0; i < 180; i++){
  // there is no fillScreen function so the screen doesn't refresh
  // after each loop
  while(!mp.update());
  mp.display.fillRect(0,12,10+i,8,TFT_NAVY);
  mp.display.fillRect(0,113,10+i,8,TFT_NAVY);
  
  }
  for(int i = 0; i < 360; i++){
  mp.update();
  mp.display.fillScreen(TFT_WHITE);
  mp.display.fillCircle(45, 64, 35, TFT_BLACK);
  mp.display.setTextColor(TFT_ORANGE);
  mp.display.setCursor(20, 44);
  mp.display.setTextFont(2);
  mp.display.setTextSize(3);
  mp.display.print("CM");
  // you can combine shapes and letters on the screen in many ways
  // and even re-create some cool real life logos
  mp.display.setCursor(85, 50);
  mp.display.setTextFont(2);
  mp.display.setTextSize(1);
  mp.display.setTextColor(TFT_NAVY);
  mp.display.print("CircuitMess");
  mp.display.setCursor(85, 70);
  mp.display.setFreeFont(TT1);
  mp.display.setTextSize(1);
  mp.display.setTextColor(TFT_NAVY);
  mp.display.print("Mess is more.");
  mp.display.fillRect(0,12,160,8,TFT_NAVY);
  mp.display.fillRect(0,113,160,8,TFT_NAVY);
  mp.display.drawCircle(-20+i, 64, 20, TFT_CYAN);
  mp.display.drawCircle(-60+i, 64, 20, TFT_DARKCYAN);
  mp.display.drawCircle(-100+i, 64, 20, TFT_CYAN);
  mp.display.drawCircle(-140+i, 64, 20, TFT_DARKCYAN);
  mp.display.drawCircle(-180+i, 64, 20, TFT_CYAN);
  if(i == 359) i = 0;
  }
}
