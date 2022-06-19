#pragma once

#include "Plane/Plane.hpp"
#include "Side/Side.hpp"

#include <functional>

class Cube {
public:
    Cube();

    void print();
private:
    std::unordered_map<Side, Plane> m_cube;
};

// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Cube> {
    std::size_t operator()(Cube const& cube) const noexcept
    {
        return 12;
    }
};