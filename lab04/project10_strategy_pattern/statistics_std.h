#pragma once
#include <vector>

#include "statistics_mc.h"

class StatisticsStd : public StatisticsMC {
 public:
  StatisticsStd();
  virtual void dump_one_result(double result);
  virtual std::vector<std::vector<double>> get_results_so_far() const;
  virtual StatisticsMC* clone() const;
  double get_average_payoff() const;
  double get_std_payoff() const;
  double get_standard_error() const;
  double get_confidence_interval() const;

 private:
  std::vector<double> payoffs;
};
