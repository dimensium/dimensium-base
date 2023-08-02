#pragma once

#include <string>
#include <exception>
#include <source_location>

namespace dimensium
{
    class Exception
    {
        private:
            std::string exception_detail;
            std::source_location occurence_location;
        public:
            Exception(std::string why, std::source_location loc = std::source_location::current()) :
                exception_detail {why},
                occurence_location {loc}
            { }

            virtual std::string detail(void) const final;

            
            virtual std::source_location location(void) const final;
    };
    extern std::ostream &operator<<(std::ostream &os, Exception e);
}

