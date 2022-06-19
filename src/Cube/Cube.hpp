#pragma once

#include "Plane/Plane.hpp"
#include "Side/Side.hpp"

#include <boost/functional/hash.hpp>

#include <functional>

class Cube {
public:
    Cube();

    void print();

    friend std::hash<Cube>;

private:
    std::unordered_map<Side, Plane> m_cube;
};

// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Cube> {
    std::size_t operator()(Cube const& cube) const noexcept
    {
        std::hash<Plane> hasher;
        std::size_t result = 0;
        for (auto [side, plane] : cube.m_cube) {
            boost::hash_combine(result, hasher(plane));
        }
        return result;
    }
};