// oscillator is a tool that generates sound waves in a different shape
// and at different speeds, allowing you to create some interesting
// sounds for your apps
#include <Arduino.h>
#include <MAKERphone.h>
// icluding MPWavLib.h that is located in a subfolder
#include <utility/soundLib/MPWavLib.h>

// declaration of the phone and oscillator 
MAKERphone mp;
// oscillator is a pointer, so accessing it's functions
// has to be done with an arrow (ex. osc->setVolume()) and not
// with a dot (ex. mp.begin())
Oscillator *osc;

void setup() {
  Serial.begin(115200);
  osc = new Oscillator(2);
  // adding oscillator to the phone
  addOscillator(osc);  
  mp.begin(0);
}

void loop() {
  mp.update();
  // setting the volume (0-128)
  osc->setVolume(30);
  // setting the frequency of the wave
  osc->setFrequency(600);
  // playing the note for one second
  osc->note(100,1);
  // 1.5 second delay
  delay(1500);
  // stopping the oscillator
  osc->stop();
  delay(1500);

}
