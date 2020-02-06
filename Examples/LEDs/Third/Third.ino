#include <MAKERphone.h>

MAKERphone mp;

void setup() {
  mp.begin(0);
}

void loop() {
  mp.update();
  mp.display.setTextColor(TFT_YELLOW);
  mp.display.setTextFont(2);
  int x = mp.buttons.getJoystickX();
  int y = mp.buttons.getJoystickY();
  mp.display.fillScreen(TFT_BLACK);
  mp.display.setCursor(45,50);
  mp.display.print(x);
  mp.display.setCursor(85,50);
  mp.display.print(y);

  CRGB ledvalue[4];
  ledvalue[0].red = y*255/1100;
  ledvalue[0].green = (x+y)*255/2200;
  ledvalue[0].blue = abs(x-y)*255/1100;
  ledvalue[1].red = ledvalue[0].blue;
  ledvalue[1].green = ledvalue[0].red;
  ledvalue[1].blue = ledvalue[0].green;
  ledvalue[2].red = ledvalue[0].green;
  ledvalue[2].green = ledvalue[0].blue;
  ledvalue[2].blue = ledvalue[0].red;
  ledvalue[3].red = ledvalue[0].blue;
  ledvalue[3].green = ledvalue[0].green;
  ledvalue[3].blue = ledvalue[0].red;
  for(int i=0; i<8; i++) mp.leds[i] = ledvalue[i%4];
}
