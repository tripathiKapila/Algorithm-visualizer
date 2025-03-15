#ifndef ALGORITHM_FACTORY_HPP
#define ALGORITHM_FACTORY_HPP

#include <memory>
#include <vector>
#include "Algorithm.hpp"
#include "GraphAlgorithm.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "HeapSort.hpp"
#include "ShellSort.hpp"
#include "QuickSort.hpp"
#include "MergeSort.hpp"
#include "BFS.hpp"
#include "DFS.hpp"

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
    static std::unique_ptr<Algorithm> createSortingAlgorithm(AlgorithmType type, std::vector<int>& data);
    static std::unique_ptr<Algorithm> createGraphAlgorithm(AlgorithmType type, const Graph& graph);
};

#endif // ALGORITHM_FACTORY_HPP 