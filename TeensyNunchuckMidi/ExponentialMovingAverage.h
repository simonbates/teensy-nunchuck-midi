template <typename T> class ExponentialMovingAverage {
public:
  ExponentialMovingAverage(T smoothingFactor) :
    smoothingFactor_(smoothingFactor), value_(0) { }

  void update(T input)
  {
    value_ = (smoothingFactor_ * input) + ((1.0 - smoothingFactor_) * value_);
  }

  T value()
  {
    return value_;
  }

private:
  T smoothingFactor_;
  T value_;
};
