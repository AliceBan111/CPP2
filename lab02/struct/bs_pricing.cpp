#include "bs_pricing.h"

#include <iostream>

#include "normdist.h"

double BSCallValue(double S, double X, double r, double sigma, double time) {
  double time_sqrt = sqrt(time);
  double d1 =
      (log(S / X) + r * time) / (sigma * time_sqrt) + 0.5 * sigma * time_sqrt;
  double d2 = d1 - (sigma * time_sqrt);
  double c = S * N(d1) - X * exp(-r * time) * N(d2);
  return c;
}

double BSPutValue(double S, double X, double r, double sigma, double time) {
  double time_sqrt = sqrt(time);
  double d1 =
      (log(S / X) + r * time) / (sigma * time_sqrt) + 0.5 * sigma * time_sqrt;
  double d2 = d1 - (sigma * time_sqrt);
  double p = X * exp(-r * time) * N(-d2) - S * N(-d1);
  return p;
}

double blackScholesByValue(OptionData opt) {
  if (opt.isCall) {
    return BSCallValue(opt.spot, opt.strike, opt.r, opt.vol, opt.expiry);
  } else {
    return BSPutValue(opt.spot, opt.strike, opt.r, opt.vol, opt.expiry);
  }
}

double blackScholesByPointer(const OptionData* opt) {
  if (opt == nullptr) {
    std::cerr << "Error: Null pointer received!" << "\n";
    return 0.0;
  }
  if (opt->isCall) {
    return BSCallValue(opt->spot, opt->strike, opt->r, opt->vol, opt->expiry);
  } else {
    return BSPutValue(opt->spot, opt->strike, opt->r, opt->vol, opt->expiry);
  }
}

double blackScholesByReference(const OptionData& opt) {
  if (opt.isCall) {
    return BSCallValue(opt.spot, opt.strike, opt.r, opt.vol, opt.expiry);
  } else {
    return BSPutValue(opt.spot, opt.strike, opt.r, opt.vol, opt.expiry);
  }
}
