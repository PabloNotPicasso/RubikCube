#include "Plane.hpp"

#include <iostream>

Plane::Plane(const Color color)
    : m_grid{{{color, color, color}, {color, color, color}, {color, color, color}}}
{
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
            std::cout << getName(color);
        }
        std::cout << "\n";
    }
}