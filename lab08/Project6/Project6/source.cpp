
#include"cppinterface.h"
#include "simple_mc8.h"
#include "park_miller.h"
#include "vanilla3.h"
#include "statistics_mc.h"
#include "convergence_table.h"
#include "conf_limits.h"
#include "antithetic.h"
#include "helpers.h"

#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

#pragma warning (disable : 4996)


short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}

double EuropeanCallMC(
    double spot,
    double strike,
    double r,
    double vol,
    double expiry,
    int number_of_paths,
    int number_of_experiments
)
{
    PayOffCall the_payoff(strike);
    VanillaOption the_option(the_payoff, expiry);

    ParametersConstant VolParam(vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer1;
    RandomParkMiller generator1(1);

    std::vector<double> prices;

    for (unsigned int i = 0; i < number_of_experiments; i++)
    {
        gatherer1.reset();

        generator1.set_seed(123 + i);

        simple_monte_carlo8(
            the_option,
            spot,
            VolParam,
            rParam,
            number_of_paths,
            gatherer1,
            generator1
        );

        prices.push_back(gatherer1.get_results_so_far()[0][0]);
    }

    return get_vec_mean(prices);
}

