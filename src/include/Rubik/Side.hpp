#pragma once

#include <string>
#include <unordered_map>

namespace Rubik {

class Side {
public:
    enum type {
        NA = 0,
        F,
        L,
        R,
        B,
        U,
        D,
    };
    static std::string getName(const Side&);

    Side(const type& side);
    operator type() const;

private:
    type m_type;
};

} // namespace Rubik

// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<Rubik::Side> {
    std::size_t operator()(Rubik::Side const& side) const noexcept
    {
        return std::hash<Rubik::Side::type>{}(Rubik::Side::type(side));
    }
};