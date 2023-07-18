#ifndef _DEFINITIONS_HPP
#define _DEFINITIONS_HPP

#include <cstdint>
#include "../precompile.hpp"
#include <string>

#include "libIntent/intent.hpp"

#include "utility/allocation/allocator.hpp"

namespace freecraft
{
    using namespace intent;
    using String = std::basic_string<char16_t, std::char_traits<char16_t>, allocation::JEAllocator<char16_t>>;
}

namespace freecraft::argument
{}
namespace freecraft::concurrency
{}
namespace freecraft::allocation
{}

#endif // _DEFINITIONS_HPP