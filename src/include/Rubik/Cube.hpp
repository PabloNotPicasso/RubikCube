#pragma once

#include "Plane.hpp"
#include "Side.hpp"

#include <boost/functional/hash.hpp>

#include <functional>

namespace Rubik {

class Cube {
public:
    Cube();

    Plane& at(const Side&);
    void rotate(const Side&);

    // Helper
    void print();
    void printNice();
    friend std::hash<Cube>;

private:
    void L();
    void R();
    void F();
    void U();
    void D();
    void B();

private:
    std::unordered_map<Side, Plane> m_cube;
    std::unordered_map<Side, std::function<void()>> m_rotationFn;
};
} // namespace Rubik
// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Rubik::Cube> {
    std::size_t operator()(Rubik::Cube const& cube) const noexcept
    {
        std::hash<Rubik::Plane> hasher;
        std::size_t result = 0;
        for (auto [side, plane] : cube.m_cube) {
            boost::hash_combine(result, hasher(plane));
        }
        return result;
    }
};