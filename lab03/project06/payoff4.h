#ifndef PAYOFF4_H
#define PAYOFF4_H

class PayOff {
 public:
  PayOff() {};

  virtual double operator()(double spot) const = 0;
  virtual ~PayOff() {}
  virtual PayOff* clone()
      const = 0;  // return a pointer 在不知道对象具体类型的情况下，创建它的副本

 private:
};

class PayOffCall : public PayOff {
 public:
  PayOffCall(double strike_);

  virtual double operator()(double spot) const;
  virtual ~PayOffCall() {}
  virtual PayOff* clone() const;

 private:
  double strike;
};

class PayOffPut : public PayOff {
 public:
  PayOffPut(double strike_);
  virtual double operator()(double spot) const;
  virtual ~PayOffPut() {}
  virtual PayOff* clone() const;

 private:
  double strike;
};

class PayOffCustomCall : public PayOff {
 public:
  PayOffCustomCall(double strike_);
  virtual double operator()(double spot) const;
  virtual ~PayOffCustomCall() {}
  virtual PayOff* clone() const;

 private:
  double strike;
};

class PayOffCustomPut : public PayOff {
 public:
  PayOffCustomPut(double strike_); 
  virtual double operator()(double spot) const; 
  virtual ~PayOffCustomPut() {}
  virtual PayOff* clone() const;

 private:
  double strike;
};

#endif
