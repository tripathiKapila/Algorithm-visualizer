#include "BubbleSort.hpp"
#include <algorithm>

BubbleSort::BubbleSort(std::vector<int>& data) : SortAlgorithm(data) {}

std::vector<Action> BubbleSort::run() {
    mActions.clear();
    for (size_t i = 0; i < mData.size(); ++i) {
        for (size_t j = 1; j < mData.size() - i; ++j) {
            logCompare(j - 1, j, mData[j - 1], mData[j]);
            if (mData[j - 1] > mData[j]) {
                logSwap(j - 1, j, mData[j - 1], mData[j]);
                std::swap(mData[j - 1], mData[j]);
            }
        }
    }
    return mActions;
} 