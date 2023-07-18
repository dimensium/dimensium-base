#include "log_queue.hpp"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <functional>
#include <mutex>
#include <queue>
#include <iostream>

namespace freecraft 
{

    inline char const*toTypeString(LogMessageType type)
    {
        return type == LogMessageType::info?
            "INFO       " : type == LogMessageType::warning?
            "WARNING    " : type == LogMessageType::error?
            "ERROR      " : type == LogMessageType::fatal_error?
            "FATAL-ERROR" : "UNKNOWN    ";
    }



    void LogQueue::listen(void)
    {
        while(true)
        {
            std::unique_lock<std::mutex> lk(internal_mutex);
            cond.wait(lk,[this]{return !messages.empty();});
            LogMessage message = messages.front();
            messages.pop();
            lk.unlock();

            print(message);

            {
                std::lock_guard<std::mutex> lk(ended_mutex);
                if (ended)
                    break;
            }
        }
    }


    
    void LogQueue::end(void)
    {
        std::lock_guard<std::mutex> lk(ended_mutex);
        ended = true;
    }


    inline std::string processNewLine(std::string str)
    {
        std::string return_value;
        Index i = 0;
        for (auto x : str)
            if (x == '\n')
                return_value += "\n\t";
            else
                return_value += x;
        return return_value;
    }//TODO: add a check



    void LogQueue::print(LogMessage message)
    {
        auto time_stamp = std::chrono::system_clock::now();
        auto c_time_stamp = std::chrono::system_clock::to_time_t(time_stamp);
        char buf[32];
        std::strftime(buf, 32, "%H%M%S", std::localtime(&c_time_stamp));
        
        output_stream << buf << " [" << toTypeString(message.type) << "]\t:" << processNewLine(message.message) << std::endl;
    }


    LogQueue::LogQueue(void) : LogQueue(std::cout)
    { }



    LogQueue::LogQueue(std::ostream &os) : output_stream(os)
    {
        internal_thread = std::thread(&LogQueue::listen, this);
    }


    void LogQueue::addLogMessage(LogMessage message)
    {
        {
            std::lock_guard<std::mutex> lk(internal_mutex);
            messages.push(message);
        }
        cond.notify_one();
    }


    LogQueue::~LogQueue(void)
    {
        {
            std::lock_guard<std::mutex> lk(ended_mutex);
            if (ended)
                end();
        }

        if (internal_thread.joinable())
            internal_thread.join();
    }
}