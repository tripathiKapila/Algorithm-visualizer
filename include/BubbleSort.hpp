#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "SortAlgorithm.hpp"

class BubbleSort : public SortAlgorithm {
public:
    BubbleSort(std::vector<int>& data);
    std::vector<Action> run() override;
};

#endif // BUBBLE_SORT_HPP 