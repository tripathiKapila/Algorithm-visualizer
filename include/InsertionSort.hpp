#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "SortAlgorithm.hpp"

class InsertionSort : public SortAlgorithm {
public:
    InsertionSort(std::vector<int>& data);
    std::vector<Action> run() override;
};

#endif // INSERTION_SORT_HPP 