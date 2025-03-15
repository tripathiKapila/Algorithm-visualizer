#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "SortAlgorithm.hpp"

class QuickSort : public SortAlgorithm {
public:
    QuickSort(std::vector<int>& data);
    std::vector<Action> run() override;
private:
    void quickSort(int low, int high);
    int partition(int low, int high);
};

#endif // QUICK_SORT_HPP 