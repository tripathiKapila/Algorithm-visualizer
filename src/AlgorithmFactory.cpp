#include "AlgorithmFactory.hpp"

std::unique_ptr<Algorithm> AlgorithmFactory::createSortingAlgorithm(AlgorithmType type, std::vector<int>& data) {
    switch (type) {
        case AlgorithmType::QuickSort:
            return std::make_unique<QuickSort>(data);
        case AlgorithmType::MergeSort:
            return std::make_unique<MergeSort>(data);
        case AlgorithmType::BubbleSort:
            return std::make_unique<BubbleSort>(data);
        case AlgorithmType::InsertionSort:
            return std::make_unique<InsertionSort>(data);
        case AlgorithmType::SelectionSort:
            return std::make_unique<SelectionSort>(data);
        case AlgorithmType::HeapSort:
            return std::make_unique<HeapSort>(data);
        case AlgorithmType::ShellSort:
            return std::make_unique<ShellSort>(data);
        default:
            return nullptr;
    }
}

std::unique_ptr<Algorithm> AlgorithmFactory::createGraphAlgorithm(AlgorithmType type, const Graph& graph) {
    switch (type) {
        case AlgorithmType::BFS:
            return std::make_unique<BFS>(graph);
        case AlgorithmType::DFS:
            return std::make_unique<DFS>(graph);
        default:
            return nullptr;
    }
} 