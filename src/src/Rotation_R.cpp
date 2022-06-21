#include "Cube.hpp"

void Cube::R()
{
    // L Side rotation
    Plane& R_side = m_cube[Side::R];
    R_side.rotate();

    Plane& U_side = m_cube[Side::U];
    Plane& F_side = m_cube[Side::F];
    Plane& D_side = m_cube[Side::D];
    Plane& B_side = m_cube[Side::B];

    Plane was_U_side = U_side;
    Plane was_F_side = F_side;
    Plane was_D_side = D_side;
    Plane was_B_side = B_side;

    // U
    U_side(0, 2) = was_F_side(0, 2);
    U_side(1, 2) = was_F_side(1, 2);
    U_side(2, 2) = was_F_side(2, 2);
    // F
    F_side(0, 2) = was_D_side(0, 2);
    F_side(1, 2) = was_D_side(1, 2);
    F_side(2, 2) = was_D_side(2, 2);
    // D
    D_side(0, 2) = was_B_side(2, 0);
    D_side(1, 2) = was_B_side(1, 0);
    D_side(2, 2) = was_B_side(0, 0);
    // B
    B_side(0, 0) = was_U_side(2, 2);
    B_side(1, 0) = was_U_side(1, 2);
    B_side(2, 0) = was_U_side(0, 2);
}