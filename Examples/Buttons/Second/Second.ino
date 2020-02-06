// in this example we are going to use some more complex button functions
// that also take into consideration the amount of times a button has been pressed
// and for how long
// including necessary libraries
#include <Arduino.h>
#include <MAKERphone.h>
// button library, located in the subfolder
#include <utility/Buttons/Buttons.h>

MAKERphone mp;

// since our screen is 160x128 pixels, unsigned integers of 8 bits 
// are going to be enough to cover the whole screen (0-255 values)
// setting the rectangle on the center of the screen
uint8_t x = 70;
uint8_t y = 54;
// variables used for changing rectangle color
uint8_t color = 0;
uint32_t col;

void setup() {
  Serial.begin(115200);
  mp.begin(0);

}

void loop() {
  // we're going to draw an object at the middle of the screen
  // and then use buttons to move it
  mp.update();

  // switch case used to change rectangle color
  switch (color) {
  case 0:
    // 0xFFFF is RGB code for white
    col = 0xFFFF;
    break;
  case 1:
    // 0xFFFF is RGB code for red
    col = 0xF800;
    break;
  case 2:
    // 0xFFFF is RGB code for yellow
    col = 0xFFE0;
    break;
  case 3:
    // 0xFFFF is RGB code for cyan
    col = 0x07FF;
    break;
}
  
  // choose a button and a period of reading 
  if(mp.buttons.repeat(BTN_UP,2)) {
    if(y <= 0);
    else y--;
  }
  // changing the second parameter in the repeat function will 
  // alter the speed of the moving object
  if(mp.buttons.repeat(BTN_DOWN,6)) {
    if(y >= 128-20);
    else y++;
  }
    if(mp.buttons.repeat(BTN_RIGHT,0)) {
    if(x >= 160-20);
    // you can also speed up the object movement by changing
    // how much it moves after one button action
    else x+=4;
  }
  if(mp.buttons.repeat(BTN_LEFT,0)) {
    if(x <= 0);
    else x--;
  }
  
  mp.display.fillScreen(TFT_BLACK);
  // draw the rectangle on the specific location
  mp.display.fillRect(x,y,20,20,col);

  // holding down the button 'A' for 1 second (1 period is 40ms, 25 x 40 is 1000ms)
  // will change the rectangle color
  if(mp.buttons.held(BTN_A, 25)) {
    color++;
    color%=4;
  } 

}
