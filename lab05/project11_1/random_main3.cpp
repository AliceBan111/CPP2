#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "antithetic.h"
#include "conf_limits.h"
#include "convergence_table.h"
#include "helpers.h"
#include "park_miller.h"
#include "simple_mc8.h"
#include "statistics_mc.h"
#include "vanilla3.h"

using namespace std;

int main() {
  srand(time(NULL));  // pricer is dependent on random numbers.
                      // unsigned long baseSeed = rand();
  // unsigned long baseSeed = 123;
  unsigned long baseSeed;
  cout << "Enter seed for generator (0 for randomized): ";
  cin >> baseSeed;

  if (baseSeed == 0) {
    baseSeed = time(NULL);
    cout << "Using randomized seed: " << baseSeed << endl;
  }

  double expiry = 0.5;
  double strike = 100;
  double spot = 95;
  double vol = 0.2;
  double r = 0.06;
  unsigned long number_of_paths = 10000;  // 减少两个0，std增加10倍
  unsigned int number_of_experiments =
      100;  // std不会因为这个增加而减少，precision of estimate会增加

  PayOffCall the_payoff(strike);
  VanillaOption the_option(the_payoff, expiry);

  ParametersConstant VolParam(vol);
  ParametersConstant rParam(r);

  // ==================================================
  cout << "\nWe have the following parameters:\n";
  cout << "expiry           = " << expiry << "\n";
  cout << "strike           = " << strike << "\n";
  cout << "spot             = " << spot << "\n";
  cout << "vol              = " << vol << "\n";
  cout << "r                = " << r << "\n";
  cout << "number_of_paths  = " << number_of_paths << "\n";

  // ==================================================
  // pricing without antithetic variates
  // ConfidenceLimits gatherer1;
  StatisticsMean gatherer1;
  ConvergenceTable table(gatherer1);
  RandomParkMiller generator1(1);

  // generator1.set_seed(124);
  // generator1.set_seed(rand());
  vector<double> prices;
  for (unsigned int i = 0; i < number_of_experiments; i++) {
    gatherer1.reset();
    generator1.set_seed(123 + i);
    simple_monte_carlo8(the_option, spot, VolParam, rParam, number_of_paths,
                        gatherer1, generator1);

    prices.push_back(gatherer1.get_results_so_far()[0][0]);
    // vector<vector<double>> result = gatherer1.get_results_so_far();
  }
  cout << "\nFor the call price the results are: \n";
  // print_results(result);
  cout << "Mean price: " << get_vec_mean(prices) << "\n";
  cout << "Standard deviation of price: " << get_vec_stddev(prices) << "\n";

  return 0;
}
