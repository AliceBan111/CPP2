#include "mc_pricing.h"

#include <algorithm>
#include <cmath>
#include <iostream>

double get_one_gaussian_by_box_muller() {
  double x;
  double y;

  double size_squared;
  do {
    x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
    y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
    size_squared = x * x + y * y;
  } while (size_squared >= 1.0);

  double result = x * sqrt(-2 * log(size_squared) / size_squared);

  return result;
}

double monteCarloPrice(double S, double X, double r, double sigma, double T,
                       bool isCall, unsigned long paths) {
  double sumPayoff = 0.0;

  for (unsigned long i = 0; i < paths; i++) {
    double epsilon = get_one_gaussian_by_box_muller();

    double ST =
        S * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * epsilon);

    double payoff;
    if (isCall) {
      payoff = std::max(ST - X, 0.0);
    } else {
      payoff = std::max(X - ST, 0.0);
    }

    sumPayoff += payoff;
  }

  double meanPayoff = sumPayoff / paths;
  double price = exp(-r * T) * meanPayoff;

  return price;
}

double monteCarloByValue(OptionData opt, unsigned long paths) {
  return monteCarloPrice(opt.spot, opt.strike, opt.r, opt.vol, opt.expiry,
                         opt.isCall, paths);
}
double monteCarloByPointer(const OptionData* opt, unsigned long paths){
  return monteCarloPrice(opt->spot, opt->strike, opt->r, opt->vol, opt->expiry,
                         opt->isCall, paths);
}
double monteCarloByReference(const OptionData& opt, unsigned long paths){
  return monteCarloPrice(opt.spot, opt.strike, opt.r, opt.vol, opt.expiry,
                         opt.isCall, paths);
}
