#ifndef _BASE_EXCEPTIONS_HPP
#define _BASE_EXCEPTIONS_HPP

#include "base/definitions.hpp"
#include <exception>

namespace freecraft::exceptions
{
    class ExceptionBase : public std::exception
    {
    private:
        char const*why_;
        uint32 error_code_;
    public:
        ExceptionBase(char const*why = "uncaught exception occured", uint32 error_code = 0) : why_(why), error_code_(error_code)
        { }
        char const*what(void) const noexcept
        { return why_; }
        uint32 error_code(void) const noexcept 
        { return error_code_; }
    };

    class RuntimeException : public ExceptionBase
    {
    public:
        RuntimeException(char const*why = "uncaught exception in runtime occured", uint32 error_code = 0) : ExceptionBase(why, error_code)
        { }
    };

    class RuntimeError : public ExceptionBase
    {
    public:
        RuntimeError(char const*why = "uncaught error in runtime occured", uint32 error_code = 0) : ExceptionBase(why, error_code)
        { }
    };

    class RuntimeFatal : public ExceptionBase
    {
    public:
        RuntimeFatal(char const*why = "uncaught error in runtime occured", uint32 error_code = 0) : ExceptionBase(why, error_code)
        { }
    };



    class MemoryAllocationError : public RuntimeError
    {
        public:
            MemoryAllocationError(char const*why_ = "memory allocation error in runtime", uint32 error_code_ = 0) : RuntimeError(why_, error_code_)
            { }
    };
}

#endif // _BASE_EXCEPTIONS_HPP