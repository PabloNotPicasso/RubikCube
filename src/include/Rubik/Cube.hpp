#pragma once

#include "Plane.hpp"
#include "Rotation.hpp"
#include "Side.hpp"

#include <boost/functional/hash.hpp>

#include <functional>

namespace Rubik {

class Cube {
public:
    using CubeGrid = std::unordered_map<Side, Plane>;
    Cube();

    Cube(const Cube&);
    Cube& operator=(const Cube&);

    void rotate(const Rotation&);
    void reverseRotate(const Rotation&);

    const Plane& operator[](const Side&) const;
    Plane& operator[](const Side&);
    bool operator==(const Cube&) const;

    // Helper
    void print() const;

    friend std::hash<Cube>;

private:
    void L(bool reverse = false);
    void R(bool reverse = false);
    void F(bool reverse = false);
    void U(bool reverse = false);
    void D(bool reverse = false);
    void B(bool reverse = false);

private:
    CubeGrid m_cubeGrid;
    std::unordered_map<Rotation, std::function<void()>> m_rotationFn;
};
} // namespace Rubik
// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Rubik::Cube> {
    std::size_t operator()(const Rubik::Cube& cube) const noexcept
    {
        std::hash<Rubik::Plane> hasher;
        std::size_t result = 0;
        for (auto [side, plane] : cube.m_cubeGrid) {
            boost::hash_combine(result, hasher(plane));
        }
        return result;
    }
};