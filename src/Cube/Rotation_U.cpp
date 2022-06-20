#include "Cube.hpp"

void Cube::U()
{
    // L Side rotation
    Plane& U_side = m_cube[Side::U];
    U_side.rotate();
    
    Plane& L_side = m_cube[Side::L];
    Plane& F_side = m_cube[Side::F];
    Plane& R_side = m_cube[Side::R];
    Plane& B_side = m_cube[Side::B];

    Plane was_L_side = L_side;
    Plane was_F_side = F_side;
    Plane was_R_side = R_side;
    Plane was_B_side = B_side;

    // B
    B_side(0,0) = was_L_side(0,0);
    B_side(0,1) = was_L_side(0,1);
    B_side(0,2) = was_L_side(0,2);
    // R
    R_side(0,0) = was_B_side(0,0);
    R_side(0,1) = was_B_side(0,1);
    R_side(0,2) = was_B_side(0,2);
    // F
    F_side(0,0) = was_R_side(0,0);
    F_side(0,1) = was_R_side(0,1);
    F_side(0,2) = was_R_side(0,2);
    // L
    L_side(0,0) = was_F_side(0,0);
    L_side(0,1) = was_F_side(0,1);
    L_side(0,2) = was_F_side(0,2);
}