#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Visualizer.hpp"
#include "AlgorithmFactory.hpp"

// Helper function to generate random data.
std::vector<int> generateRandomData(size_t size) {
    std::vector<int> data;
    for (size_t i = 0; i < size; ++i)
        data.push_back(rand() % 100 + 1);
    return data;
}

// Helper function for sorting demos.
void runSortingDemo(AlgorithmType algoType) {
    std::vector<int> data = generateRandomData(50);
    auto algorithm = AlgorithmFactory::createSortingAlgorithm(algoType, data);
    if (algorithm) {
        auto actions = algorithm->run();

        // (Testing verification remains unchanged.)
        for (size_t i = 1; i < data.size(); ++i) {
            if (data[i - 1] > data[i]) {
                std::cerr << "Error: Array is not sorted correctly!" << std::endl;
                break;
            }
        }

        Visualizer visualizer(800, 600);
        visualizer.setData(data);
        visualizer.loadActions(actions);
        visualizer.run(); // Wait until user clicks "Menu" in the UI.
    }
}

// Helper function for graph demos.
void runGraphDemo(AlgorithmType algoType) {
    // Create a more complex graph (adjacency list) with 10 nodes.
    Graph graph = {
        {1, 2, 3},   // Node 0 connects to 1, 2, 3
        {0, 4, 5},   // Node 1 connects to 0, 4, 5
        {0, 6},      // Node 2 connects to 0, 6
        {0, 7},      // Node 3 connects to 0, 7
        {1, 8},      // Node 4 connects to 1, 8
        {1, 9},      // Node 5 connects to 1, 9
        {2, 7},      // Node 6 connects to 2, 7
        {3, 6, 8},   // Node 7 connects to 3, 6, 8
        {4, 7, 9},   // Node 8 connects to 4, 7, 9
        {5, 8}       // Node 9 connects to 5, 8
    };

    auto algorithm = AlgorithmFactory::createGraphAlgorithm(algoType, graph);
    if (algorithm) {
        auto actions = algorithm->run();

        // For visualization, create dummy data (one per node).
        std::vector<int> dummyData(graph.size(), 50);
        Visualizer visualizer(800, 600);
        visualizer.setData(dummyData);
        visualizer.setGraphMode(true);
        // Pass the actual graph for edge drawing.
        visualizer.setGraph(graph);
        visualizer.loadActions(actions);
        visualizer.run(); // Wait until user clicks "Menu" in the UI.
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    int choice = 0;
    while (true) {
        std::cout << "\n=== Algorithm Visualizer Menu ===\n";
        std::cout << "1. QuickSort (Sorting)\n";
        std::cout << "2. MergeSort (Sorting)\n";
        std::cout << "3. BubbleSort (Sorting)\n";
        std::cout << "4. InsertionSort (Sorting)\n";
        std::cout << "5. SelectionSort (Sorting)\n";
        std::cout << "6. HeapSort (Sorting)\n";
        std::cout << "7. ShellSort (Sorting)\n";
        std::cout << "8. BFS (Graph Traversal)\n";
        std::cout << "9. DFS (Graph Traversal)\n";
        std::cout << "10. Exit\n";
        std::cout << "Enter your choice (1-10): ";
        std::cin >> choice;
        
        if (choice == 10) {
            std::cout << "Exiting...\n";
            break;
        }
        
        switch (choice) {
            case 1:
                runSortingDemo(AlgorithmType::QuickSort);
                break;
            case 2:
                runSortingDemo(AlgorithmType::MergeSort);
                break;
            case 3:
                runSortingDemo(AlgorithmType::BubbleSort);
                break;
            case 4:
                runSortingDemo(AlgorithmType::InsertionSort);
                break;
            case 5:
                runSortingDemo(AlgorithmType::SelectionSort);
                break;
            case 6:
                runSortingDemo(AlgorithmType::HeapSort);
                break;
            case 7:
                runSortingDemo(AlgorithmType::ShellSort);
                break;
            case 8:
                runGraphDemo(AlgorithmType::BFS);
                break;
            case 9:
                runGraphDemo(AlgorithmType::DFS);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    
    return 0;
}
