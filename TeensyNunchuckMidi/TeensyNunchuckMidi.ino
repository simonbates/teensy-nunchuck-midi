#include "ExponentialMovingAverage.h"
#include "StatefulMidiContinuousController.h"
#include "WiiNunchuck.h"

// TODO: Map analog stick X and Y actual range to [0, 127]

const int midiChannel = 1;
const int analogStickX_control = 0;
const int analogStickY_control = 1;
const int roll_control = 2;
const int pitch_control = 3;

const int updateDelayMs = 10;
const float smoothingFactor = 0.15f;

WiiNunchuck chuck;

ExponentialMovingAverage<float> roll(smoothingFactor);
ExponentialMovingAverage<float> pitch(smoothingFactor);

StatefulMidiContinuousController analogStickXController(analogStickX_control, midiChannel);
StatefulMidiContinuousController analogStickYController(analogStickY_control, midiChannel);
StatefulMidiContinuousController rollController(roll_control, midiChannel);
StatefulMidiContinuousController pitchController(pitch_control, midiChannel);

void setup()
{
  chuck.begin();
}

void loop()
{
  chuck.update(updateDelayMs);

  roll.update((chuck.roll() / 2.0f + 0.5f) * 127.0f);
  pitch.update((chuck.pitch() + 0.5f) * 127.0f);

  analogStickXController.sendIfChanged(chuck.analogStickX / 2);
  analogStickYController.sendIfChanged(chuck.analogStickY / 2);
  rollController.sendIfChanged(roll.value());
  pitchController.sendIfChanged(pitch.value());
}
