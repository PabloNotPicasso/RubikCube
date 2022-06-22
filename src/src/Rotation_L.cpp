#include "Rubik/Cube.hpp"

namespace Rubik {

static void _rotate(Cube::CubeGrid& cube);

void Cube::L(bool reverse)
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
    Plane& L_side = grid[Side::L];
    L_side.rotateReverse();

    Plane& U_side = grid[Side::U];
    Plane& F_side = grid[Side::F];
    Plane& D_side = grid[Side::D];
    Plane& B_side = grid[Side::B];

    Plane was_U_side = U_side;
    Plane was_F_side = F_side;
    Plane was_D_side = D_side;
    Plane was_B_side = B_side;

    // U
    U_side(0, 0) = was_F_side(0, 0);
    U_side(1, 0) = was_F_side(1, 0);
    U_side(2, 0) = was_F_side(2, 0);
    // F
    F_side(0, 0) = was_D_side(0, 0);
    F_side(1, 0) = was_D_side(1, 0);
    F_side(2, 0) = was_D_side(2, 0);
    // D
    D_side(0, 0) = was_B_side(2, 2);
    D_side(1, 0) = was_B_side(1, 2);
    D_side(2, 0) = was_B_side(0, 2);
    // B
    B_side(0, 2) = was_U_side(2, 0);
    B_side(1, 2) = was_U_side(1, 0);
    B_side(2, 2) = was_U_side(0, 0);
}
} // namespace Rubik