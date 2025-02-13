#include <functional>   // Required for std::function
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>    // for std::swap
#include "Algorithms.hpp"

void bubbleSort(std::vector<int>& data, int delay,
                const std::function<void(const std::vector<int>&, int, int)>& swapCallback)
{
    for (size_t i = 1; i < data.size(); ++i) {
        for (size_t j = 1; j < data.size(); ++j) {
            if (data[j - 1] > data[j]) {
                // Call the callback to record the swap.
                swapCallback(data, j - 1, j);
                std::swap(data[j - 1], data[j]);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            }
        }
    }
}
