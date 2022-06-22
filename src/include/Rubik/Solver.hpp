#pragma once

#include "Cube.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace Rubik {

class Solver {
public:
    Solver();
    int solve(const Cube& cube);

private:
    void connectRightCube();
    void connectCube();

private:
    int m_distance;
    int m_nestingLvl;
    Cube m_cube;
};

} // namespace Rubik