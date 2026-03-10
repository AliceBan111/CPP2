#pragma once

#include "option_struct.h"

double blackScholesByValue(OptionData opt);
double blackScholesByPointer(const OptionData* opt);
double blackScholesByReference(const OptionData& opt);
