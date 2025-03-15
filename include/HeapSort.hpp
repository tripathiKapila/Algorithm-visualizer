#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "SortAlgorithm.hpp"

class HeapSort : public SortAlgorithm {
public:
    HeapSort(std::vector<int>& data);
    std::vector<Action> run() override;
private:
    void heapify(int n, int i);
};

#endif // HEAP_SORT_HPP 