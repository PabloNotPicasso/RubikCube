#pragma once

#include "Color/Color.hpp"
#include "Common/Helper.hpp"

#include <array>

class Plane {
public:
    Plane(const Color color = Color::NA);

    Color at(const int& r, const int& col);
    Color& operator()(const int& row, const int& col);

    void print();
private:
    std::array<std::array<Color, DIMENSION>, DIMENSION> m_grid;
};