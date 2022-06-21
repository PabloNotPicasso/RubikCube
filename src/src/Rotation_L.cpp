#include "Cube.hpp"

void Cube::L()
{
    // L Side rotation
    Plane& L_side = m_cube[Side::L];
    L_side.rotateReverse();

    Plane& U_side = m_cube[Side::U];
    Plane& F_side = m_cube[Side::F];
    Plane& D_side = m_cube[Side::D];
    Plane& B_side = m_cube[Side::B];

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