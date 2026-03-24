#include "statistics_std.h"

#include <cmath>

using namespace std;

StatisticsStd::StatisticsStd() {}

void StatisticsStd::dump_one_result(double result) {
  payoffs.push_back(result);
}

vector<vector<double>> StatisticsStd::get_results_so_far() const {
  vector<vector<double>> Results(2);

  Results[0].resize(1);  // 为什么要resize？
  Results[0][0] = get_average_payoff();

  Results[1].resize(1);
  Results[1][0] = get_std_payoff();

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

StatisticsMC* StatisticsStd::clone() const { return new StatisticsStd(*this); }