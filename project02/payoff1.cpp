// payoff1.cpp

#include "payoff1.h"

#include <cmath>

#include "min_max.h"

Payoff::Payoff(double strike, double strike2, OptionType option_type)
    : strike_(strike), strike2_(strike2), option_type_(option_type) {
  if (strike_ > strike2_) {
    double tmp;
    tmp = strike_;
    strike_ = strike2_;
    strike2_ = tmp;
  }
}

double Payoff::operator()(double spot) const {
  switch (option_type_) {
    case Call:
      return max(spot - strike_, 0.0);

    case Put:
      return max(strike_ - spot, 0.0);

    case DoubleDigital:
      if ((spot > strike_) && (spot < strike2_)) {
        return 1.0;
      } else {
        return 0.0;
      }

    case DigitalCall:
      return spot >= strike_ ? 1.0 : 0.0;

    case DigitalPut:
      return spot <= strike_ ? 1.0 : 0.0;

    case PowerCall1:
      return max(spot - strike_, 0.0) * max(spot - strike_, 0.0);

    case PowerPut1:
      return max(strike_ - spot, 0.0) * max(strike_ - spot, 0.0);

    case PowerCall2:
      return max(pow(spot,2) - pow(strike_,2), 0.0);

    case PowerPut2:
      return max(pow(strike_,2) - pow(spot,2), 0.0);

    default:
      throw("Unknown option type found.");
  }
}
