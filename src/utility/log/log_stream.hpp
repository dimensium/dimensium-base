#pragma once

#include "base/base.hpp"
#include "log_message.hpp"

#include <condition_variable>
#include <iostream>
#include <queue>
#include <list>
#include <mutex>
#include <concepts>



namespace dimensium 
{
    class LogStream 
    {
        private:
            std::ostream &stream {std::cout};
            

            bool thread_exit_flag {false};
            std::mutex exit_flag_mutex;

            std::jthread thread_listen {&LogStream::listen};
            
            
            std::queue<LogMessage, std::list<LogMessage>> message_queue;
            std::mutex queue_mutex;
            std::condition_variable queue_cond;
            
        private:

            void listen(void);
            bool exitFlagIsSet(void);
            void print(LogMessage) const;
            LogMessage getMessageFromFrontOfQueue(void);
            std::string getTimeString(void) const;

        public:
            LogStream(std::ostream &os) :
                stream {os}
            { }

            LogStream(void) = default;

            LogStream(LogStream const&) = delete;
            LogStream &operator=(LogStream const&) = delete;


            void push(LogMessage const&);
            void stop(void);

            virtual ~LogStream(void) = default;
    };
}

