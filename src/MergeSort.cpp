#include "MergeSort.hpp"
#include <algorithm>

MergeSort::MergeSort(std::vector<int>& data) : SortAlgorithm(data) {}

std::vector<Action> MergeSort::run() {
    mActions.clear();
    if (!mData.empty()) {
        mergeSort(0, static_cast<int>(mData.size() - 1));
    }
    return mActions;
}

void MergeSort::mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void MergeSort::merge(int left, int mid, int right) {
    std::vector<int> temp(mData.begin() + left, mData.begin() + right + 1);
    int i = 0;
    int j = mid - left + 1;
    int k = left;
    while (i <= mid - left && j < temp.size()) {
        logCompare(k, k, temp[i], temp[j]);
        if (temp[i] <= temp[j]) {
            mData[k] = temp[i];
            logSet(k, temp[i]);
            i++;
        } else {
            mData[k] = temp[j];
            logSet(k, temp[j]);
            j++;
        }
        k++;
    }
    while (i <= mid - left) {
        mData[k] = temp[i];
        logSet(k, temp[i]);
        i++;
        k++;
    }
    while (j < temp.size()) {
        mData[k] = temp[j];
        logSet(k, temp[j]);
        j++;
        k++;
    }
} 