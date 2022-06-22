#include "Rubik/Cube.hpp"

#include <iostream>

namespace Rubik {

Cube::Cube()
    : m_cubeGrid{
        {Side::B, Color::Orange},
        {Side::D, Color::White},
        {Side::F, Color::Red},
        {Side::L, Color::Blue},
        {Side::R, Color::Green},
        {Side::U, Color::Yellow},
    }
    , m_rotationFn{
        {Rotation::B, std::bind(&Cube::B, this, false)},{Rotation::Br, std::bind(&Cube::B, this, true)},
        {Rotation::D, std::bind(&Cube::D, this, false)},{Rotation::Dr, std::bind(&Cube::D, this, true)},
        {Rotation::F, std::bind(&Cube::F, this, false)},{Rotation::Fr, std::bind(&Cube::F, this, true)},
        {Rotation::L, std::bind(&Cube::L, this, false)},{Rotation::Lr, std::bind(&Cube::L, this, true)},
        {Rotation::R, std::bind(&Cube::R, this, false)},{Rotation::Rr, std::bind(&Cube::R, this, true)},
        {Rotation::U, std::bind(&Cube::U, this, false)},{Rotation::Ur, std::bind(&Cube::U, this, true)},
    }
{
}

Cube::Cube(const Cube& copy)
    : m_cubeGrid(copy.m_cubeGrid)
    , m_rotationFn{
          {Rotation::B, std::bind(&Cube::B, this, false)},
          {Rotation::Br, std::bind(&Cube::B, this, true)},
          {Rotation::D, std::bind(&Cube::D, this, false)},
          {Rotation::Dr, std::bind(&Cube::D, this, true)},
          {Rotation::F, std::bind(&Cube::F, this, false)},
          {Rotation::Fr, std::bind(&Cube::F, this, true)},
          {Rotation::L, std::bind(&Cube::L, this, false)},
          {Rotation::Lr, std::bind(&Cube::L, this, true)},
          {Rotation::R, std::bind(&Cube::R, this, false)},
          {Rotation::Rr, std::bind(&Cube::R, this, true)},
          {Rotation::U, std::bind(&Cube::U, this, false)},
          {Rotation::Ur, std::bind(&Cube::U, this, true)},
      }
{
}

Cube& Cube::operator=(const Cube& assign)
{
    this->m_cubeGrid = assign.m_cubeGrid;
    return *this;
}

Plane& Cube::operator[](const Side& side)
{
    return m_cubeGrid[side];
}
const Plane& Cube::operator[](const Side& side) const
{
    return m_cubeGrid.at(side);
}

void Cube::rotate(const Rotation& rotation)
{
    m_rotationFn[rotation]();
}
void Cube::reverseRotate(const Rotation& rotation)
{
    m_rotationFn[ReverseRotationMap.at(rotation)]();
}

bool Cube::operator==(const Cube& otherCube) const
{
    bool isEq = true;
    for (const Side& side : Side::SideList) {
        isEq &= otherCube[side] == (*this)[side];
    }
    return isEq;
}

void Cube::print() const
{
    using namespace std;
    auto symb = [&](const Side& side, const int& row, const int& col) {
        return Color::getName(m_cubeGrid.at(side)(row, col));
    };

    // U
    cout << "    " << symb(Side::U, 0, 0) << symb(Side::U, 0, 1) << symb(Side::U, 0, 2) << endl;
    cout << "    " << symb(Side::U, 1, 0) << symb(Side::U, 1, 1) << symb(Side::U, 1, 2) << endl;
    cout << "    " << symb(Side::U, 2, 0) << symb(Side::U, 2, 1) << symb(Side::U, 2, 2) << endl;

    cout << symb(Side::L, 0, 0) << symb(Side::L, 0, 1) << symb(Side::L, 0, 2) << " ";
    cout << symb(Side::F, 0, 0) << symb(Side::F, 0, 1) << symb(Side::F, 0, 2) << " ";
    cout << symb(Side::R, 0, 0) << symb(Side::R, 0, 1) << symb(Side::R, 0, 2) << " ";
    cout << symb(Side::B, 0, 0) << symb(Side::B, 0, 1) << symb(Side::B, 0, 2) << " ";
    cout << endl;

    cout << symb(Side::L, 1, 0) << symb(Side::L, 1, 1) << symb(Side::L, 1, 2) << " ";
    cout << symb(Side::F, 1, 0) << symb(Side::F, 1, 1) << symb(Side::F, 1, 2) << " ";
    cout << symb(Side::R, 1, 0) << symb(Side::R, 1, 1) << symb(Side::R, 1, 2) << " ";
    cout << symb(Side::B, 1, 0) << symb(Side::B, 1, 1) << symb(Side::B, 1, 2) << " ";
    cout << endl;

    cout << symb(Side::L, 2, 0) << symb(Side::L, 2, 1) << symb(Side::L, 2, 2) << " ";
    cout << symb(Side::F, 2, 0) << symb(Side::F, 2, 1) << symb(Side::F, 2, 2) << " ";
    cout << symb(Side::R, 2, 0) << symb(Side::R, 2, 1) << symb(Side::R, 2, 2) << " ";
    cout << symb(Side::B, 2, 0) << symb(Side::B, 2, 1) << symb(Side::B, 2, 2) << " ";
    cout << endl;

    // D
    cout << "    " << symb(Side::D, 0, 0) << symb(Side::D, 0, 1) << symb(Side::D, 0, 2) << endl;
    cout << "    " << symb(Side::D, 1, 0) << symb(Side::D, 1, 1) << symb(Side::D, 1, 2) << endl;
    cout << "    " << symb(Side::D, 2, 0) << symb(Side::D, 2, 1) << symb(Side::D, 2, 2) << endl;
}
} // namespace Rubik