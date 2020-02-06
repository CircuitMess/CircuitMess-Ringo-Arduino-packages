// demonstration of beep function wchich generates
// interruped sounds with defined frequency and length
#include <Arduino.h>
#include <MAKERphone.h>
#include <utility/soundLib/MPWavLib.h>

MAKERphone mp;
Oscillator *osc;

void setup() {
  Serial.begin(115200);
  osc = new Oscillator(3);
  addOscillator(osc);  
  mp.begin(0);
}

void loop() {

  mp.update();
  osc->setVolume(60);
  osc->setWaveform(3);
  // creates beeping sound with 40 frequency for 3 seconds 
  osc->beep(40,3);
  delay(4000);
  osc->setWaveform(0);
  osc->beep(300,3);
  delay(4000);
  osc->stop();
  delay(1000);
}
