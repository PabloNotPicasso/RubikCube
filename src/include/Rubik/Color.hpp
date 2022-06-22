#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Rubik {

class Color {
public:
    enum Type {
        NA = 0,
        White,
        Red,
        Blue,
        Orange,
        Green,
        Yellow,
    };

    Color(const Type& color = Type::NA);

    const Type& type() const;
    operator Type() const;

    static std::string getName(const Color&);
    static const std::vector<Color> ColorList;

private:
    Type m_color;
};

} // namespace Rubik

// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Rubik::Color> {
    std::size_t operator()(const Rubik::Color& color) const noexcept
    {
        return std::hash<Rubik::Color::Type>{}(Rubik::Color::Type(color));
    }
};