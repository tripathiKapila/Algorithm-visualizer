#include "ShellSort.hpp"

ShellSort::ShellSort(std::vector<int>& data)
    : SortAlgorithm(data) {}

std::vector<Action> ShellSort::run() {
    mActions.clear();
    int n = mData.size();
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = mData[i];
            int j = i;
            while (j >= gap) {
                logCompare(j - gap, i, mData[j - gap], temp);
                if (mData[j - gap] > temp) {
                    mData[j] = mData[j - gap];
                    logSet(j, mData[j - gap]);
                    j -= gap;
                } else {
                    break;
                }
            }
            mData[j] = temp;
            logSet(j, temp);
        }
    }
    
    return mActions;
} 