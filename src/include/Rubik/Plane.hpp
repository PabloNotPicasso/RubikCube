#pragma once

#include "Color.hpp"
#include "Helper.hpp"

#include <boost/functional/hash.hpp>

#include <array>

namespace Rubik {

class Plane {
public:
    Plane(const Color::Type color = Color::NA);

    void rotate();
    void rotateReverse();

    Color& operator()(const int& row, const int& col);
    const Color& operator()(const int& row, const int& col) const;

    void print() const;
    friend std::hash<Plane>;

private:
    void transponse();
    void reflect();
    std::array<std::array<Color, DIMENSION>, DIMENSION> m_grid;
};
} // namespace Rubik

template<>
struct std::hash<Rubik::Plane> {
    std::size_t operator()(const Rubik::Plane& plane) const noexcept
    {
        std::size_t result = 0;
        for (auto row : plane.m_grid) {
            for (auto el : row) {
                boost::hash_combine(result, static_cast<int>(el));
            }
        }
        return result;
    }
};