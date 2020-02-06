// demonstration of different waveforms
// with the same note and the the same frequency 
#include <Arduino.h>
#include <MAKERphone.h>
#include <utility/soundLib/MPWavLib.h>

MAKERphone mp;
Oscillator *osc;

void setup() {
  Serial.begin(115200);
  // waveform is set to 0 - SINE
  osc = new Oscillator(0);
  addOscillator(osc);  
  mp.begin(0);
}

void loop() {

  mp.update();
  osc->setVolume(50);
  osc->setFrequency(100);
  osc->note(50,1);
  delay(2000);
  // set waveform to 1 - TRIANGLE
  osc->setWaveform(1);
  osc->note(50,1);
  delay(2000);
    // set waveform to 2 - SQUARE
  osc->setWaveform(2);
  osc->note(50,1);
  delay(2000);
    // set waveform to 4 - SAW
  osc->setWaveform(3);
  osc->note(50,1);
  delay(2000);
    // set waveform to 4 - NOISE
  osc->setWaveform(4);
  osc->note(50,1);
  delay(2000);
}
