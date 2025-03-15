#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include "SortAlgorithm.hpp"

class ShellSort : public SortAlgorithm {
public:
    ShellSort(std::vector<int>& data);
    std::vector<Action> run() override;
};

#endif // SHELL_SORT_HPP 