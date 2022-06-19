#pragma once

#include <string>
#include <unordered_map>

enum class Color {
    NA = 0,
    White,
    Red,
    Blue,
    Orange,
    Green,
    Yellow,
};

std::string getName(const Color&);