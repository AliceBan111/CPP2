#include "convergence_table.h"

// constructor
ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC> &Inner_) : Inner(Inner_)
{
    stopping_point = 2; // 初始时设置stopping_point为2，表示在完成2条路径后记录结果。
    paths_done = 0;
}

// definition of clone() method
StatisticsMC *ConvergenceTable::clone() const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::dump_one_result(double result)
{
    Inner->dump_one_result(result); // 将结果传递给Inner（内部统计器）对象的dump_one_result方法进行处理。
    ++paths_done;

    if (paths_done == stopping_point)
    {
        stopping_point *= 2;
        std::vector<std::vector<double>> thisResult(Inner->get_results_so_far());

        for (unsigned long i = 0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(paths_done);
            results_so_far.push_back(thisResult[i]);
        }
    }
}

std::vector<std::vector<double>> ConvergenceTable::get_results_so_far() const
{
    std::vector<std::vector<double>> this_result(results_so_far);

    if (paths_done * 2 != stopping_point)
    {
        std::vector<std::vector<double>> thisResult(Inner->get_results_so_far());

        for (unsigned long i = 0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(paths_done);
            this_result.push_back(thisResult[i]);
        }
    }
    return this_result;
}

double ConvergenceTable::get_standard_error() const
{
    return Inner->get_standard_error();
}