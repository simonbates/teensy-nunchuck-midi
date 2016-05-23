#include "WiiNunchuck.h"

// TODO: Map analog stick X and Y actual range to [0, 127]

const int midiChannel = 1;
const int analogStickX_control = 0;
const int analogStickY_control = 1;
const int roll_control = 2;
const int pitch_control = 3;

const int updateDelayMs = 20;

WiiNunchuck chuck;

void setup()
{
  chuck.begin();
}

void loop()
{
  chuck.update(updateDelayMs);
  usbMIDI.sendControlChange(analogStickX_control, chuck.analogStickX / 2, midiChannel);
  usbMIDI.sendControlChange(analogStickY_control, chuck.analogStickY / 2, midiChannel);
  usbMIDI.sendControlChange(roll_control, (chuck.roll() / 2.0f + 0.5f) * 127.0f, midiChannel);
  usbMIDI.sendControlChange(pitch_control, (chuck.pitch() + 0.5f) * 127.0f, midiChannel);
}

