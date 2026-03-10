#include "payoff2.h"

#include <algorithm>
#include <cmath>

PayOffCall::PayOffCall(double strike) : strike(strike) {}

double PayOffCall::operator()(double spot) const {
  return std::max(spot - strike, 0.0);
}

PayOffPut::PayOffPut(double strike) : strike(strike) {}

double PayOffPut::operator()(double spot) const {
  return std::max(strike - spot, 0.0);
}

PayOffDigitalCall::PayOffDigitalCall(double strike) : strike(strike) {}

double PayOffDigitalCall::operator()(double spot) const {
  if (spot > strike) {
    return 1.0;
  } else {
    return 0.0;
  }
}

PayoffDoubleDigital::PayoffDoubleDigital(double lower_strike,
                                         double upper_strike)
    : strike(strike), upper_strike(upper_strike) {}

double PayoffDoubleDigital::operator()(double spot) const {
  if ((spot > strike) && (spot < upper_strike)) {
    return 1.0;
  } else {
    return 0.0;
  }
}

PayoffPowerCall1::PayoffPowerCall1(double strike) : strike(strike) {}

double PayoffPowerCall1::operator()(double spot) const {
  return std::max(spot - strike, 0.0) * std::max(spot - strike, 0.0);
}

PayoffPowerPut1::PayoffPowerPut1(double strike) : strike(strike) {}

double PayoffPowerPut1::operator()(double spot) const {
  return std::max(strike - spot, 0.0) * std::max(strike - spot, 0.0);
}

PayoffPowerCall2::PayoffPowerCall2(double strike) : strike(strike) {}

double PayoffPowerCall2::operator()(double spot) const {
  return std::max(pow(spot,2) - pow(strike,2), 0.0);
}

PayoffPowerPut2::PayoffPowerPut2(double strike) : strike(strike) {}

double PayoffPowerPut2::operator()(double spot) const {
  return std::max(pow(strike,2) - pow(spot,2), 0.0);
}