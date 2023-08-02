#ifndef _BLOCK_HPP
#define _BLOCK_HPP

#include "base/base.hpp"

namespace dimensium 
{   
    class Block
    {
        public:
            using ID = uint32;
            using NamespaceID = uint32;
        private:
            ID id;
            NamespaceID namespace_id;
        public:
            Block(ID, NamespaceID);
            ~Block(void);
    };

}



#endif // _BLOCK_HPP