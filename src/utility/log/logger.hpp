#ifndef _LOGGER_HPP
#define _LOGGER_HPP

#include "log_queue.hpp"

namespace dimensium 
{

    class Logger
    {
        private:
            static LogQueue internal_queue;
            LogMessageType type = LogMessageType::info;
        public:
            Logger(LogMessageType type) : type(type)
            { }
            Logger &operator<<(std::string);

    };

}

#endif // _LOGGER_HPP