#ifndef SIMPLE_MC7_H
#define SIMPLE_MC7_H

#include "parameters.h"
#include "statistics_mc.h"
#include "vanilla3.h"
#include "StoppingRule.h"

void simple_monte_carlo7(const VanillaOption& the_option, double spot,
                         const Parameters& vol, const Parameters& r,
                         unsigned long number_of_paths, StatisticsMC& gatherer,
                         const StoppingRule& stopping_rule);

#endif
