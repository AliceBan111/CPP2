#pragma once
#include "option_struct.h"

double monteCarloByValue(OptionData opt, unsigned long paths);
double monteCarloByPointer(const OptionData* opt, unsigned long paths);
double monteCarloByReference(const OptionData& opt, unsigned long paths);
