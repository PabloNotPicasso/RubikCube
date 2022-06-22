#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Rubik {

class Side {
public:
    enum Type {
        NA = 0,
        F,
        L,
        R,
        B,
        U,
        D,
    };

    Side(const Type& side);

    const Type& type() const;
    operator Type() const;

    static std::string getName(const Side&);
    static const std::vector<Side> SideList;

private:
    Type m_type;
};

} // namespace Rubik

// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Rubik::Side> {
    std::size_t operator()(Rubik::Side const& side) const noexcept
    {
        return std::hash<Rubik::Side::Type>{}(Rubik::Side::Type(side));
    }
};