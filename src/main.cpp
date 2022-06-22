#include "Rubik/RubikApi.hpp"

#include <iostream>

using namespace Rubik;
using namespace std;

int main()
{
    Cube cube;
    Solver solver;

    cube.rotate(Rotation::L);
    cube.rotate(Rotation::R);
    cube.rotate(Rotation::F);
    cube.rotate(Rotation::D);
    cube.rotate(Rotation::R);
    cube.rotate(Rotation::U);
    cube.rotate(Rotation::B);
    cube.rotate(Rotation::F);

    int dist = solver.solve(cube);
    std::cout << " DISTANCE = " << dist;
    return 0;
}