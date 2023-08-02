#pragma once

#include "exceptions.hpp"
#include <source_location>

namespace dimensium 
{
    class LogicError : public Exception
    {
        public:
            LogicError(std::string why, std::source_location loc = std::source_location::current()) :
                Exception {why, loc}
            { }
    };

    class DomainError : public LogicError
    {
        public:
            DomainError(std::string why, std::source_location loc = std::source_location::current()) :
                LogicError {why, loc}
            { }
    };

    class LengthError : public LogicError
    {
        public:
            LengthError(std::string why, std::source_location loc = std::source_location::current()) :
                LogicError {why, loc}
            { }
    };

    class InvalidArgument : public LogicError
    {
        public:
            InvalidArgument(std::string why, std::source_location loc = std::source_location::current()) :
                LogicError {why, loc}
            { }
    };

    class OutOfRange : public LogicError
    {
        public:
            OutOfRange(std::string why, std::source_location loc = std::source_location::current()) :
                LogicError {why, loc}
            { }
    };




    class RuntimeError : public Exception
    {
        public:
            RuntimeError(std::string why, std::source_location loc = std::source_location::current()) :
                Exception {why, loc}
            { }
    };

    class RangeError : public RuntimeError
    {
        public:
            RangeError(std::string why, std::source_location loc = std::source_location::current()) :
                RuntimeError {why, loc}
            { }
    };

    class OverflowError : public RuntimeError
    {
        public:
            OverflowError(std::string why, std::source_location loc = std::source_location::current()) :
                RuntimeError {why, loc}
            { }
    };

    class UnderflowError : public RuntimeError
    {
        public:
            UnderflowError(std::string why, std::source_location loc = std::source_location::current()) :
                RuntimeError {why, loc}
            { }
    };

    
}