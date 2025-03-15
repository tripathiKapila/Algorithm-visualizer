#ifndef ACTION_HPP
#define ACTION_HPP

#include <cstddef>

enum class ActionType {
    Compare,
    Swap,
    Visit,
    Set,        // For setting array values in sorting algorithms
    TreeEdge,   // For DFS tree edges
    BackEdge,   // For DFS back edges
    Exit        // For when DFS exits a node
};

class Action {
public:
    Action(ActionType type, int index1, int index2 = -1, int value1 = 0, int value2 = 0)
        : type(type), index1(index1), index2(index2), value1(value1), value2(value2) {}

    ActionType type;
    int index1;
    int index2;
    int value1;
    int value2;
};

#endif // ACTION_HPP 