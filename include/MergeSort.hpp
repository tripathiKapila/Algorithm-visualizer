#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "SortAlgorithm.hpp"

class MergeSort : public SortAlgorithm {
public:
    MergeSort(std::vector<int>& data);
    std::vector<Action> run() override;
private:
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
};

#endif // MERGE_SORT_HPP 