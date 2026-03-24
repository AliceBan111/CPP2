#include <iostream>
#include "simple_mc7.h"
#include "vanilla3.h"
#include "statistics_mc.h"
#include "statistics_std.h"
#include <cmath>

using namespace std;

int main()
{

    double expiry = 0.5;
    double strike = 100.0;
    double spot = 95.0;
    double vol = 0.2;
    double r = 0.06;
    unsigned long number_of_paths = 1000000;

    cout << "Do you want to enter your own option paramters (1) or use defaults (2)?\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nEnter expiry\n";
        cin >> expiry;

        cout << "\nEnter strike\n";
        cin >> strike;

        cout << "\nEnter spot\n";
        cin >> spot;

        cout << "\nEnter vol\n";
        cin >> vol;

        cout << "\nEnter r\n";
        cin >> r;

        cout << "\nEnter number of paths\n";
        cin >> number_of_paths;
    }

    PayOffCall thePayOff(strike);
    VanillaOption theOption(thePayOff, expiry);
    ParametersConstant volParam(vol);
    ParametersConstant rParam(r);
    //StatisticsMean gatherer;
    StatisticsStd gatherer;

    simple_monte_carlo7(theOption,
                        spot,
                        volParam,
                        rParam,
                        number_of_paths,
                        gatherer);


    vector<vector<double>> results = gatherer.get_results_so_far(); // results: a vector of vectors of double  results[i][j]


    double option_price = results[0][0];
    double std_deviation = results[1][0];

    double standard_error = std_deviation / sqrt(number_of_paths);
    double z_value = 1.96;  // 95% confidence level
    double margin_of_error = z_value * standard_error;
    double ci_lower = option_price - margin_of_error;
    double ci_upper = option_price + margin_of_error;

    cout << "Option price (mean): " << option_price << endl;
    cout << "Standard deviation: " << std_deviation << endl;

    cout << "\n95% Confidence Interval:" << endl;
    cout << "  " << ci_lower << " to " << ci_upper << endl;
    return 0;
}
