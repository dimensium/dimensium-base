#ifndef _ITEM_HPP
#define _ITEM_HPP


#include "base/base.hpp"
#include <memory>

namespace dimensium 
{
    class Item
    {
        public:
            using ID = uint32;
            using Count = uint16;
            using Damage = uint16;
            using Speed = float;


        public:
            Item(void);



        private:
            ID id;
            Count count;
            std::string description;
            struct Attribute
            {
                Speed attack_speed;
                Damage damage_point;
            };
    };
}


#endif // _ITEM_HPP