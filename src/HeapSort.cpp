#include "HeapSort.hpp"

HeapSort::HeapSort(std::vector<int>& data)
    : SortAlgorithm(data) {}

void HeapSort::heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n) {
        logCompare(largest, left, mData[largest], mData[left]);
        if (mData[left] > mData[largest])
            largest = left;
    }
    
    if (right < n) {
        logCompare(largest, right, mData[largest], mData[right]);
        if (mData[right] > mData[largest])
            largest = right;
    }
    
    if (largest != i) {
        logSwap(i, largest, mData[i], mData[largest]);
        std::swap(mData[i], mData[largest]);
        heapify(n, largest);
    }
}

std::vector<Action> HeapSort::run() {
    mActions.clear();
    int n = mData.size();
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        logSwap(0, i, mData[0], mData[i]);
        std::swap(mData[0], mData[i]);
        heapify(i, 0);
    }
    
    return mActions;
} 