#include "exceptions.hpp"
#include <format>
#include <source_location>

namespace dimensium 
{
    std::string Exception::detail() const 
    {
        return exception_detail;
    }

    std::ostream &operator<<(std::ostream &stream, Exception e)
    {
        return 
            stream << std::format("file {}:{}:{} at function \"{}\": {}",
                e.location().file_name(),
                e.location().line(),
                e.location().column(),
                e.location().function_name(),
                e.detail());
    }

    std::source_location Exception::location() const 
    {
        return occurence_location;
    }
}