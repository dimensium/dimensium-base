#pragma once

#include "base/base.hpp"
#include <string>

namespace dimensium
{
    struct NamespaceIDString
    {
        std::string identifier_namespace;
        std::string identifier_name;
        
        NamespaceIDString(std::string id_namespace, std::string id_name) :
            identifier_namespace {id_namespace},
            identifier_name {id_name}
        { }

        operator std::string(void) const
        {return identifier_namespace + "::" + identifier_name;}

        std::string toString(void) const 
        {return *this;}
    };
}
