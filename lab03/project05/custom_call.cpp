#include "custom_call.h"

#include "minmax.h"

// definition of a constructor
PayOffCustomCall::PayOffCustomCall(double strike_) { strike = strike_; }

// definition of a function
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