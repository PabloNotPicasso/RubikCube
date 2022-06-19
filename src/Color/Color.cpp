#include "Color.hpp"

static const std::unordered_map<Color, std::string> fullColorName{
    {Color::NA, "NA"},
    {Color::White, "White"},
    {Color::Red, "Red"},
    {Color::Blue, "Blue"},
    {Color::Orange, "Orange"},
    {Color::Green, "Green"},
    {Color::Yellow, "Yellow"},
};

static const std::unordered_map<Color, std::string> colorName{
    {Color::NA, "N"},
    {Color::White, "W"},
    {Color::Red, "R"},
    {Color::Blue, "B"},
    {Color::Orange, "O"},
    {Color::Green, "G"},
    {Color::Yellow, "Y"},
};

std::string getName(const Color& color)
{
    return colorName.at(color);
}