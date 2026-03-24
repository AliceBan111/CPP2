// PayOff3.cpp

#include "payoff4.h"

#include "minmax.h"

PayOffCall::PayOffCall(double strike_) { strike = strike_; }

double PayOffCall::operator()(double spot) const {
  return max(spot - strike, 0.0);
}

PayOff* PayOffCall::clone() const {
  return new PayOffCall(*this);  // pointer to itself
}

double PayOffPut::operator()(double spot) const {
  return max(strike - spot, 0.0);
}

PayOffPut::PayOffPut(double strike_) : strike(strike_) {}

PayOff* PayOffPut::clone() const { return new PayOffPut(*this); }

PayOffCustomCall::PayOffCustomCall(double strike_) { strike = strike_; }

double PayOffCustomCall::operator()(double spot) const {
  if (spot / strike <= 1.0) {
    return 0.0;
  } else if (spot / strike <= 1.05) {
    return 1.0;
  } else if (spot / strike <= 1.1) {
    return 2.0;
  } else {
    return 3.0;
  }
}

PayOff* PayOffCustomCall::clone() const { return new PayOffCustomCall(*this); }

PayOffCustomPut::PayOffCustomPut(double strike_) { strike = strike_; }

double PayOffCustomPut::operator()(double spot) const {
  if (spot / strike >= 1.0) {
    return 0.0;
  } else if (spot / strike >= 0.95) {
    return 1.0;
  } else if (spot / strike >= 0.9) {
    return 2.0;
  } else {
    return 3.0;
  }
}

PayOff* PayOffCustomPut::clone() const { return new PayOffCustomPut(*this); }
