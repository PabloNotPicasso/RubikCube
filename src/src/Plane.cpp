#include "Rubik/Plane.hpp"

#include <iostream>

namespace Rubik {

Plane::Plane(const Color::type color)
    : m_grid{{{color, color, color}, {color, color, color}, {color, color, color}}}
{
}

void Plane::transponse()
{
    // transpose
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = i; j < DIMENSION; ++j) {
            std::swap(m_grid[i][j], m_grid[j][i]);
        }
    }
}

void Plane::reflect()
{
    // swap
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j * 2 < DIMENSION; ++j) {
            std::swap(m_grid[i][j], m_grid[i][DIMENSION - 1 - j]);
        }
    }
}

void Plane::rotate()
{
    transponse();
    reflect();
}

void Plane::rotateReverse()
{
    reflect();
    transponse();
}

Color Plane::at(const int& r, const int& col)
{
    return operator()(r, col);
}

Color& Plane::operator()(const int& row, const int& col)
{
    return m_grid[row][col];
}

const Color& Plane::operator()(const int& row, const int& col) const
{
    return m_grid[row][col];
}

void Plane::print()
{
    for (auto row : m_grid) {
        for (auto color : row) {
            std::cout << Color::getName(color);
        }
        std::cout << "\n";
    }
}
} // namespace Rubik