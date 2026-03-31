#pragma once

#include "wrapper.h"

class StoppingRule {
public:
    StoppingRule() {}
    virtual ~StoppingRule() {}

    virtual bool should_stop(unsigned long paths_done,
                             double std_error) const = 0;

    virtual StoppingRule* clone() const = 0;
};

// maximum number of paths
class StopByPaths : public StoppingRule {
public:
    StopByPaths(unsigned long max_paths_);

    virtual bool should_stop(unsigned long paths_done,
                             double std_error) const;

    virtual StoppingRule* clone() const;

private:
    unsigned long max_paths;
};

// precision-based stopping rule
class StopByPrecision : public StoppingRule {
public:
    StopByPrecision(double target_error_);

    virtual bool should_stop(unsigned long paths_done,
                             double std_error) const;

    virtual StoppingRule* clone() const;

private:
    double target_error;
};

// stop when either of the two rules is satisfied
class StopEither : public StoppingRule {
public:
    StopEither(const Wrapper<StoppingRule>& rule1_,
               const Wrapper<StoppingRule>& rule2_);

    virtual bool should_stop(unsigned long paths_done,
                             double std_error) const;

    virtual StoppingRule* clone() const;

private:
    Wrapper<StoppingRule> rule1;
    Wrapper<StoppingRule> rule2;
};
