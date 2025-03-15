#include "InsertionSort.hpp"

InsertionSort::InsertionSort(std::vector<int>& data)
    : SortAlgorithm(data) {}

std::vector<Action> InsertionSort::run() {
    mActions.clear();
    int n = mData.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            logCompare(j - 1, j, mData[j - 1], mData[j]);
            if (mData[j - 1] > mData[j]) {
                logSwap(j - 1, j, mData[j - 1], mData[j]);
                std::swap(mData[j - 1], mData[j]);
                j--;
            } else {
                break;
            }
        }
    }
    return mActions;
} 