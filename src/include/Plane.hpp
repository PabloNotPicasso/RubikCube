#pragma once

#include "Color.hpp"
#include "Helper.hpp"

#include <boost/functional/hash.hpp>

#include <array>

class Plane {
public:
    Plane(const Color color = Color::NA);

    void rotate();
    void rotateReverse();

    Color at(const int& r, const int& col);

    Color& operator()(const int& row, const int& col);
    const Color& operator()(const int& row, const int& col) const;

    void print();
    friend std::hash<Plane>;

private:
    void transponse();
    void reflect();
    std::array<std::array<Color, DIMENSION>, DIMENSION> m_grid;
};

template<>
struct std::hash<Plane> {
    std::size_t operator()(Plane const& plane) const noexcept
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