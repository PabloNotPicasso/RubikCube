#include "Rubik/Side.hpp"

namespace Rubik {

static const std::unordered_map<Side, std::string> sideName{
    {Side::NA, "N"},
    {Side::F, "F"},
    {Side::L, "L"},
    {Side::R, "R"},
    {Side::B, "B"},
    {Side::U, "U"},
    {Side::D, "D"},
};

const std::vector<Side> Side::SideList{
    Side::F,
    Side::L,
    Side::R,
    Side::B,
    Side::U,
    Side::D,
};

std::string Side::getName(const Side& side)
{
    return sideName.at(side);
}

Side::Side(const Type& side)
    : m_type(side)
{
}

const Side::Type& Side::type() const
{
    return m_type;
}

Side::operator Type() const
{
    return m_type;
}

} // namespace Rubik