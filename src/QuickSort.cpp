#include "QuickSort.hpp"
#include <algorithm>

QuickSort::QuickSort(std::vector<int>& data) : SortAlgorithm(data) {}

std::vector<Action> QuickSort::run() {
    mActions.clear();
    if (!mData.empty()) {
        quickSort(0, static_cast<int>(mData.size() - 1));
    }
    return mActions;
}

void QuickSort::quickSort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quickSort(low, pivotIndex - 1);
        quickSort(pivotIndex + 1, high);
    }
}

int QuickSort::partition(int low, int high) {
    int pivotValue = mData[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        logCompare(j, high, mData[j], pivotValue);
        if (mData[j] < pivotValue) {
            i++;
            logSwap(i, j, mData[i], mData[j]);
            std::swap(mData[i], mData[j]);
        }
    }
    logSwap(i + 1, high, mData[i + 1], mData[high]);
    std::swap(mData[i + 1], mData[high]);
    return i + 1;
} 