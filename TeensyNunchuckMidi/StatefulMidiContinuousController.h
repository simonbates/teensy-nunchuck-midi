class StatefulMidiContinuousController {
public:
  StatefulMidiContinuousController(int control, int channel) :
    control_(control), channel_(channel), value_(0) { }

  void sendIfChanged(int value)
  {
    if (value != value_) {
      value_ = value;
      usbMIDI.sendControlChange(control_, value_, channel_);
    }
  }

private:
  int control_;
  int channel_;
  int value_;
};
