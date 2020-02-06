// some of the more advanced functions of Ringo's display library are shown here
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
  // update function refreshes screen 25 times per second
  // so when it's not running, you set what you want on the screen
  mp.update();
  // setting the whole screen to black, erases everything that has been written
  mp.display.fillScreen(TFT_BLACK);
  // change screen background color
  mp.display.fillScreen(TFT_WHITE);
  // set desired font
  mp.display.setTextFont(1);
    // set desired text size
  mp.display.setTextSize(1);
  // set cursor to a specific place (160x128)
  mp.display.setCursor(10,40);
  // set desired font color
  mp.display.setTextColor(TFT_BLACK);
  // print 'Now it's time to change ' on the screen
  mp.display.print("Now it's time to change ");
  // set cursor to a specific place (160x128)
  mp.display.setCursor(10,48);
  // set desired font color
  mp.display.setTextColor(TFT_RED);
  // print 'colors...' on the screen
  mp.display.print("colors...");
  // set desired font
  mp.display.setTextFont(2);
  // set cursor to a specific place (160x128)
  mp.display.setCursor(10,56);
  // print 'And fonts!' on the screen
  mp.display.print("And fonts!");
  // set cursor to a specific place (160x128)
  mp.display.setCursor(10,70);
  // set desired text size
  mp.display.setTextSize(2);
  // print 'And SIZE!' on the screen
  mp.display.print("And SIZE!");
}
