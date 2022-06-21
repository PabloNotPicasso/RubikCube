#include "Side.hpp"

static const std::unordered_map<Side, std::string> sideName{
    {Side::NA, "N"},
    {Side::F, "F"},
    {Side::L, "L"},
    {Side::R, "R"},
    {Side::B, "B"},
    {Side::U, "U"},
    {Side::D, "D"},
};

std::string getName(const Side& side)
{
    return sideName.at(side);
}