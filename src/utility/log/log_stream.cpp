#include "log_stream.hpp"
#include <chrono>
#include <locale>
#include <mutex>
#include <sstream>
#include <stdexcept>

namespace dimensium 
{
    void LogStream::listen(void)
    {
        while(true)
        {
            if (exitFlagIsSet())
                break;
            // not "if" block!!
            {
                std::unique_lock lk {queue_mutex};
                if (!queue_cond.wait_for(
                    lk, std::chrono::milliseconds(100),
                    [this] {return !message_queue.empty();}))
                    continue;
                else
                {
                    LogMessage message = getMessageFromFrontOfQueue();
                    print(message);
                }
            }
        }
    }


    bool LogStream::exitFlagIsSet(void)
    {
        std::lock_guard lk {exit_flag_mutex};
        return thread_exit_flag;
    }

    void LogStream::print(LogMessage m) const 
    {
        stream 
            << "[" << getTimeString() << "]"
            << " " << std::setw(10) <<
                (
                    m.type == LogMessage::Type::status?         "STATUS":
                    m.type == LogMessage::Type::warning?        "WARNING":
                    m.type == LogMessage::Type::error?          "ERROR":
                    m.type == LogMessage::Type::fatal_error?    "FATAL ERROR":"NULL"
                )
            << " " << "from thread " << m.sender_thread_id << " :"
            << m.message;
    }

    LogMessage LogStream::getMessageFromFrontOfQueue(void) 
    {
        std::lock_guard lk {queue_mutex};
        LogMessage m {message_queue.front()};
        message_queue.pop();

        return m;
    }

    std::string LogStream::getTimeString(void) const 
    {
        auto time_point = std::chrono::system_clock::now();
        auto c_time = std::chrono::system_clock::to_time_t(time_point);
        
        // following statement may cause warning or error in Visual Studio and other compiler.
        // TODO: use compiler-specific functions when building.
        std::tm *time_struct = std::localtime(&c_time);

        std::ostringstream oss;
        oss << std::put_time(time_struct, "%H:%M:%S");
        // following statement disables RVO because we're concerned about some stupid compilers:)
        return std::move(oss.str());
    }




    // public functions

    void LogStream::push(LogMessage const&message)
    {
        {
            std::lock_guard lk {exit_flag_mutex};
            if (thread_exit_flag)
                throw InvalidArgument("message-listening thread had already stopped");
        }
        std::lock_guard lk{queue_mutex};
        message_queue.push(message);
    }

    void LogStream::stop(void)
    {
        std::lock_guard lk{exit_flag_mutex};
        if (thread_exit_flag)
            throw InvalidArgument("message-listening thread had already stopped");
    }
}