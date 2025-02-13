#ifndef ACTION_HPP
#define ACTION_HPP

#include <cstddef>

enum class ActionType {
    Compare,
    Swap,
    Visit,
    Set  // Represents placing a value in the array.
};

struct Action {
    ActionType type;
    std::size_t index1;
    std::size_t index2;
    int value1;
    int value2;

    Action(ActionType t, std::size_t idx1, std::size_t idx2 = 0, int val1 = 0, int val2 = 0)
        : type(t), index1(idx1), index2(idx2), value1(val1), value2(val2) {}
};

#endif // ACTION_HPP
