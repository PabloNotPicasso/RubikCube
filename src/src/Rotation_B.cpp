#include "Rubik/Cube.hpp"

namespace Rubik {

static void _rotate(Cube::CubeGrid& cube);

void Cube::B(bool reverse)
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
    Plane& B_side = grid[Side::B];
    B_side.rotate();

    Plane& U_side = grid[Side::U];
    Plane& R_side = grid[Side::R];
    Plane& D_side = grid[Side::D];
    Plane& L_side = grid[Side::L];

    Plane was_U_side = U_side;
    Plane was_R_side = R_side;
    Plane was_D_side = D_side;
    Plane was_L_side = L_side;

    // U
    U_side(0, 0) = was_R_side(0, 2);
    U_side(0, 1) = was_R_side(1, 2);
    U_side(0, 2) = was_R_side(2, 2);
    // R
    R_side(0, 2) = was_D_side(2, 2);
    R_side(1, 2) = was_D_side(2, 1);
    R_side(2, 2) = was_D_side(2, 0);
    // D
    D_side(2, 0) = was_L_side(0, 0);
    D_side(2, 1) = was_L_side(1, 0);
    D_side(2, 2) = was_L_side(2, 0);
    // L
    L_side(0, 0) = was_U_side(0, 2);
    L_side(1, 0) = was_U_side(0, 1);
    L_side(2, 0) = was_U_side(0, 0);
}

} // namespace Rubik