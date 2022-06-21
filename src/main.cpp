#include "Rubik/Cube.hpp"

int main()
{
    Rubik::Cube c;
    c.rotate(Rubik::Side::L);
    c.printNice();
    return 0;
}