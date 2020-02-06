// here are some examples of the button usage
// since pressing buttons is the base of everything else happening,
// there will be actions where pressed buttons will print something out,
// play a sound or light up the LED, so we would recommend getting
// familiar with those first

// including necessary libraries
#include <Arduino.h>
#include <MAKERphone.h>
// button library, located in the subfolder
#include <utility/Buttons/Buttons.h>

MAKERphone mp;

void setup() {
  Serial.begin(115200);
  mp.begin(0);

}

void loop() {
  // we're going to draw an object at the middle of the screen
  // and then use buttons to move it
  while(!mp.update());
  
  // we're going to use the buttons to print different words on the screen
  // phone checks if the button was pressed and returns true value if it was
  if(mp.buttons.pressed(BTN_A)){
    mp.display.fillScreen(TFT_BLACK);
    mp.display.setTextColor(TFT_WHITE);
    mp.display.setTextFont(2);
    mp.display.setCursor(30, 15);
    mp.display.print("You've pressed");
    mp.display.setCursor(30, 30);
    mp.display.print("the 'A' button.");
  }

    // if the button is pressed, clear the screen and write out which button has been pressed
    if(mp.buttons.pressed(BTN_B)){
    mp.display.fillScreen(TFT_BLACK);
    mp.display.setTextColor(TFT_WHITE);
    mp.display.setTextFont(2);
    mp.display.setCursor(30, 70);
    mp.display.print("You've pressed");
    mp.display.setCursor(30, 85);
    mp.display.print("the 'B' button."); 
  }
 
}
