#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <vector>
#include <functional>

// Bubble sort function that uses a callback to record swaps.
void bubbleSort(std::vector<int>& data, int delay,
                const std::function<void(const std::vector<int>&, int, int)>& swapCallback);

#endif // ALGORITHMS_HPP
