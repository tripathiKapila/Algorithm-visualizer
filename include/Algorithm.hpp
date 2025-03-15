#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>
#include "Action.hpp"

class Algorithm {
public:
    virtual ~Algorithm() = default;
    virtual std::vector<Action> run() = 0;
};

#endif // ALGORITHM_HPP 