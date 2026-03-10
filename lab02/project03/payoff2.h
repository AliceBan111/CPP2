#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff {
 public:
  PayOff() = default;
  virtual double operator()(double spot) const = 0;
  virtual ~PayOff() = default;
};

class PayOffCall : public PayOff {
 public:
  PayOffCall(double strike);
  double operator()(double spot) const override;

 private:
  double strike;
};

class PayOffPut : public PayOff {
 public:
  PayOffPut(double strike);
  double operator()(double spot) const override;

 private:
  double strike;
};

class PayOffDigitalCall : public PayOff {
 public:
  PayOffDigitalCall(double strike);
  double operator()(double spot) const override;

 private:
  double strike;
};

class PayoffDoubleDigital : public PayOff {
 public:
  PayoffDoubleDigital(double strike, double upper_strike);
  double operator()(double spot) const override;

 private:
  double strike;
  double upper_strike;
};

class PayoffPowerCall1 : public PayOff {
 public:
  PayoffPowerCall1(double strike);
  double operator()(double spot) const override;

 private:
  double strike;
};

class PayoffPowerPut1 : public PayOff {
 public:
  PayoffPowerPut1(double strike);
  double operator()(double spot) const override;

 private:
  double strike;
};

class PayoffPowerCall2 : public PayOff {
 public:
  PayoffPowerCall2(double strike);
  double operator()(double spot) const override;

 private:
  double strike;
};

class PayoffPowerPut2 : public PayOff {
 public:
  PayoffPowerPut2(double strike);
  double operator()(double spot) const override;

 private:
  double strike;
};

#endif