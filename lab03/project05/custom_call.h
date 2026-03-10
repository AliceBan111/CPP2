#pragma once
#include "payoff3.h"

class PayOffCustomCall : public PayOff {
 public:
  // construtor
  PayOffCustomCall(double strike_); 
  // method (function)
  virtual double operator()(double spot) const; 
  // destructor
  virtual ~PayOffCustomCall() {}

 private:
  // member (attribute)
  double strike;
};