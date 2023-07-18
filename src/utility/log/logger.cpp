#include "logger.hpp"
#include <thread>

namespace freecraft 
{
    Logger &Logger::operator<<(std::string str)
    {
        LogMessage m 
            {
                .from = std::this_thread::get_id(),
                .message = str,
                .type = type
            };
        internal_queue.addLogMessage(m);
        return *this;
    }
}