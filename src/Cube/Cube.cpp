#include "Cube.hpp"

#include <iostream>

Cube::Cube()
    : m_cube{
        {Side::B, Color::Orange},
        {Side::D, Color::White},
        {Side::F, Color::Red},
        {Side::L, Color::Blue},
        {Side::R, Color::Green},
        {Side::U, Color::Yellow},
    }
{
}

void Cube::print()
{
    for (auto& [side, plane] : m_cube) {
        std::cout << "Side [" << getName(side) << "] \n";
        plane.print();
    }
}