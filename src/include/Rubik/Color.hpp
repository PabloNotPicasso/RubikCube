#pragma once

#include <string>
#include <unordered_map>

namespace Rubik {

class Color {
public:
    enum type {
        NA = 0,
        White,
        Red,
        Blue,
        Orange,
        Green,
        Yellow,
    };

    Color(const type& color = type::NA);

    operator type();

    static std::string getName(const Color::type&);

private:
    type m_color;
};

} // namespace Rubik