#include "SelectionSort.hpp"

SelectionSort::SelectionSort(std::vector<int>& data)
    : SortAlgorithm(data) {}

std::vector<Action> SelectionSort::run() {
    mActions.clear();
    int n = mData.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            logCompare(minIndex, j, mData[minIndex], mData[j]);
            if (mData[j] < mData[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            logSwap(i, minIndex, mData[i], mData[minIndex]);
            std::swap(mData[i], mData[minIndex]);
        }
    }
    return mActions;
} 