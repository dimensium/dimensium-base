#ifndef _UUID_HPP
#define _UUID_HPP


#include "base/base.hpp"
#include <ostream>

namespace dimensium 
{
    class UUID//8-4-4-4-12 hex
    {
        private:
            uint16 a[2], b, c, d, e[3];
        public:
            UUID(uint32 a, uint16 b, uint16 c, uint16 d, uint16 e_1, uint16 e_2, uint16 e_3)
                :   a{uint16(a >> 16), uint16(a << 16)},
                    b{b}, c{c}, d{d},
                    e{e_1, e_2, e_3}
            { }
            UUID(void) = default;
            UUID(UUID const&) = default;
            UUID &operator=(UUID const&) = default;

            static UUID random(void);
            

            friend std::ostream &operator<<(std::ostream &os, UUID const&);
    };
}


#endif // _UUID_HPP