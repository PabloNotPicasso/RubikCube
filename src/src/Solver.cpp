#include "Rubik/Solver.hpp"

#include "Rubik/Cube.hpp"
#include "Rubik/Rotation.hpp"

#include <iostream>
namespace Rubik {

// Side is parent
std::unordered_map<Cube, int> rightCubeMoves;

Solver::Solver()
    : m_distance(INT_MAX)
    , m_nestingLvl(6)
{
}

int Solver::solve(const Cube& cube)
{
    m_cube = cube;
    connectRightCube();
    connectCube();

    return m_distance;
}

void Solver::connectRightCube()
{
    Cube rightCube;

    std::function<void(int, const Rotation&)> dfs;
    dfs = [&](int availableLvl, const Rotation& parentRotation) {
        int curDist = m_nestingLvl - availableLvl;
        if (availableLvl <= 0)
            return;
        if (rightCubeMoves.count(rightCube))
            if (rightCubeMoves[rightCube] < curDist)
                return;

        rightCubeMoves[rightCube] = curDist;

        for (const Rotation& rotation : RotationList) {
            rightCube.rotate(rotation);

            dfs(availableLvl - 1, rotation);

            rightCube.reverseRotate(rotation);
        }
    };

    dfs(m_nestingLvl, Rotation::Final);
}

void Solver::connectCube()
{
    std::unordered_map<Cube, int> cubeMoves;

    std::function<void(int, const Rotation&)> dfs;
    dfs = [&](int availableLvl, const Rotation& parentRotation) {
        int curDist = m_nestingLvl - availableLvl;
        if (availableLvl <= 0)
            return;
        if (cubeMoves.count(m_cube))
            if (cubeMoves[m_cube] < curDist)
                return;

        cubeMoves[m_cube] = curDist;

        if (rightCubeMoves.count(m_cube)) {
            m_distance = std::min(m_distance, rightCubeMoves[m_cube] + cubeMoves[m_cube]);
            return;
        }

        for (const Rotation& rotation : RotationList) {
            m_cube.rotate(rotation);
            dfs(availableLvl - 1, rotation);
            m_cube.reverseRotate(rotation);
        }
    };

    dfs(m_nestingLvl, Rotation::Start);
}

} // namespace Rubik