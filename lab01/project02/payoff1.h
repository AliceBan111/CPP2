// payoff1.h

#ifndef PAYOFF1_H
#define PAYOFF1_H

class  Payoff {
 public:
  enum OptionType { Call, Put, DoubleDigital, DigitalCall, DigitalPut, PowerCall1, PowerPut1, PowerCall2, PowerPut2  };  
  Payoff(double strike, double strike2, OptionType option_type);

  double operator()(double spot) const;

 private:
  double strike_;
  double strike2_;
  OptionType option_type_;
};

#endif
