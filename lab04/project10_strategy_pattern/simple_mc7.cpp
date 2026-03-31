#include <cmath>
#include "simple_mc7.h"
#include "random1.h"
#include "statistics_std.h"
#include "StoppingRule.h"

using namespace std;

void simple_monte_carlo7(const VanillaOption &the_option,
						 double spot,
						 const Parameters &vol,
						 const Parameters &r,
						 unsigned long number_of_paths,
						 StatisticsMC &gatherer,
						const StoppingRule& stopping_rule)
{
	double expiry = the_option.get_expiry();
	double variance = vol.get_integral_square(0, expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;
	double movedspot = spot * exp(r.get_integral(0, expiry) + itoCorrection);
	double thisspot;
	double discounting = exp(-r.get_integral(0, expiry));

	unsigned long paths_done = 0;

    while (true)
    {
        double thisGaussian = get_one_gaussian_by_box_muller();
		thisspot = movedspot * exp(rootVariance * thisGaussian);
		double thisPayOff = the_option.get_option_payoff(thisspot);

        gatherer.dump_one_result(thisPayOff * discounting);
        paths_done++;

        double std_error = gatherer.get_standard_error();

        if (paths_done >= 100 && stopping_rule.should_stop(paths_done, std_error))
            break;
    }


	// for (unsigned long i = 0; i < number_of_paths; i++)
	// {
	// 	double thisGaussian = get_one_gaussian_by_box_muller();
	// 	thisspot = movedspot * exp(rootVariance * thisGaussian);
	// 	double thisPayOff = the_option.get_option_payoff(thisspot);
	// 	gatherer.dump_one_result(thisPayOff * discounting);
	// }
}
