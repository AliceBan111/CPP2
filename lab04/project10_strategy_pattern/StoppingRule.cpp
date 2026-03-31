#include "StoppingRule.h"

// StopByPaths
StopByPaths::StopByPaths(unsigned long max_paths_)
    : max_paths(max_paths_) {}

bool StopByPaths::should_stop(unsigned long paths_done,
                              double) const {
    return paths_done >= max_paths;
}

StoppingRule* StopByPaths::clone() const {
    return new StopByPaths(*this);
}

// StopByPrecision
StopByPrecision::StopByPrecision(double target_error_)
    : target_error(target_error_) {}

bool StopByPrecision::should_stop(unsigned long,
                                  double std_error) const {
    return std_error < target_error;
}

StoppingRule* StopByPrecision::clone() const {
    return new StopByPrecision(*this);
}

// StopEither
StopEither::StopEither(const Wrapper<StoppingRule>& rule1_,
                       const Wrapper<StoppingRule>& rule2_)
    : rule1(rule1_), rule2(rule2_) {}

bool StopEither::should_stop(unsigned long paths_done,
                             double std_error) const {
    return rule1->should_stop(paths_done, std_error) ||
           rule2->should_stop(paths_done, std_error);
}

StoppingRule* StopEither::clone() const {
    return new StopEither(rule1, rule2);
}