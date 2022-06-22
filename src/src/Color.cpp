#include "Rubik/Color.hpp"

namespace Rubik {

static const std::unordered_map<Color::Type, std::string> fullColorName{
    {Color::NA, "NA"},
    {Color::White, "White"},
    {Color::Red, "Red"},
    {Color::Blue, "Blue"},
    {Color::Orange, "Orange"},
    {Color::Green, "Green"},
    {Color::Yellow, "Yellow"},
};

static const std::unordered_map<Color::Type, std::string> colorName{
    {Color::NA, "N"},
    {Color::White, "W"},
    {Color::Red, "R"},
    {Color::Blue, "B"},
    {Color::Orange, "O"},
    {Color::Green, "G"},
    {Color::Yellow, "Y"},
};

std::string Color::getName(const Color& color)
{
    return colorName.at(color);
}

Color::Color(const Type& color)
    : m_color(color)
{
}

const Color::Type& Color::type() const
{
    return m_color;
}

Color::operator Color::Type() const
{
    return m_color;
}

} // namespace Rubik