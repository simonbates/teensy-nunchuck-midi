Teensy Wii Nunchuck MIDI controller
===================================

This project contains code and information for making a
Teensy-based Wii Nunchuck MIDI controller.

Parts
-----

- Wii Nunchuck controller
- [Teensy](http://www.pjrc.com/teensy/index.html) (I'm using version 3.2)
- [WiiChuck adapter](http://todbot.com/blog/2008/02/18/wiichuck-wii-nunchuck-adapter-available/)
- Two 4.7K resistors
- Breadboard (or some other means of wiring the components)
- Header pins for the WiiChuck adapter

Circuit
-------

![Circuit schematic](schematic.png)

- Connect the WiiChuck '-' to GND
- Connect the WiiChuck '+' to 3.3V
- Connect the WiiChuck 'D' to the Teensy SDA0
- Connect the WiiChuck 'C' to the Teensy SCL0
- Use 4.7K pullup resistors on SCL0 and SDA0

Software
--------

### Install the Arduino IDE and Teensyduino

Install the [Arduino IDE](https://www.arduino.cc/) and the
[Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) add-on for
the Arduino IDE.

### Build the code and upload to the Teensy

- Open the TeensyNunchuckMidi sketch
- Select "MIDI" from the Tools / USB Type menu
- Run Verify/Compile
- Push the button on the Teensy to upload

MIDI
----

The Teensy sketch sends analog stick position and Nunchuck roll and
pitch orientation as MIDI control change events. The channel number
and control numbers are specified in constants at the top of the
`TeensyNunchuckMidi.ino` file.

The default channel number is 1.

The default control assignments are:

| Value | Control number |
|-------|----------------|
| Analog stick X | 0 |
| Analog stick Y | 1 |
| Roll | 2 |
| Pitch | 3 |

Acknowledgments and Resources
-----------------------------

The code for interfacing with the Nunchuck controller is based on:

- [Tim Hirzel's WiiChuck class on Arduino Playground](http://playground.arduino.cc/Main/WiiChuckClass)
- [Tod E. Kurt's wiichuck_adapter project](https://github.com/todbot/wiichuck_adapter)

Further information on the protocol for interfacing with the Nunchuck
controller can be found at the following:

- [Nunchuck information at WiiBrew](http://wiibrew.org/wiki/Wiimote/Extension_Controllers/Nunchuck)
- [CoD4 Nunchuk Leaner](http://michael.lesauvage.name/cod4-nunchuk-leaner/)

Resources for Teensy programming:

- [Wire Arduino Library on Teensy](https://www.pjrc.com/teensy/td_libs_Wire.html)
- [USB MIDI on Teensy](https://www.pjrc.com/teensy/td_midi.html)

License
-------

This project is distributed under the terms of the MIT License.
