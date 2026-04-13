#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "antithetic.h"
#include "convergence_table.h"
#include "helpers.h"
#include "park_miller.h"
#include "simple_mc8.h"
#include "statistics_mc.h"
#include "vanilla3.h"

using namespace std;

int main() {
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
    unsigned long number_of_paths = 10000;

    PayOffCall the_payoff(strike);
    VanillaOption the_option(the_payoff, expiry);

    ParametersConstant VolParam(vol);
    ParametersConstant rParam(r);

    cout << "\nWe have the following parameters:\n";
    cout << "expiry           = " << expiry << "\n";
    cout << "strike           = " << strike << "\n";
    cout << "spot             = " << spot << "\n";
    cout << "vol              = " << vol << "\n";
    cout << "r                = " << r << "\n";
    cout << "number_of_paths  = " << number_of_paths << "\n";

    //  Standard Monte Carlo with ConvergenceTable 
    StatisticsMean gatherer1;
    ConvergenceTable table1(gatherer1);
    RandomParkMiller generator1(1);

    generator1.set_seed(baseSeed);

    simple_monte_carlo8(the_option,
                        spot,
                        VolParam,
                        rParam,
                        number_of_paths,
                        table1,
                        generator1);

    vector<vector<double>> result1 = table1.get_results_so_far();

    cout << "\n Standard Monte Carlo Convergence\n";
    for (unsigned long i = 0; i < result1.size(); i++) {
        cout << "Paths: " << result1[i][1]
             << " Price: " << result1[i][0] << endl;
    }

    // Antithetic Monte Carlo 
    StatisticsMean gatherer2;
    ConvergenceTable table2(gatherer2);

    RandomParkMiller generator2(1);
    AntiThetic anti_generator(generator2);

    generator2.set_seed(baseSeed);
    anti_generator.reset();

    simple_monte_carlo8(the_option,
                        spot,
                        VolParam,
                        rParam,
                        number_of_paths,
                        table2,
                        anti_generator);

    vector<vector<double>> result2 = table2.get_results_so_far();

    cout << "\nAntithetic Monte Carlo Convergence\n";
    for (unsigned long i = 0; i < result2.size(); i++) {
        cout << "Paths: " << result2[i][1]
             << " Price: " << result2[i][0] << endl;
    }

    return 0;
}