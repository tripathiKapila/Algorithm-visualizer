#ifndef SORT_ALGORITHM_HPP
#define SORT_ALGORITHM_HPP

#include "Algorithm.hpp"
#include <vector>

class SortAlgorithm : public Algorithm {
public:
    SortAlgorithm(std::vector<int>& data) : mData(data) {}
protected:
    std::vector<int>& mData;
    std::vector<Action> mActions;
    
    // Helper methods for consistent action logging.
    void logCompare(int index1, int index2, int value1, int value2) {
        mActions.push_back(Action(ActionType::Compare, index1, index2, value1, value2));
    }
    void logSwap(int index1, int index2, int value1, int value2) {
        mActions.push_back(Action(ActionType::Swap, index1, index2, value1, value2));
    }
    void logSet(int index, int value) {
        mActions.push_back(Action(ActionType::Set, index, 0, value, 0));
    }
};

#endif // SORT_ALGORITHM_HPP 