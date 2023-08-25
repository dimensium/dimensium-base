#pragma once

#include "base/base.hpp"
#include <optional>

namespace dimensium 
{


    class Block 
    {
        private:
            uint32 world_id;
        public:
            Block(uint32 world_id) :
                world_id {world_id}
            { }

            ~Block(void)
            {}
    };
}