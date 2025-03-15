#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include "SortAlgorithm.hpp"

class SelectionSort : public SortAlgorithm {
public:
    SelectionSort(std::vector<int>& data);
    std::vector<Action> run() override;
};

#endif // SELECTION_SORT_HPP 