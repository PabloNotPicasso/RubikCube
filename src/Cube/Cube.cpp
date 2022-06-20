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

Plane& Cube::at(const Side& side){
    return m_cube[side];
}

void Cube::rotate(const Side& side)
{
    switch (side)
    {
    case Side::L:
        L();
        break;
    case Side::R:
        R();
        break;
    case Side::F:
        F();
        break;
    case Side::B:
        B();
        break;
    case Side::U:
        U();
        break;
    case Side::D:
        D();
        break;
    default:
        break;
    }
}

void Cube::print()
{
    for (auto& [side, plane] : m_cube) {
        std::cout << "Side [" << getName(side) << "] \n";
        plane.print();
    }
}

void Cube::printNice()
{
    using namespace std;
    auto symb = [&](Side side, int row, int col)
    {
        return getName(m_cube[side](row,col));
    };

    // U
    cout << "    " << symb(Side::U,0,0) << symb(Side::U,0,1) << symb(Side::U,0,2) << endl;
    cout << "    " << symb(Side::U,1,0) << symb(Side::U,1,1) << symb(Side::U,1,2) << endl;
    cout << "    " << symb(Side::U,2,0) << symb(Side::U,2,1) << symb(Side::U,2,2) << endl;
    
    cout << symb(Side::L,0,0) << symb(Side::L,0,1) << symb(Side::L,0,2) << " ";
    cout << symb(Side::F,0,0) << symb(Side::F,0,1) << symb(Side::F,0,2) << " ";
    cout << symb(Side::R,0,0) << symb(Side::R,0,1) << symb(Side::R,0,2) << " ";
    cout << symb(Side::B,0,0) << symb(Side::B,0,1) << symb(Side::B,0,2) << " ";
    cout << endl;
    
    cout << symb(Side::L,1,0) << symb(Side::L,1,1) << symb(Side::L,1,2) << " ";
    cout << symb(Side::F,1,0) << symb(Side::F,1,1) << symb(Side::F,1,2) << " ";
    cout << symb(Side::R,1,0) << symb(Side::R,1,1) << symb(Side::R,1,2) << " ";
    cout << symb(Side::B,1,0) << symb(Side::B,1,1) << symb(Side::B,1,2) << " ";
    cout << endl;

    cout << symb(Side::L,2,0) << symb(Side::L,2,1) << symb(Side::L,2,2) << " ";
    cout << symb(Side::F,2,0) << symb(Side::F,2,1) << symb(Side::F,2,2) << " ";
    cout << symb(Side::R,2,0) << symb(Side::R,2,1) << symb(Side::R,2,2) << " ";
    cout << symb(Side::B,2,0) << symb(Side::B,2,1) << symb(Side::B,2,2) << " ";
    cout << endl;


    // D
    cout << "    " << symb(Side::D,0,0) << symb(Side::D,0,1) << symb(Side::D,0,2) << endl;
    cout << "    " << symb(Side::D,1,0) << symb(Side::D,1,1) << symb(Side::D,1,2) << endl;
    cout << "    " << symb(Side::D,2,0) << symb(Side::D,2,1) << symb(Side::D,2,2) << endl;
    
}
