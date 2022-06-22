#include "Rubik/Cube.hpp"

namespace Rubik {

static void _rotate(Cube::CubeGrid& cube);

void Cube::D(bool reverse)
{
    if (reverse) {
        _rotate(m_cubeGrid);
        _rotate(m_cubeGrid);
    }
    _rotate(m_cubeGrid);
}

void _rotate(Cube::CubeGrid& grid)
{
    // L Side rotation
    Plane& D_side = grid[Side::D];
    D_side.rotateReverse();

    Plane& L_side = grid[Side::L];
    Plane& F_side = grid[Side::F];
    Plane& R_side = grid[Side::R];
    Plane& B_side = grid[Side::B];

    Plane was_L_side = L_side;
    Plane was_F_side = F_side;
    Plane was_R_side = R_side;
    Plane was_B_side = B_side;

    // B
    B_side(2, 0) = was_L_side(2, 0);
    B_side(2, 1) = was_L_side(2, 1);
    B_side(2, 2) = was_L_side(2, 2);
    // R
    R_side(2, 0) = was_B_side(2, 0);
    R_side(2, 1) = was_B_side(2, 1);
    R_side(2, 2) = was_B_side(2, 2);
    // F
    F_side(2, 0) = was_R_side(2, 0);
    F_side(2, 1) = was_R_side(2, 1);
    F_side(2, 2) = was_R_side(2, 2);
    // L
    L_side(2, 0) = was_F_side(2, 0);
    L_side(2, 1) = was_F_side(2, 1);
    L_side(2, 2) = was_F_side(2, 2);
}
} // namespace Rubik