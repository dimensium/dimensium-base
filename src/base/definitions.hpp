#ifndef _DEFINITIONS_HPP
#define _DEFINITIONS_HPP

#include <cstdint>
#include "../precompile.hpp"
#include <string>

#include "libIntent/intent.hpp"

#include "utility/allocation/allocator.hpp"

namespace dimensium
{
    using namespace intent;
    using String = std::basic_string<char16_t, std::char_traits<char16_t>, allocation::JEAllocator<char16_t>>;
}

namespace dimensium::argument
{}
namespace dimensium::concurrency
{}
namespace dimensium::allocation
{}

#endif // _DEFINITIONS_HPP