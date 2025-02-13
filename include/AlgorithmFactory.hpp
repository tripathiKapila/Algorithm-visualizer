#ifndef ALGORITHM_FACTORY_HPP
#define ALGORITHM_FACTORY_HPP

#include <memory>
#include <vector>
#include "Algorithm.hpp"
#include "GraphAlgorithm.hpp"

// Existing sorting algorithm headers.
#include "QuickSort.hpp"
#include "MergeSort.hpp"
#include "BubbleSort.hpp"

// New sorting algorithm headers.
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "HeapSort.hpp"
#include "ShellSort.hpp"

#include "BFS.hpp"
#include "DFS.hpp"

// Define an enum for available algorithms.
enum class AlgorithmType {
    QuickSort,
    MergeSort,
    BubbleSort,
    InsertionSort,
    SelectionSort,
    HeapSort,
    ShellSort,
    BFS,
    DFS
};

class AlgorithmFactory {
public:
    // Create a sorting algorithm instance.
    static std::unique_ptr<Algorithm> createSortingAlgorithm(AlgorithmType type, std::vector<int>& data);

    // Create a graph algorithm instance.
    static std::unique_ptr<Algorithm> createGraphAlgorithm(AlgorithmType type, const Graph& graph);
};

#endif // ALGORITHM_FACTORY_HPP
