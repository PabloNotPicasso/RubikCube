#include "Rubik/Color.hpp"

namespace Rubik {

static const std::unordered_map<Color::type, std::string> fullColorName{
    {Color::NA, "NA"},
    {Color::White, "White"},
    {Color::Red, "Red"},
    {Color::Blue, "Blue"},
    {Color::Orange, "Orange"},
    {Color::Green, "Green"},
    {Color::Yellow, "Yellow"},
};

static const std::unordered_map<Color::type, std::string> colorName{
    {Color::NA, "N"},
    {Color::White, "W"},
    {Color::Red, "R"},
    {Color::Blue, "B"},
    {Color::Orange, "O"},
    {Color::Green, "G"},
    {Color::Yellow, "Y"},
};

std::string Color::getName(const Color::type& color)
{
    return colorName.at(color);
}

Color::Color(const type& color)
    : m_color(color)
{
}

Color::operator type()
{
    return m_color;
}

} // namespace Rubik