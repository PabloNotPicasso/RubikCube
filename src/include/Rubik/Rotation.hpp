#pragma once

namespace Rubik {

enum class Rotation {
    Final = 0,
    Start,
    F,
    Fr,
    L,
    Lr,
    R,
    Rr,
    B,
    Br,
    U,
    Ur,
    D,
    Dr,
};

const std::vector<Rotation> RotationList{
    Rotation::F,
    Rotation::Fr,
    Rotation::L,
    Rotation::Lr,
    Rotation::R,
    Rotation::Rr,
    Rotation::B,
    Rotation::Br,
    Rotation::U,
    Rotation::Ur,
    Rotation::D,
    Rotation::Dr};

const std::unordered_map<Rotation, Rotation> ReverseRotationMap{
    {Rotation::F, Rotation::Fr},
    {Rotation::L, Rotation::Lr},
    {Rotation::R, Rotation::Rr},
    {Rotation::B, Rotation::Br},
    {Rotation::U, Rotation::Ur},
    {Rotation::D, Rotation::Dr},

    {Rotation::Fr, Rotation::F},
    {Rotation::Lr, Rotation::L},
    {Rotation::Rr, Rotation::R},
    {Rotation::Br, Rotation::B},
    {Rotation::Ur, Rotation::U},
    {Rotation::Dr, Rotation::D},
};

} // namespace Rubik