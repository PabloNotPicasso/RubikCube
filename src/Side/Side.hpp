#pragma once

#include <string>
#include <unordered_map>

enum class Side
{
    NA = 0,
    F,L,R,B,U,D,
};

std::string getName(const Side&);