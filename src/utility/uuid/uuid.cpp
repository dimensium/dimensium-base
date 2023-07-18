
#include "uuid.hpp"
#include <ostream>
#include <random>

namespace dimensium 
{
    std::ostream &operator<<(std::ostream &os, UUID const&uuid)
    {
        return os   << std::hex << uuid.a[0] << std::hex << uuid.a[1]
                    << "-" << std::hex << uuid.b
                    << "-" << std::hex << uuid.c
                    << "-" << std::hex << uuid.d
                    << "-" << std::hex << uuid.e[0] << std::hex << uuid.e[1] << std::hex << uuid.e[2]; 
    }
    

    UUID UUID::random(void)
    {
        UUID return_value;
        static thread_local std::minstd_rand eng(256);
        static thread_local std::uniform_int_distribution<> dis(0, 65535);
        for (auto &x : return_value.a)
            x = dis(eng);
        return_value.b = dis(eng);
        return_value.c = dis(eng);
        return_value.d = dis(eng);
        for (auto &x : return_value.e)
            x = dis(eng);
        return return_value;
    }
}