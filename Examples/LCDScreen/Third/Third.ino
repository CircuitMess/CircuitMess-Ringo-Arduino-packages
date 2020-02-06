// drawing objects is next and we can do it in a couple of ways
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
  mp.update();
  mp.display.fillScreen(TFT_WHITE);
  // you can write out different shapes on the screen
  // draw a rectangle
  mp.display.drawRect(20, 20, 20, 20, TFT_DARKGREEN);
  // draw a filled rectangle
  mp.display.fillRect(60, 20, 20, 20, TFT_GREEN);
  // draw a circle
  mp.display.drawCircle(30, 60, 10, TFT_NAVY);
  // draw a filled circle
  mp.display.fillCircle(70, 60, 10, TFT_BLUE);
  // draw a triangle
  mp.display.drawTriangle(30, 80, 20, 100, 40, 100, TFT_MAROON);
  // draw a filled triangle
  mp.display.fillTriangle(70, 80, 60, 100, 80, 100, TFT_RED);

  // you can also draw custom shapes pixel-by-pixel using the drawPixel()
  // and drawLine() functions
 {
  // drawing the infinity symbol
  mp.display.drawLine(110,62,110,66,TFT_BLACK);
  mp.display.drawPixel(111, 61, TFT_BLACK);
  mp.display.drawPixel(111, 67, TFT_BLACK);
  mp.display.drawPixel(112, 60, TFT_BLACK);
  mp.display.drawPixel(112, 68, TFT_BLACK);
  mp.display.drawPixel(113, 59, TFT_BLACK);
  mp.display.drawPixel(113, 69, TFT_BLACK);
  mp.display.drawLine(114,70,116,70,TFT_BLACK);
  mp.display.drawLine(114,58,116,58,TFT_BLACK);
  mp.display.drawLine(117,59,120,62,TFT_BLACK);
  mp.display.drawLine(117,69,120,66,TFT_BLACK);
  mp.display.drawLine(121,63,121,65,TFT_BLACK);
  // now the other side
  mp.display.drawLine(122,62,125,59,TFT_BLACK);
  mp.display.drawLine(122,66,125,69,TFT_BLACK);
  mp.display.drawLine(126,58,128,58,TFT_BLACK);
  mp.display.drawLine(126,70,128,70,TFT_BLACK);
  mp.display.drawPixel(129, 59, TFT_BLACK);
  mp.display.drawPixel(129, 69, TFT_BLACK);
  mp.display.drawPixel(130, 60, TFT_BLACK);
  mp.display.drawPixel(130, 68, TFT_BLACK);
  mp.display.drawPixel(131, 61, TFT_BLACK);
  mp.display.drawPixel(131, 67, TFT_BLACK);
  mp.display.drawLine(132,62,132,66,TFT_BLACK);
 }
 
 mp.display.setFreeFont(TT1);
 mp.display.setTextColor(TFT_BLACK);
 mp.display.setCursor(110, 80);
 mp.display.print("Infinity");
 mp.display.setCursor(110, 87);
 mp.display.print("symbol");
}
