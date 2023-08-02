#pragma once

#include "base/base.hpp"
#include <thread>

namespace dimensium 
{
    struct LogMessage 
    {
        enum class Type : uint8;
        Type type;
        std::string message;
        std::thread::id sender_thread_id;
    };

    enum class LogMessage::Type : uint8 
    {
        status,
        warning,
        error,
        fatal_error,
    };
}