// PayOff3.cpp

#include "payoff4.h"

#include "minmax.h"

PayOffCall::PayOffCall(double strike_) { strike = strike_; }

double PayOffCall::operator()(double spot) const {
  return max(spot - strike, 0.0);
}

PayOff* PayOffCall::clone() const { return new PayOffCall(*this); }

double PayOffPut::operator()(double spot) const {
  return max(strike - spot, 0.0);
}

PayOffPut::PayOffPut(double strike_) : strike(strike_) {}

PayOff* PayOffPut::clone() const { return new PayOffPut(*this); }

PayOffCustomCall::PayOffCustomCall(double strike_, double boostLevel_)
    : strike(strike_), boostLevel(boostLevel_) {}

double PayOffCustomCall::operator()(double spot) const {
  if (spot <= boostLevel) {
    return max(spot - strike, 0.0);
  } else {
    return 2 * max(spot - strike, 0.0);
  }
}

PayOff* PayOffCustomCall::clone() const { return new PayOffCustomCall(*this); }

PayOffCustomPut::PayOffCustomPut(double strike_, double boostLevel_)
    : strike(strike_), boostLevel(boostLevel_) {}

double PayOffCustomPut::operator()(double spot) const {
  if (spot >= strike) {
    return max(boostLevel - spot, 0.0);
  } else {
    return 2 * max(boostLevel - spot, 0.0);
  }
}

PayOff* PayOffCustomPut::clone() const { return new PayOffCustomPut(*this); }
