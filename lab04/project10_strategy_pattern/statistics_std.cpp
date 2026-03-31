#include "statistics_std.h"

#include <cmath>

using namespace std;

StatisticsStd::StatisticsStd() {}

void StatisticsStd::dump_one_result(double result) {
  payoffs.push_back(result);
}

vector<vector<double>> StatisticsStd::get_results_so_far() const {
  vector<vector<double>> Results(1);

  double average_payoff = get_average_payoff();
  double std_payoff = get_std_payoff();
  double std_error = get_standard_error();
  double CI = get_confidence_interval();

  Results[0].push_back(average_payoff);
  Results[0].push_back(std_payoff);
  Results[0].push_back(std_error);
  Results[0].push_back(CI);

  return Results;
}

double StatisticsStd::get_average_payoff() const{
  double running_sum = 0.0;
  for (unsigned long i = 0; i < payoffs.size(); i++) {
    running_sum += payoffs[i];
  }
  return running_sum / payoffs.size();
}

double StatisticsStd::get_std_payoff() const{
  double running_sum = 0.0;
  double mean = get_average_payoff();
  for (unsigned long i = 0; i < payoffs.size(); i++) {
    running_sum += (payoffs[i] - mean) * (payoffs[i] - mean);
  }
  return sqrt(running_sum / payoffs.size());
}

double StatisticsStd::get_standard_error() const{
  return get_std_payoff() / sqrt(payoffs.size()-1);
}

double StatisticsStd::get_confidence_interval() const{
  return 1.96 * get_standard_error();
}

StatisticsMC* StatisticsStd::clone() const { return new StatisticsStd(*this); }