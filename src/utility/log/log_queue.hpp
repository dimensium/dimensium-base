#ifndef _LOG_QUEUE_HPP
#define _LOG_QUEUE_HPP

#include "base/definitions.hpp"
#include "utility/allocation/allocator.hpp"
#include <condition_variable>
#include <mutex>
#include <ostream>
#include <queue>
#include <string>


namespace freecraft
{
    //fdcl
    enum class LogMessageType : uint16
    {
        info,
        warning,
        error,
        fatal_error,
    };
    struct LogMessage
    {
        std::thread::id from;
        std::string message;
        LogMessageType type;
    };



    class LogQueue
    {
        private:
            std::thread internal_thread;
            std::mutex internal_mutex;
            std::condition_variable cond;
            std::queue<LogMessage> messages;
            std::ostream &output_stream;
            bool ended = false;
            std::mutex ended_mutex;




            void listen(void);
            void print(LogMessage);
        public:
            LogQueue(std::ostream &);
            LogQueue(void);


            LogQueue(LogQueue const&) = delete;
            LogQueue &operator=(LogQueue const&) = delete;


            ~LogQueue(void);


            void addLogMessage(LogMessage);
            void end(void);
    };

} // namespace freecraft




#endif // _LOG_QUEUE_HPP