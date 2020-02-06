// now it is time to start with some animations
// include libraries
#include <Arduino.h>
#include <MAKERphone.h>
// creating an object 
MAKERphone mp;
int i;
// the setup starts when Ringo is booted up
void setup() {

  // initialize serial port
  Serial.begin(115200);
  // initialize Ringo 
  mp.begin(1);
  
}

// loop routine runs again and again, until the program is stopped
void loop() {
  // here we are going to create a circle that travels around the screen and bounces off the walls
  mp.update();
  mp.display.fillScreen(TFT_WHITE);
  mp.display.fillCircle(65, 49, 15, TFT_ORANGE);
  for(i=1; i<=143; i++){
    // clear the screen everytime the loop repeats, so the old drawn object is deleted from the screen
    mp.display.fillScreen(TFT_WHITE);
    // circle's starting position is off the screen, so it gets the effect of 'flying in'
    mp.display.fillCircle(1+i, -15+i, 15, TFT_ORANGE);
    // update function in the for loop refreshes the screen everytime it loops, allowing you to create moving objects
    while(!mp.update());
  }
  // circle travels until it hits the wall for the first time
  for(i=1; i<=16; i++){
    mp.display.fillScreen(TFT_WHITE);
    mp.display.drawCircle(144+i, 128-i, 15, TFT_ORANGE);
    while(!mp.update());
  }
  // change of direction
  for(i=1; i<=112; i++){
    mp.display.fillScreen(TFT_WHITE);
    // circle's color is changed
    mp.display.fillCircle(160-i,112-i , 15, TFT_NAVY);
    while(!mp.update());
  }
  for(i=1; i<=48; i++){
    mp.display.fillScreen(TFT_WHITE);
    mp.display.drawCircle(48-i, 0+i, 15, TFT_NAVY);
    while(!mp.update());
  }
  for(i=1; i<=80; i++){
    mp.display.fillScreen(TFT_WHITE);
    mp.display.fillCircle(0+i, 48+i, 15, TFT_ORANGE);
    while(!mp.update());
  }
  for(i=1; i<=110; i++){
    mp.display.fillScreen(TFT_WHITE);
    mp.display.drawCircle(80+i, 128-i, 15, TFT_ORANGE);
    while(!mp.update());
  }
  // circle goes off the screen and the whole process repeats in the main loop
}
